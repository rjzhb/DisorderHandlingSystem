//
// Created by 86183 on 2023/1/6.
//

#ifndef DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
#define DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H


#include <vector>
#include <unordered_map>
#include <mutex>
#include "profiler/tuple_productivity_profiler.h"
#include "common/define.h"
#include <parallel-hashmap/parallel_hashmap/phmap.h>

class StatisticsManager {
public:

    explicit StatisticsManager(TupleProductivityProfiler *profiler);

    ~StatisticsManager() = default;

    //获得元组最大delay
    auto get_maxD(int stream_id) -> int;

    //离散随机变量Dik的概率分布函数fDiK， Dik表示连接算子在k设置下接受相应流中一个元组的粗粒度延迟
    auto fDk(int d, int stream_id, int K) -> double;

    //|wi^l|的估计
    auto wil(int l, int stream_id, int K) -> int;

    auto add_record(int stream_id, Tuple tuple) -> void;

    auto add_record(int stream_id, int T, int K) -> void;


private:
    //获得Ksync
    auto get_ksync(int stream_id) -> int;

    //获取avg(ksync)
    auto get_avg_ksync(int stream_id) -> int;

    //估计未来的ksync
    auto get_future_ksync(int stream_id) -> int;

    //参考文献[25]的自适应窗口方法, 传入的主要参数待定，需阅读文献[25]
    auto get_R_stat(int stream_id) -> int;

    //离散随机变量Di的概率分布函数fDi
    auto fD(int d, int stream_id) -> double;

    //互斥锁
    std::mutex latch_;

    //锁TupleProductivity的互斥锁，否则调用时会和其他线程冲突
    std::mutex profiler_latch_;

    //锁get_D
    std::mutex d_latch_;

    //Rstat窗口大小
    phmap::parallel_flat_hash_map<int, int> R_stat_map_{};

    //历史流Si输入记录的映射
    phmap::parallel_flat_hash_map<int, std::vector<Tuple>> record_map_{};

    //历史流Si的T记录
    phmap::parallel_flat_hash_map<int, int> T_map_{};

    //历史流的K记录
    phmap::parallel_flat_hash_map<int, int> K_map_{};

    //保存所有的K_sync，方便抽取样本预测未来的ksync
    phmap::parallel_flat_hash_map<int, std::vector<int>> ksync_map_{};

    //直方图映射
    phmap::parallel_flat_hash_map<int, std::vector<double>> histogram_map_{};

    //元组生产力
    TupleProductivityProfiler *productivity_profiler_;
};


#endif //DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
