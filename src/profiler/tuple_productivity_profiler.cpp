//
// Created by 86183 on 2023/1/9.
//

#include "profiler/tuple_productivity_profiler.h"
#include "common/define.h"

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
    if (join_result_map_.empty() || cross_join_map_.empty()) {
        return 1;

    }
    int M_sum = 0;
    int Mx_sum = 0;
    for (int d = 0; d <= K; d++) {
        M_sum += join_result_map_[d];
        Mx_sum += cross_join_map_[d];
    }
    int M_DM_sum = 0;
    int Mx_DM_sum = 0;
    for (int d = 0; d <= join_result_map_.end()->first; d++) {
        Mx_DM_sum += cross_join_map_[d];
        M_DM_sum += join_result_map_[d];
    }
    double res = (M_sum * 1.0 / Mx_sum) * (Mx_DM_sum * 1.0 / M_DM_sum);
    return res;
}

auto TupleProductivityProfiler::get_requirement_recall() -> double {
    int max_D = cross_join_map_.end()->first;
    int N_true_L = 0;
    for (int d = 0; d <= max_D; d++) {
        N_true_L += join_result_map_[d];
    }

    int N_true_P_L = 0;
    for (int d = max_D * (1 - (P - L) / L); d <= max_D; d++) {
        N_true_P_L += join_result_map_[d];
    }

    int N_prod_P_L = 0;
    for (int d = max_D * (1 - (P - L) / L); d <= max_D; d++) {
        N_prod_P_L += join_result_map_[d];
    }

    //requirement_recall大于等于这个值
    double requirement_recall = (userRecall * (N_true_P_L + N_true_L) - N_prod_P_L) * 1.0 / N_true_L;
    return requirement_recall;
}
