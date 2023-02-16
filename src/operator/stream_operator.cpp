//
// Created by 86183 on 2023/1/8.
//

#include "operator/stream_operator.h"

StreamOperator::StreamOperator(TupleProductivityProfiler *profiler) {
    productivity_profiler_ = profiler;
}



auto StreamOperator::get_result() -> std::queue<std::vector<Tuple>> {
    return result_;
}

auto StreamOperator::mswj_execution(std::queue<Tuple> &input) -> void {
    std::lock_guard<std::mutex> lock(latch_);
    while (!input.empty()) {
        Tuple tuple = input.front();
        input.pop();
        int stream_id = tuple.streamId;

        //计算Di
        int delay = tuple.delay;


        //计算cross-join的结果大小
        int cross_join = 1;

        if (tuple.ts >= T_op_) {
            T_op_ = tuple.ts;

            for (auto &it: window_map_) {
                //统计window内元组数量数据
                productivity_profiler_->add_join_record(stream_id, it.second.size());

                if (it.first == stream_id) {
                    continue;
                }

                for (auto iter = it.second.begin(); iter != it.second.end();) {
                    Tuple tuple_j = *iter;
                    cross_join++;
                    if (tuple_j.ts < tuple.ts - it.second.size()) {
                        it.second.erase(iter++);
                        cross_join--;
                    } else {
                        iter++;
                    }
                }

            }

            //更新cross_join_map
            productivity_profiler_->update_cross_join(delay, cross_join);

            //连接
            std::vector<Tuple> join_tuple;
            join_tuple.push_back(tuple);
            for (auto &it: window_map_) {
                if (it.first == stream_id) {
                    continue;
                }
                while (!it.second.empty()) {
                    Tuple tuple_j = it.second.front();
                    it.second.pop_front();
                    if (can_join_(tuple, tuple_j)) {
                        //时间戳定义为ei.ts
                        tuple_j.ts = tuple.ts;
                        join_tuple.push_back(tuple_j);
                    }
                }
            }
            result_.push(join_tuple);

            //更新join result map
            productivity_profiler_->update_join_res(delay, join_tuple.size());

            window_map_[stream_id].push_back(tuple);
        } else if (tuple.ts > T_op_ - window_map_[stream_id].size()) {
            window_map_[stream_id].push_back(tuple);
        }
    }
}





