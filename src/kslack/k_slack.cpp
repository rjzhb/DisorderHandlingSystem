//
// Created by 86183 on 2023/1/4.
//

#include "kslack/k_slack.h"

//K-Slack算法对无序流进行处理
void KSlack::disorder_handling() {

    while (!stream_list_.empty()) {
        //先让缓冲区所有满足条件的tuple出队进入输出区
        while (!buffer_.empty()) {
            Tuple tuple = *buffer_.begin();

            //TODO: 用BufferManager动态更新buffer_size_(论文中的K), 把事情交给BufferManager

            //对应论文的公式：ei. ts + Ki <= T
            if (tuple.ts + buffer_size_ > current_time_) {
                break;
            }
            //满足上述公式，加入输出区
            output_list_.push(tuple);
            buffer_.erase(buffer_.begin());
        }

        Tuple tuple = stream_list_.front();
        stream_list_.pop();
        //加入tuple进入buffer
        buffer_.insert(tuple);
    }
}
