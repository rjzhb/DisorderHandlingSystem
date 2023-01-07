//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_DEFINE_H
#define DISORDERHANDLINGSYSTEM_DEFINE_H

//系统参数定义
//搜索粒度
constexpr int g{};
//自适应时间间隔
constexpr int L{};
//最大延迟
constexpr int MAX_DELAY = 100;

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
        return e1.ts < e2.ts;
    }
};

#endif //DISORDERHANDLINGSYSTEM_DEFINE_H
