//
// Created by 86183 on 2023/1/6.
//

#ifndef DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
#define DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H


#include <vector>
#include <unordered_map>
#include "common/define.h"

class StatisticsManager {
public:

    //论文中的函数γ(L,T)
    auto y(int stream_id, int L, int T) -> double;

    //参考文献[25]的自适应窗口方法, 传入的主要参数待定，需阅读文献[25]
    auto get_R_stat(int stream_id) -> int;

    //离散随机变量Dik的概率密度函数fDiK， Dik表示连接算子在k设置下接受相应流中一个元组的粗粒度延迟
    auto fD(int d, int stream_id) -> double;

    void add_record(int stream_id, Tuple tuple);

    //获得离散随机变量Di的值
    int get_D(int delay);



private:
    //历史流Si输入记录的映射
    std::unordered_map<int, std::vector<Tuple>> record_map_;

    //直方图映射
    std::unordered_map<int, std::vector<int>> histogram_map_;

};


#endif //DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
