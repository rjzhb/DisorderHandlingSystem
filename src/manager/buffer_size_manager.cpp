//
// Created by 86183 on 2023/1/5.
//

#include "manager/buffer_size_manager.h"

/**
 *
 * @param L  - buffer-size manager的自适应时间间隔
 * @param b basic window的size
 * @param g  K*搜索粒度
 * @return
 */
auto BufferSizeManager::k_search(int L, int b, int g) -> int {
    /**
     *     TODO:需要获得 current maximum tuple delay（MAXDH)
     *     TODO:需要获得instant recall requirement  Γ‘
     *     TODO:需要调用γ(L, K)
     */
    return 0;
}

auto BufferSizeManager::y(int stream_id, int L, int K) -> double {
    //SEL比值
    double sel_radio = productivity_profiler_->get_select_ratio(K);

    int wil = 0;
    int m = productivity_profiler_->get_join_record_map()[stream_id];

    //分子
    int numerator = 0;
    for (int i = 1; i <= m; i++) {
        int res = 1;
        for (int j = 1; j <= m && j != i; j++) {
            int wj = stream_map[j]->get_window_size();
            int nj = wj / b;
            int sum = 0;
            for (int l = 1; l <= nj; l++) {
                sum += statistics_manager_->wil(l, j, K);
            }
            res *= sum;
        }
        numerator += statistics_manager_->fDk(0, i, K) * res;
    }

    //分母
    int denominator = 0;
    for (int i = 1; i <= m; i++) {
        int res = 1;
        for (int j = 1; j <= m && j != i; j++) {
            res *= stream_map[j]->get_window_size();
        }
        denominator += res;
    }

    if (denominator == 0) {
        return -1;
    }

    return static_cast<int>(sel_radio * numerator / denominator);
}




