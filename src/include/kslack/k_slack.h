//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_K_SLACK_H
#define DISORDERHANDLINGSYSTEM_K_SLACK_H


#include <cstddef>
#include <queue>
#include <set>
#include "common/define.h"
#include "manager/buffer_size_manager.h"
#include "manager/statistics_manager.h"

class KSlack {
public:

    void disorder_handling();

private:
    //缓冲区大小,相当于论文的K值,注：缓冲区大小并不是指集合的大小，而是以时间为单位来度量的
    size_t buffer_size_{};
    //当前时间(相当于论文的T值)
    int current_time_;
    //流id，如论文中S1的id为1，S2的id为2
    int stream_id_{};
    //传输过来的流
    std::queue<Tuple> stream_list_;

    //缓冲区(用随时保持有序的红黑树)
    std::set<Tuple, TupleComparator> buffer_;

//    //输出区
//    std::queue<Tuple> output_list_;

    BufferSizeManager *buffer_size_manager_;
    StatisticsManager *statistics_manager_;
};


#endif //DISORDERHANDLINGSYSTEM_K_SLACK_H
