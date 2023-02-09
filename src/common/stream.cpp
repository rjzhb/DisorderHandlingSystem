//
// Created by 86183 on 2023/1/8.
//



#include <utility>

#include "common/define.h"

Stream::Stream(int stream_id, int window_size, std::queue<Tuple> tuple_list) {
    stream_id_ = stream_id;
    window_size_ = window_size;
    tuple_list_ = std::move(tuple_list);
}

auto Stream::get_window_size() -> int {
    return window_size_;
}

auto Stream::get_id() -> int {
    return stream_id_;
}

auto Stream::get_tuple_list() -> std::queue<Tuple> {
    return tuple_list_;
}

auto Stream::pop_tuple() -> void {
    tuple_list_.pop();
}

auto Stream::push_tuple(Tuple tuple) -> void {
    tuple_list_.push(tuple);
}



