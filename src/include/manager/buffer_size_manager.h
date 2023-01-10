//
// Created by 86183 on 2023/1/5.
//

#ifndef DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H
#define DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H


#include "statistics_manager.h"

class BufferSizeManager {
public:

    //自适应K值算法
    auto k_search(int stream_id) -> int;

    //论文中的函数γ(L,T)
    auto y(int stream_id, int K) -> double;


private:

    //数据统计器
    StatisticsManager *statistics_manager_;

    //元组生产力
    TupleProductivityProfiler *productivity_profiler_;

};


#endif //DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H
