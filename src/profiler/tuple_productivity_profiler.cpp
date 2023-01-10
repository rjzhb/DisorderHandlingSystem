//
// Created by 86183 on 2023/1/9.
//

#include "profiler/tuple_productivity_profiler.h"

auto TupleProductivityProfiler::get_join_record_map() -> std::unordered_map<int, int> {
    return join_record_map_;
}

auto TupleProductivityProfiler::add_join_record(int stream_id, int count) -> void {
    join_record_map_[stream_id] = count;
}

auto TupleProductivityProfiler::update_cross_join(int Di, int res) -> void {
    cross_join_map_[Di] = res;
}

auto TupleProductivityProfiler::update_join_res(int Di, int res) -> void {
    join_result_map_[Di] = res;
}
