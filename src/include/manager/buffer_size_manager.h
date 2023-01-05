//
// Created by 86183 on 2023/1/5.
//

#ifndef DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H
#define DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H


class BufferSizeManager {
public:

    //自适应K值算法
    auto k_search(int L, int b, int g) -> int;

    //论文中的函数γ(L,T)
    auto y(int L, int T) -> double;

private:

};


#endif //DISORDERHANDLINGSYSTEM_BUFFER_SIZE_MANAGER_H
