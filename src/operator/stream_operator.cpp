//
// Created by 86183 on 2023/1/8.
//

#include "operator/stream_operator.h"

void StreamOperator::mswj_execution(std::vector<Stream *> stream_list_) {
    for(int i = 0;i < stream_list_.size();i++){

    }
    while (!input_list.empty()) {
        Tuple tuple = input_list.front();
        input_list.pop();
        if (tuple.ts >= T_op_) {
            T_op_ = tuple.ts;

        } else {

        }
    }
}
