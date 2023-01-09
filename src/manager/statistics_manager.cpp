//
// Created by 86183 on 2023/1/6.
//

#include <map>
#include "manager/statistics_manager.h"

void StatisticsManager::add_record(int stream_id, Tuple tuple) {
    record_map_[stream_id].push_back(tuple);
}

void StatisticsManager::add_record(int stream_id, int T, int K) {
    T_map_[stream_id] = T;
    K_map_[stream_id] = K;
}


//获得离散随机变量Di的值,如果delay(ei) ∈(kg,(k+1)g]，则Di=k+1
int StatisticsManager::get_D(int delay) {
    return delay % g == 0 ? delay / g : delay / g + 1;
}

//获取Ksync的值，Ksync = iT - ki - min{iT - ki| i∈[1,m]}
auto StatisticsManager::get_ksync(int stream_id) -> int {
    int min_iT_ki = T_map_[stream_id] - K_map_[stream_id];
    for (auto it: record_map_) {
        min_iT_ki = std::min(min_iT_ki, T_map_[it.first] - K_map_[it.first]);
    }
    return T_map_[stream_id] - K_map_[stream_id] - min_iT_ki;
}

//概率分布函数fD
auto StatisticsManager::fD(int d, int stream_id) -> double {
    int R_stat = get_R_stat(stream_id);

    if (record_map_.find(stream_id) == record_map_.end()) {
        return -1;
    }

    std::vector<Tuple> record = record_map_[stream_id];

    //取出record里面R_stat大小范围的数据
    std::map<int, int> rate_map;
    for (int i = record.size() - 1; i >= record.size() - R_stat; i--) {
        int Di = get_D(record[i].delay);
        rate_map[Di] = rate_map.find(Di) == rate_map.end() ? 0 : rate_map[Di] + 1;
    }
    //用直方图模拟
    if (histogram_map_.find(stream_id) == histogram_map_.end()) {
        histogram_map_[stream_id].reserve(MAX_DELAY);
    }

    for (auto it: rate_map) {
        histogram_map_[stream_id][it.first] = it.second * 1.0 / R_stat;
    }

    //折线插值估计 , 双指针中心扩散法
    int hi_size = histogram_map_[stream_id].size();
    int left = d - 1, right = d + 1;
    while (left >= 0 && right < hi_size) {
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
            if (histogram_map_[stream_id][left] == 0) {
                left--;
            }
            if (histogram_map_[stream_id][right] == 0) {
                right--;
            }
        }
    }

    double p_l = histogram_map_[stream_id][left];
    double p_r = histogram_map_[stream_id][right];
    //此时left和right分别指向了有实际数据的点，可用折线估计概率
    //直线方程： y =  (p_r - p_l)/(right - left)(x - left) + p_l
    double p_d = (p_r - p_l) / (right - left) * (d - left) + p_l;
    //更新直方图
    histogram_map_[stream_id][d] = p_d;
    return p_d;
}



