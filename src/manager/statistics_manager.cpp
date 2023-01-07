//
// Created by 86183 on 2023/1/6.
//

#include <map>
#include "manager/statistics_manager.h"

void StatisticsManager::add_record(int stream_id, Tuple tuple) {
    record_map_[stream_id].push_back(tuple);
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
    int left = d - 1, right = d + 1;
    while (left >= 0 && right < histogram_map_[stream_id].size()) {
        if (histogram_map_[stream_id][left] == 0) {
            left--;
        }
        if (histogram_map_[stream_id][right] == 0) {
            right++;
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

//获得离散随机变量Di的值
int StatisticsManager::get_D(int delay) {
    return 0;
}

