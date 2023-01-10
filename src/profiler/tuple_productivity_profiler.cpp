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

auto TupleProductivityProfiler::get_select_ratio(int K) -> double {
    int M_sum = 0;
    int Mx_sum = 0;
    for (int d = 0; d < K; d++) {
        M_sum += join_result_map_[d];
        Mx_sum += cross_join_map_[d];
    }
    int M_DM_sum = 0;
    int Mx_DM_sum = 0;
    for (int d = 0; d < join_result_map_.end()->first; d++) {
        Mx_DM_sum += cross_join_map_[d];
        M_DM_sum += join_result_map_[d];
    }
    double res = (M_sum * 1.0 / Mx_sum) * (Mx_DM_sum * 1.0 / M_DM_sum);
    return res;
}
