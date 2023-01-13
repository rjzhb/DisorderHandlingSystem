#include <iostream>
#include <list>
#include "manager/buffer_size_manager.h"
#include "operator/stream_operator.h"
#include "synchronizer/synchronizer.h"
#include "kslack/k_slack.h"

//测试用例
std::list<Stream *> generate_stream() {
    std::queue<Tuple> stream_1_list;

    Tuple e1_1(1, 1, 1);
    Tuple e1_2(1, 2, 4);
    Tuple e1_3(1, 3, 3);
    Tuple e1_4(1, 4, 5);
    Tuple e1_5(1, 5, 7);
    Tuple e1_6(1, 6, 8);
    Tuple e1_7(1, 7, 6);
    Tuple e1_8(1, 8, 9);

    stream_1_list.push(e1_1);
    stream_1_list.push(e1_2);
    stream_1_list.push(e1_3);
    stream_1_list.push(e1_4);
    stream_1_list.push(e1_5);
    stream_1_list.push(e1_6);
    stream_1_list.push(e1_7);
    stream_1_list.push(e1_8);

    Stream *stream_1 = new Stream(1, 2, stream_1_list);

    std::queue<Tuple> stream_2_list;

    Tuple e2_1(2, 1, 2);
    Tuple e2_2(2, 2, 5);
    Tuple e2_3(2, 3, 4);
    Tuple e2_4(2, 4, 5);
    Tuple e2_5(2, 5, 8);
    Tuple e2_6(2, 6, 9);
    Tuple e2_7(2, 7, 7);
    Tuple e2_8(2, 8, 10);

    stream_2_list.push(e2_1);
    stream_2_list.push(e2_2);
    stream_2_list.push(e2_3);
    stream_2_list.push(e2_4);
    stream_2_list.push(e2_5);
    stream_2_list.push(e2_6);
    stream_2_list.push(e2_7);
    stream_2_list.push(e2_8);

    Stream *stream_2 = new Stream(2, 2, stream_2_list);

    std::list<Stream *> list;
    list.push_back(stream_1);
    list.push_back(stream_2);

    stream_map[1] = stream_1;
    stream_map[2] = stream_2;

    return list;
}


int main() {
    //初始化
    Synchronizer *synchronizer = new Synchronizer();
    TupleProductivityProfiler *productivity_profiler = new TupleProductivityProfiler();
    StreamOperator *stream_operator = new StreamOperator(productivity_profiler);
    StatisticsManager *statistics_manager = new StatisticsManager(productivity_profiler);
    BufferSizeManager *buffer_size_manager = new BufferSizeManager(statistics_manager, productivity_profiler);

    std::list<Stream *> stream_list = generate_stream();
    std::list<KSlack *> kslack_list;

    for (auto it: stream_list) {
        KSlack *kslack = new KSlack(it, buffer_size_manager, statistics_manager, synchronizer);
        kslack_list.push_back(kslack);
    }

    for (auto it: kslack_list) {
        it->disorder_handling();
    }

    delete synchronizer;
    delete productivity_profiler;
    delete stream_operator;
    delete statistics_manager;
    delete buffer_size_manager;
    return 0;
}
