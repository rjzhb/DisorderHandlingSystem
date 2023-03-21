//
// Created by 86183 on 2023/1/4.
//

#include <iostream>
#include <future>
#include "kslack/k_slack.h"

KSlack::KSlack(Stream *stream, BufferSizeManager *buffer_size_manager, StatisticsManager *statistics_manager,
               Synchronizer *synchronizer) {
    stream_ = stream;
    buffer_size_manager_ = buffer_size_manager;
    statistics_manager_ = statistics_manager;
    synchronizer_ = synchronizer;
}


KSlack::~KSlack() {
    delete stream_;
    delete buffer_size_manager_;
    delete statistics_manager_;
    delete synchronizer_;
}


auto KSlack::get_output() -> std::queue<Tuple> {
    return watch_output_;
}

auto KSlack::get_id() -> int {
    return stream_->get_id();
}

//K-Slack算法对无序流进行处理
auto KSlack::disorder_handling() -> void {
    while (!stream_->get_tuple_list().empty()) {
        Tuple tuple = stream_->get_tuple_list().front();

        //更新local time
        current_time_ = std::max(current_time_, tuple.ts);

        //每L个时间单位调整K值
        if (current_time_ != 0 && current_time_ % L == 0) {
            buffer_size_ = buffer_size_manager_->k_search(stream_->get_id());
        }

        //计算出tuple的delay,T - ts, 方便统计管理器统计记录
        tuple.delay = current_time_ - tuple.ts;

        std::async(std::launch::async, [&] {
            //将output_加入同步器
            //加入statistics_manager的历史记录统计表以及T值
            statistics_manager_->add_record(stream_->get_id(), tuple);
            statistics_manager_->add_record(stream_->get_id(), current_time_, buffer_size_);
        }).get();

        //先让缓冲区所有满足条件的tuple出队进入输出区
        while (!buffer_.empty()) {
            Tuple tuple = *buffer_.begin();

            //对应论文的公式：ei. ts + Ki <= T
            if (tuple.ts + buffer_size_ > current_time_) {
                break;
            }

            //满足上述公式，加入输出区
            output_.push(tuple);
            watch_output_.push(tuple);
            buffer_.erase(buffer_.begin());
        }
        stream_->pop_tuple();

        //加入tuple进入buffer
        buffer_.insert(tuple);

        std::async(std::launch::async, [&] {
            //将output_加入同步器
            synchronizer_->synchronize_stream(output_);
        }).get();

    }

    //将buffer区剩下的元素加入output
    while (!buffer_.empty()) {
        output_.push(*buffer_.begin());
        watch_output_.push(*buffer_.begin());
        buffer_.erase(buffer_.begin());
    }

    std::async(std::launch::async, [&] {
        //将output_加入同步器
        synchronizer_->synchronize_stream(output_);
    }).get();

}


