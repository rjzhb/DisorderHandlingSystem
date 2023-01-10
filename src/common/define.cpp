//
// Created by 86183 on 2023/1/10.
//
#include "common/define.h"

//获得离散随机变量Di的值,如果delay(ei) ∈(kg,(k+1)g]，则Di=k+1
int get_D(int delay) {
    return delay % g == 0 ? delay / g : delay / g + 1;
}