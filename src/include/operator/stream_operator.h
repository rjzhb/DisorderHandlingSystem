//
// Created by 86183 on 2023/1/8.
//

#ifndef DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
#define DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H


#include <queue>
#include "common/define.h"
#include "common/stream.h"

class StreamOperator {
public:

    void mswj_execution(std::vector<Stream *> stream_list_);

private:
    //连接时的T
    int T_op_;
    //
};


#endif //DISORDERHANDLINGSYSTEM_STREAM_OPERATOR_H
