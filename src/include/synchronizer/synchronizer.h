//
// Created by 86183 on 2023/1/7.
//

#ifndef DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
#define DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H


#include <vector>
#include <queue>
#include <set>
#include <list>
#include <mutex>
#include "common/define.h"
#include "operator/stream_operator.h"


class Synchronizer {
public:
    explicit Synchronizer(int stream_count, StreamOperator *stream_operator);

    ~Synchronizer() = default;

    //同步过程
    auto synchronize_stream(std::queue<Tuple> &input) -> void;

    auto get_output() -> std::queue<Tuple>;

private:
//    //输入区
//    std::queue<Tuple> input_{};

    std::mutex m;
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

    //连接器
    StreamOperator *stream_operator_;
};


#endif //DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
