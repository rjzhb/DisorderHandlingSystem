//
// Created by 86183 on 2023/1/7.
//

#include "synchronizer/synchronizer.h"


//从k-slack发送过来的流
auto Synchronizer::synchronize_stream(std::queue<Tuple> input_list) -> void {
    int stream_id = input_list.front().streamId;
    while (!input_list.empty()) {
        Tuple tuple = input_list.front();
        input_list.pop();
        if (tuple.ts > T_sync_) {
            if (sync_buffer_map_.find(stream_id) == sync_buffer_map_.end() || sync_buffer_map_[stream_id].empty()) {
                //下一步要插入tuple了
                own_stream_++;
            }
            sync_buffer_map_[stream_id].insert(tuple);
            //检测是否缓冲区拥有所有流的tuple
            while (own_stream_ == stream_count_) {
                //找到Tsync
                for (auto it: sync_buffer_map_) {
                    T_sync_ = std::min(T_sync_, it.second.begin()->ts);
                }

                for (auto it: sync_buffer_map_) {
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
            Tuple tuple = input_list.front();
            input_list.pop();
            output_.push(tuple);
        }
    }

}

