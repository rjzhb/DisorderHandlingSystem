//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
#define DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H


#include <queue>
#include <unordered_map>
#include "common/define.h"
#include "common/stream.h"

class StreamOperator {
public:

    void mswj_execution(std::queue<Tuple> input);

    bool can_join_(Tuple t1, Tuple t2);

private:
    //连接时的T
    int T_op_;
    //window map
    std::unordered_map<int, std::queue<Tuple>> window_map_;
    //结果元组
    std::queue<Tuple> result_;
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
