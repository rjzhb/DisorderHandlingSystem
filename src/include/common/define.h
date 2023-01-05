//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_DEFINE_H
#define DISORDERHANDLINGSYSTEM_DEFINE_H



struct Tuple {
    //表示来自输入流Si
    int streamId;
    //第几个到达的元组
    int id;
    //时间戳
    int ts;
};

struct TupleComparator{
    //按到达时间来排序
    bool operator()(Tuple e1, Tuple e2){
        return e1.ts < e2.ts;
    }
};
#endif //DISORDERHANDLINGSYSTEM_DEFINE_H
