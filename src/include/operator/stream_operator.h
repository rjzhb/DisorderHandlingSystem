//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
#define DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H


#include <queue>
#include <unordered_map>
#include "common/define.h"
#include "common/stream.h"
#include "manager/statistics_manager.h"

class StreamOperator {
public:

    auto mswj_execution(std::queue<Tuple> input) -> void;

    auto can_join_(Tuple t1, Tuple t2) -> bool;

    auto get_result() -> std::queue<Tuple>;

private:

    //连接时的T
    int T_op_;

    //window map
    std::unordered_map<int, std::queue<Tuple>> window_map_;

    //结果元组
    std::queue<Tuple> result_;

    //元组生产力监视器
    TupleProductivityProfiler *productivity_profiler_;
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
