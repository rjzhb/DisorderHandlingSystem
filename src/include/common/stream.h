//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_H
#define DISORDERHANDLINGSYSTEM_STREAM_H


#include <queue>
#include "common/define.h"

class Stream {
public:

    int get_window_size() { return window_size_; }

    int get_id() { return stream_id_; }

    std::queue<Tuple> get_tuple_list() { return tuple_list_; }

    void syn_res_push(Tuple tuple) { syn_res_.push(tuple); }

private:
    //论文中的Wi
    int window_size_;
    //流id
    int stream_id_;
    //元组
    std::queue<Tuple> tuple_list_;
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_H
