//
// Created by 86183 on 2023/1/9.
//

#ifndef DISORDERHANDLINGSYSTEM_TUPLE_PRODUCTIVITY_PROFILER_H
#define DISORDERHANDLINGSYSTEM_TUPLE_PRODUCTIVITY_PROFILER_H


#include <unordered_map>

class TupleProductivityProfiler {
public:

    auto get_join_record_map() -> std::unordered_map<int, int>;

    auto add_join_record(int stream_id, int count) -> void;

    auto update_cross_join(int Di, int res) -> void;

    auto update_join_res(int Di, int res) -> void;

private:

    //到达join operator的元组数量记录
    std::unordered_map<int, int> join_record_map_;

    //the join operator records both the number of cross-join result size,
    std::unordered_map<int, int> cross_join_map_;

    //the number of join results,
    std::unordered_map<int, int> join_result_map_;
};


#endif //DISORDERHANDLINGSYSTEM_TUPLE_PRODUCTIVITY_PROFILER_H
