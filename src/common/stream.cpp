//
// Created by 86183 on 2023/1/8.
//



#include "common/define.h"

auto Stream::get_window_size() -> int {
    return window_size_;
}

auto Stream::get_id() -> int {
    return stream_id_;
}

auto Stream::get_tuple_list() -> std::queue<Tuple> {
    return tuple_list_;
}
