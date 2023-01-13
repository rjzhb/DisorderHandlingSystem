//
// Created by 86183 on 2023/1/10.
//
#include "common/define.h"

std::unordered_map<int, Stream *> stream_map;

//获得离散随机变量Di的值,如果delay(ei) ∈(kg,(k+1)g]，则Di=k+1
auto get_D(int delay) -> int {
    return delay % g == 0 ? delay / g : delay / g + 1;
}