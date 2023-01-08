//
// Created by 86183 on 2023/1/4.
//

#include "kslack/k_slack.h"

//K-Slack算法对无序流进行处理
void KSlack::disorder_handling() {
    std::queue<Tuple> output_list_;
    while (!stream_->get_tuple_list().empty()) {
        Tuple tuple = stream_->get_tuple_list().front();
        //更新local time
        current_time_ = std::max(current_time_, tuple.ts);
        //计算出tuple的delay,T - ts, 方便统计管理器统计记录
        tuple.delay = current_time_ - tuple.ts;
        //加入statistics_manager的历史记录统计表
        statistics_manager_->add_record(stream_->get_id(), tuple);
        //TODO: 用BufferManager动态更新buffer_size_(论文中的K), 把事情交给BufferManager

        //先让缓冲区所有满足条件的tuple出队进入输出区
        while (!buffer_.empty()) {
            Tuple tuple = *buffer_.begin();

            //对应论文的公式：ei. ts + Ki <= T
            if (tuple.ts + buffer_size_ > current_time_) {
                break;
            }
            //满足上述公式，加入输出区
            output_list_.push(tuple);
            buffer_.erase(buffer_.begin());
        }
        stream_->get_tuple_list().pop();
        //加入tuple进入buffer
        buffer_.insert(tuple);
    }
}
