//
// Created by 86183 on 2023/1/7.
//

#include <iostream>
#include "synchronizer/synchronizer.h"

Synchronizer::Synchronizer(std::list<KSlack *> kslack_list) {
    for (auto it: kslack_list) {
        std::queue<Tuple> q = it->get_output();
        while (!q.empty()) {
            input_.push(q.front());
            q.pop();
        }
    }
    stream_count_ = kslack_list.size();
}


auto Synchronizer::get_output() -> std::queue<Tuple> {
    return output_;
}


//从k-slack发送过来的流
auto Synchronizer::synchronize_stream() -> void {
    while (!input_.empty()) {
        Tuple tuple = input_.front();
        int stream_id = tuple.streamId;
        input_.pop();
        if (tuple.ts > T_sync_) {
            if (sync_buffer_map_.find(stream_id) == sync_buffer_map_.end() || sync_buffer_map_[stream_id].empty()) {
                //下一步要插入tuple了
                own_stream_++;
            }
            sync_buffer_map_[stream_id].insert(tuple);
            //检测是否缓冲区拥有所有流的tuple
            while (own_stream_ == stream_count_) {
                //找到Tsync
                T_sync_ = INT8_MAX;
                for (auto it: sync_buffer_map_) {
                    T_sync_ = std::min(T_sync_, it.second.begin()->ts);
                }

                for (auto &it: sync_buffer_map_) {
                    //将所有等于Tsync的元组输出
                    while (it.second.begin()->ts == T_sync_) {
                        output_.push(*it.second.begin());
                        it.second.erase(it.second.begin());
                    }
                    if (it.second.empty()) {
                        own_stream_--;
                    }
                }
            }
        } else {
            Tuple tuple = input_.front();
            input_.pop();
            output_.push(tuple);
        }
    }

    std::cout << "同步后:" << std::endl;
    print(output_);
}

