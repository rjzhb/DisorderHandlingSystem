//
// Created by 86183 on 2023/1/6.
//

#include <map>
#include <list>
#include <complex>
#include <iostream>
#include "manager/statistics_manager.h"

StatisticsManager::StatisticsManager(TupleProductivityProfiler *profiler) {
    productivity_profiler_ = profiler;
}


auto StatisticsManager::add_record(int stream_id, Tuple tuple) -> void {
    record_map_[stream_id].push_back(tuple);
}

auto StatisticsManager::add_record(int stream_id, int T, int K) -> void {
    T_map_[stream_id] = T;
    K_map_[stream_id] = K;
    ksync_map_[stream_id].push_back(get_ksync(stream_id));
}


auto StatisticsManager::get_maxD(int stream_id) -> int {
//    std::lock_guard<std::mutex> lock(latch_);
    int max_D = 0;

    if (record_map_.find(stream_id) == record_map_.end()) {
        return max_D;
    }

    for (auto it: record_map_[stream_id]) {
        max_D = std::max(max_D, it.delay);
    }
    return max_D;
}


auto StatisticsManager::get_R_stat(int stream_id) -> int {
    std::vector<Tuple> record = record_map_[stream_id];
    if (record.empty()) {
        return 1;
    }

    //当前Rstat大小
    int R_stat = 2;
    if (R_stat_map_.find(stream_id) != R_stat_map_.end()) {
        R_stat = R_stat_map_[stream_id];
    }

    //窗口
    std::list<int> window1_list;
    std::list<int> window0_list;

    //维护sum变量,方便取平均值
    int sum_w0 = 0;
    int sum_w1 = 0;

    //取出record里面当前R_stat大小范围的数据,并计算频率，用频率估计概率
    for (int i = record.size() - 1; i >= std::max((int) record.size() - R_stat, 0); i--) {
        int xi = get_D(record[i].delay);
        window1_list.push_back(xi);
        sum_w1 += xi;
    }

    double e_cut = 0;
    while (window1_list.size() > 1) {
        //将窗口分为w0,w1两部分
        int w1_front = window1_list.front();
        window0_list.push_back(w1_front);
        window1_list.pop_front();
        sum_w1 -= w1_front;
        sum_w0 += w1_front;

        //更新e_cut
        double m = 1 / (1 / window0_list.size() + 1 / window1_list.size());
        double confidence_value = confidenceValue / (window1_list.size() + window0_list.size());
        e_cut = std::sqrt((1 / 2 * m) * std::log1p(4 / confidence_value));

        if (std::abs(sum_w1 * 1.0 / window1_list.size() - sum_w0 * 1.0 / window0_list.size()) >= e_cut) {
            R_stat_map_[stream_id] = window1_list.size();
            break;
        }
    }

    return window1_list.size();
}


//获取Ksync的值，Ksync = iT - ki - min{iT - ki| i∈[1,latch_]}
auto StatisticsManager::get_ksync(int stream_id) -> int {
    if (T_map_.find(stream_id) == T_map_.end()
        || K_map_.find(stream_id) == K_map_.end()
        || record_map_.empty()) {
        return 1;
    }

    int min_iT_ki = T_map_[stream_id] - K_map_[stream_id];

    for (auto it: record_map_) {
        min_iT_ki = std::min(min_iT_ki, T_map_[it.first] - K_map_[it.first]);
    }
    return T_map_[stream_id] - K_map_[stream_id] - min_iT_ki;
}


//获取平均值，目的是为了预测未来的k_sync
auto StatisticsManager::get_avg_ksync(int stream_id) -> int {
    int sum_ksync_i = 0;
    int R_stat = get_R_stat(stream_id);
    std::vector<int> ksync_list = ksync_map_[stream_id];
    if (ksync_list.empty()) {
        return 1;
    }

    //找出R_stat范围内的ksync_i的总和，再取平均值
    for (int i = ksync_list.size() - 1; i >= std::max((int) ksync_list.size() - R_stat, 0); i--) {
        sum_ksync_i += ksync_map_[stream_id][i];
    }
    int avg_ksync_i = sum_ksync_i / R_stat;

    return avg_ksync_i == 0 ? 1 : avg_ksync_i;
}

//公式见论文page 7
auto StatisticsManager::get_future_ksync(int stream_id) -> int {
    int avg_ksync_i = get_avg_ksync(stream_id);
    int min_ksync = INT32_MAX;

    //找到j != i的所有avg_ksync的最小值
    for (auto it: ksync_map_) {
        if (it.first == stream_id) {
            continue;
        }
        min_ksync = std::min(min_ksync, get_avg_ksync(it.first));
    }

    if (min_ksync == INT32_MAX) {
        min_ksync = 0;
    }
    return avg_ksync_i - min_ksync;
}


//概率分布函数fD
auto StatisticsManager::fD(int d, int stream_id) -> double {
    int R_stat = get_R_stat(stream_id);

    if (record_map_.find(stream_id) == record_map_.end()) {
        return -1;
    }

    std::vector<Tuple> record = record_map_[stream_id];
    if (record.empty()) {
        return 1;
    }

    //取出record里面R_stat大小范围的数据,并计算频率，用频率估计概率
    std::map<int, int> rate_map;
    for (int i = record.size() - 1; i >= std::max((int) record.size() - R_stat, 0); i--) {
        int Di = get_D(record[i].delay);
        rate_map[Di] = rate_map.find(Di) == rate_map.end() ? 1 : rate_map[Di] + 1;
    }

    //用直方图模拟
    if (histogram_map_.find(stream_id) == histogram_map_.end()) {
        histogram_map_[stream_id].resize(maxDelay);
    }

    double sum_p = 0;
    for (auto it: rate_map) {
        if (histogram_map_[stream_id][it.first] != 0) {
            //原先的直方图已经统计过了该Di的概率，故取平均值
            histogram_map_[stream_id][it.first] = (histogram_map_[stream_id][it.first] + it.second * 1.0 / R_stat) / 2;
        } else {
            histogram_map_[stream_id][it.first] = it.second * 1.0 / R_stat;
        }
        sum_p += histogram_map_[stream_id][it.first];
    }

    //如果d已经有现成的概率，则直接返回即可
    if (histogram_map_[stream_id][d] != 0) {
        //前面可能更新过了直方图，返回前做一次归一化
        if (sum_p != 0) {
            for (auto &it: histogram_map_[stream_id]) {
                if (it != 0) {
                    it /= sum_p;
                }
            }
        }
        return histogram_map_[stream_id][d];
    }

    //如果d没有记录，则做折线插值估计 , 双指针中心扩散法
    int hi_size = histogram_map_[stream_id].size();
    int left = d - 1, right = d + 1;
    while (left >= 0 && right < hi_size) {
        if (histogram_map_[stream_id][left] != 0 && histogram_map_[stream_id][right] != 0) {
            break;
        }
        if (histogram_map_[stream_id][left] == 0) {
            left--;
        }
        if (histogram_map_[stream_id][right] == 0) {
            right++;
        }
    }

    if (left < 0) {
        left = d + 1, right = d + 2;
        while (right < hi_size) {
            if (histogram_map_[stream_id][left] != 0 && histogram_map_[stream_id][right] != 0) {
                break;
            }
            if (histogram_map_[stream_id][left] == 0) {
                left++;
            }
            if (histogram_map_[stream_id][right] == 0) {
                right++;
            }
        }
    } else if (right >= hi_size) {
        left = d - 2, right = d - 1;
        while (left >= 0) {
            if (histogram_map_[stream_id][left] != 0 && histogram_map_[stream_id][right] != 0) {
                break;
            }
            if (histogram_map_[stream_id][left] == 0) {
                left--;
            }
            if (histogram_map_[stream_id][right] == 0) {
                right--;
            }
        }
    }

    if (left == right) {
        histogram_map_[stream_id][left] /= 2;
        histogram_map_[stream_id][d] = histogram_map_[stream_id][left];
        return histogram_map_[stream_id][d];
    }

    double p_l = histogram_map_[stream_id][left];
    double p_r = histogram_map_[stream_id][right];

    //此时left和right分别指向了有实际数据的点，可用折线估计概率
    //直线方程： y =  (p_r - p_l)/(right - left)(x - left) + p_l
    double p_d = (p_r - p_l) / (right - left) * (d - left) + p_l;

    //更新直方图
    histogram_map_[stream_id][d] = p_d;

    //归一化
    sum_p += p_d;
    for (auto &it: histogram_map_[stream_id]) {
        if (it != 0) {
            it /= sum_p;
        }
    }

    return histogram_map_[stream_id][d];
}

auto StatisticsManager::fDk(int d, int stream_id, int K) -> double {
    int k_sync = get_future_ksync(stream_id);
    double res = 0;

    if (d == 0) {
        for (int i = 0; i <= (k_sync + K) / g; i++) {
            res += fD(i, stream_id);
        }
    } else {
        res = fD(d + (K + k_sync) / g, stream_id);
    }

    return res;
}

auto StatisticsManager::wil(int l, int stream_id, int K) -> int {
    int wi = stream_map[stream_id]->get_window_size();
    int ni = wi / b;
    int res = 0;
    double ri = productivity_profiler_->get_join_record_map()[stream_id] * 1.0 / wi;

    if (l <= ni - 1 && l >= 1) {
        for (int i = 0; i <= (l - 1) * b / g; i++) {
            res += fDk(i, stream_id, K);
        }
        res = static_cast<int>(ri * b * res);
    } else if (l == ni) {
        for (int i = 0; i <= (ni - 1) * b / g; i++) {
            res += fDk(i, stream_id, K);
        }
        res = static_cast<int>(ri * (wi - (ni - 1) * b) * res);
    }

    return res;
}



