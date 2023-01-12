//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_H
#define DISORDERHANDLINGSYSTEM_STREAM_H


#include <queue>

struct Tuple {
    //表示来自输入流Si
    int streamId;
    //第几个到达的元组
    int id;
    //时间戳
    int ts;
    //延迟
    int delay;
};

struct TupleComparator {
    //按到达时间来排序
    bool operator()(Tuple e1, Tuple e2) {
        return e1.ts == e2.ts ? e1.id < e2.id : e1.ts < e2.ts;
    }
};


class Stream {
public:

    auto get_window_size() -> int;

    auto get_id() -> int;

    auto get_tuple_list() -> std::queue<Tuple>;


private:
    //论文中的Wi
    int window_size_;
    //流id
    int stream_id_;
    //元组
    std::queue<Tuple> tuple_list_;
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_H
