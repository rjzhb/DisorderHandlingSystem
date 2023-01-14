//
// Created by 86183 on 2023/1/7.
//

#ifndef DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
#define DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H


#include <vector>
#include <queue>
#include <set>
#include <list>
#include "common/define.h"
#include "kslack/k_slack.h"


class Synchronizer {
public:
    explicit Synchronizer(std::list<KSlack *> kslack_list);

    ~Synchronizer() = default;

    //同步过程
    auto synchronize_stream(std::queue<Tuple> input_list) -> void;

private:
    //输入区
    std::queue<Tuple> input_{};

    //SyncBuf缓冲区映射
    std::unordered_map<int, std::set<Tuple, TupleComparator>> sync_buffer_map_{};

    //同步输出区
    std::queue<Tuple> output_{};

    //Tsync
    int T_sync_{};

    //stream的数量
    int stream_count_{};

    //当前缓冲区拥有tuple的流的数量
    int own_stream_{};
};


#endif //DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
