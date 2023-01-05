//
// Created by 86183 on 2023/1/4.
//

#include "kslack/k_slack.h"

//K-Slack算法对无序流进行处理
void KSlack::disorder_handling() {

    while (!stream_list_.empty()) {
        //先让缓冲区所有满足条件的tuple出队进入输出区
        while(!buffer_.empty()){
            Tuple tuple = *buffer_.begin();
            if(tuple.ts + buffer_size_ <=
        }
    }
}
