#include <iostream>
#include <list>
#include <thread>
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

    std::list<Stream *> list;
    list.push_back(stream_1);

    stream_map[1] = stream_1;
    return list;
}

static void *task(void *p) {
    reinterpret_cast<KSlack *>(p)->disorder_handling();
}

int main() {
    //初始化
    TupleProductivityProfiler *productivity_profiler = new TupleProductivityProfiler();
    StreamOperator *stream_operator = new StreamOperator(productivity_profiler);
    StatisticsManager *statistics_manager = new StatisticsManager(productivity_profiler);
    BufferSizeManager *buffer_size_manager = new BufferSizeManager(statistics_manager, productivity_profiler);
    Synchronizer *synchronizer = new Synchronizer(1, stream_operator);

    std::list<Stream *> stream_list = generate_stream();
    std::list<KSlack *> kslack_list;

    for (auto it: stream_list) {
        KSlack *kslack = new KSlack(it, buffer_size_manager, statistics_manager, synchronizer);
        kslack_list.push_back(kslack);
    }

    //生成线程
    pthread_t t1 = 1;
    pthread_t t2 = 2;
    pthread_create(&t1, NULL, &task, kslack_list.front());

    //执行线程：
    pthread_join(t1, NULL);


    //输出kslack后的结果
    for (auto it: kslack_list) {
        std::cout << "kslack作用后:" << std::endl;
        print(it->get_output());
    }

    //同步后的结果：
    std::cout << "同步后:" << std::endl;
    print(synchronizer->get_output());

    //连接后的结果：
    std::cout << "连接后:" << std::endl;
    print(stream_operator->get_result());

    delete productivity_profiler;
    delete stream_operator;
    delete statistics_manager;
    delete buffer_size_manager;
    return 0;
}
