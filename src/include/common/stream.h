//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_H
#define DISORDERHANDLINGSYSTEM_STREAM_H


#include <queue>
#include "define.h"


class Stream {
public:

    auto get_window_size() -> int { return window_size_; }

    auto get_id() -> int { return stream_id_; }

    auto get_tuple_list() -> std::queue<Tuple> { return tuple_list_; }


private:
    //论文中的Wi
    int window_size_;
    //流id
    int stream_id_;
    //元组
    std::queue<Tuple> tuple_list_;
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_H
