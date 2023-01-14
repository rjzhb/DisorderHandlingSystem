//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_K_SLACK_H
#define DISORDERHANDLINGSYSTEM_K_SLACK_H


#include <cstddef>
#include <queue>
#include <set>
#include "manager/buffer_size_manager.h"
#include "manager/statistics_manager.h"
#include "common/define.h"


class KSlack {
public:

    explicit KSlack(Stream *stream, BufferSizeManager *buffer_size_manager, StatisticsManager *statistics_manager,
                    Synchronizer *synchronizer);

    ~KSlack();

    auto disorder_handling() -> void;

    auto get_output() -> std::queue<Tuple>;

private:

    //输出区
    std::queue<Tuple> output_;

    //缓冲区大小,相当于论文的K值,注：缓冲区大小并不是指集合的大小，而是以时间为单位来度量的
    size_t buffer_size_{1};

    //当前时间(相当于论文的T值)
    int current_time_;

    //传输过来的流
    Stream *stream_;

    //缓冲区(用随时保持有序的红黑树)
    std::set<Tuple, TupleComparator> buffer_;

    //缓冲区管理器
    BufferSizeManager *buffer_size_manager_;

    //数据统计管理器
    StatisticsManager *statistics_manager_;

};


#endif //DISORDERHANDLINGSYSTEM_K_SLACK_H
