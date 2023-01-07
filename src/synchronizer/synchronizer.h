//
// Created by 86183 on 2023/1/7.
//

#ifndef DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
#define DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H


#include <vector>
#include "kslack/k_slack.h"

class Synchronizer {
public:

private:
    //待同步k-slack组件
    std::vector<KSlack> kslack_list_;

};


#endif //DISORDERHANDLINGSYSTEM_SYNCHRONIZER_H
