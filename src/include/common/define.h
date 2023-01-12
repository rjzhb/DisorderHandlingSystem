//
// Created by 86183 on 2023/1/4.
//

#ifndef DISORDERHANDLINGSYSTEM_DEFINE_H
#define DISORDERHANDLINGSYSTEM_DEFINE_H


#include <unordered_map>
#include "stream.h"

//系统参数定义
//搜索粒度
constexpr int g{};

//自适应时间间隔
constexpr int L{};

//最大延迟
constexpr int maxDelay = 100;

//用户期待的recall率
constexpr double userRecall{};

//用户设定的时间P
constexpr int P{};

//basic window size
constexpr int b{};

//用于估计R的可信度值，范围(0,1)
constexpr int confidenceValue{};

//流id和stream对象的映射
std::unordered_map<int, Stream *> stream_map;

//获得离散随机变量Di(粗粒度延迟)的值
auto get_D(int delay) -> int;

#endif //DISORDERHANDLINGSYSTEM_DEFINE_H
