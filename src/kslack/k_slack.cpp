//
// Created by 86183 on 2023/1/4.
//

#include <iostream>
#include "kslack/k_slack.h"

KSlack::KSlack(Stream *stream, BufferSizeManager *buffer_size_manager, StatisticsManager *statistics_manager) {
    stream_ = stream;
    buffer_size_manager_ = buffer_size_manager;
    statistics_manager_ = statistics_manager;
}


KSlack::~KSlack() {
    delete stream_;
    delete buffer_size_manager_;
    delete statistics_manager_;
}


auto KSlack::get_output() -> std::queue<Tuple> {
    return output_;
}

//K-Slack算法对无序流进行处理
auto KSlack::disorder_handling() -> void {
    while (!stream_->get_tuple_list().empty()) {
        Tuple tuple = stream_->get_tuple_list().front();

        //更新local time
        current_time_ = std::max(current_time_, tuple.ts);

        //计算出tuple的delay,T - ts, 方便统计管理器统计记录
        tuple.delay = current_time_ - tuple.ts;

        //加入statistics_manager的历史记录统计表以及T值
        statistics_manager_->add_record(stream_->get_id(), tuple);
        statistics_manager_->add_record(stream_->get_id(), current_time_, buffer_size_);

        //先让缓冲区所有满足条件的tuple出队进入输出区
        while (!buffer_.empty()) {
            Tuple tuple = *buffer_.begin();

            //对应论文的公式：ei. ts + Ki <= T
            if (tuple.ts + buffer_size_ > current_time_) {
                break;
            }

            //满足上述公式，加入输出区
            output_.push(tuple);
            buffer_.erase(buffer_.begin());
        }
        stream_->pop_tuple();

        //加入tuple进入buffer
        buffer_.insert(tuple);

        //动态更新K值
        buffer_size_ = buffer_size_manager_->k_search(stream_->get_id());
    }

    //将buffer区剩下的元素加入output
    while (!buffer_.empty()) {
        output_.push(*buffer_.begin());
        buffer_.erase(buffer_.begin());
    }

    std::cout << "kslack作用后:" << std::endl;
    print(output_);
}
