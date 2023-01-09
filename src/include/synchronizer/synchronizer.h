//
// Created by 86183 on 2023/1/7.
//

#ifndef DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
#define DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H


#include <vector>
#include "kslack/k_slack.h"

class Synchronizer {
public:

    //同步过程
    void synchronize_stream(std::queue<Tuple> input_list);

    //获取某个流的Ksync
    auto get_Ksync(int stream_id) -> int;

private:
    //SyncBuf缓冲区映射
    std::unordered_map<int, std::set<Tuple, TupleComparator>> sync_buffer_map_;
    //Tsync
    int T_sync_{};
    //stream的数量
    int stream_count_;
    //当前缓冲区拥有tuple的流的数量
    int own_stream_{};
    //同步输出区
    std::queue<Tuple> output_;


};


#endif //DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
