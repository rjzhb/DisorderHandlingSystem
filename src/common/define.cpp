//
// Created by 86183 on 2023/1/10.
//
#include <iostream>
#include <mutex>
#include "common/define.h"

phmap::parallel_flat_hash_map<int, Stream *> stream_map;


//获得离散随机变量Di的值,如果delay(ei) ∈(kg,(k+1)g]，则Di=k+1
auto inline get_D(int delay) -> int {
    return delay % g == 0 ? delay / g : delay / g + 1;
}

auto inline print(std::queue<Tuple> q) -> void {
    while (!q.empty()) {
        std::cout << "e" << q.front().streamId << "," << q.front().id << "时间戳:" << q.front().ts << std::endl;
        q.pop();
    }
    std::cout << std::endl;
}