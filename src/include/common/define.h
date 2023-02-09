//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_DEFINE_H
#define DISORDERHANDLINGSYSTEM_DEFINE_H


#include <unordered_map>
#include <queue>
#include <mutex>
#include "parallel-hashmap/parallel_hashmap/phmap.h"

//系统参数定义
//搜索粒度
constexpr int g{1};

//自适应时间间隔
constexpr int L{3};

//最大延迟
constexpr int maxDelay = 100;

//用户期待的recall率
constexpr double userRecall{0.4};

//用户设定的时间P
constexpr int P{4};

//basic window size
constexpr int b{1};

//用于估计R的可信度值，范围(0,1)
constexpr double confidenceValue{0.5};

class Stream;

struct Tuple;

extern phmap::parallel_flat_hash_map<int, Stream *> stream_map;

extern std::mutex global_lock;

//获得离散随机变量Di(粗粒度延迟)的值
auto inline get_D(int delay) -> int;

//输出用
auto inline print(std::queue<Tuple> q) -> void;

struct Tuple {
    //表示来自输入流Si
    int streamId;
    //第几个到达的元组
    int id;
    //时间戳
    int ts;
    //延迟
    int delay{};

    Tuple(int streamId, int id, int ts) : streamId(streamId), id(id), ts(ts) {}
};

struct TupleComparator {
    //按到达时间来排序
    bool operator()(Tuple e1, Tuple e2) const {
        return e1.ts == e2.ts ? e1.id < e2.id : e1.ts < e2.ts;
    }
};


class Stream {
public:

    explicit Stream(int stream_id, int window_size, std::queue<Tuple> tuple_list);

    ~Stream() = default;

    auto get_window_size() -> int;

    auto get_id() -> int;

    auto get_tuple_list() -> std::queue<Tuple>;

    auto pop_tuple() -> void;

    auto push_tuple(Tuple tuple) -> void;

private:

    //论文中的Wi
    int window_size_{};

    //流id
    int stream_id_{};

    //元组
    std::queue<Tuple> tuple_list_{};
};


#endif //DISORDERHANDLINGSYSTEM_DEFINE_H
