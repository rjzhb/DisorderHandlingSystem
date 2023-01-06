//
// Created by 86183 on 2023/1/6.
//

#ifndef DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
#define DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H


class StatisticsManager {
public:


    //参考文献[25]的自适应窗口方法, 传入的主要参数：
    auto get_R_stat(int streamId)-> int;
private:

};


#endif //DISORDERHANDLINGSYSTEM_STATISTICS_MANAGER_H
