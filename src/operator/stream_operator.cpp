//
// Created by 86183 on 2023/1/8.
//

#include "operator/stream_operator.h"

//连接条件,根据实际生产由程序员指定
auto StreamOperator::can_join_(Tuple t1, Tuple t2) -> bool {
    return true;
}

auto StreamOperator::get_result() -> std::queue<Tuple> {
    return result_;
}

void StreamOperator::mswj_execution(std::queue<Tuple> input) {
    while (!input.empty()) {
        Tuple tuple = input.front();
        input.pop();
        int stream_id = tuple.streamId;

        //计算Di
        int Di = get_D(tuple.delay);

        //计算cross-join的结果大小
        int cross_join = 1;

        if (tuple.ts >= T_op_) {
            T_op_ = tuple.ts;

            for (auto it: window_map_) {
                //统计window内元组数量数据
                productivity_profiler_->add_join_record(stream_id, it.second.size());

                if (it.first == stream_id) {
                    continue;
                }

                while (!it.second.empty()) {
                    Tuple tuple_j = it.second.front();
                    cross_join++;
                    if (tuple_j.ts < tuple.ts - it.second.size()) {
                        it.second.pop();
                        cross_join--;
                    }
                }
            }

            //更新cross_join_map
            productivity_profiler_->update_cross_join(Di, cross_join);

            //连接
            int res_size = 1;
            result_.push(tuple);
            for (auto it: window_map_) {
                if (it.first == stream_id) {
                    continue;
                }
                while (!it.second.empty()) {
                    Tuple tuple_j = it.second.front();
                    it.second.pop();
                    if (can_join_(tuple, tuple_j)) {
                        res_size++;
                        //时间戳定义为ei.ts
                        tuple_j.ts = tuple.ts;
                        result_.push(tuple_j);
                    }
                }
            }

            //更新join result map
            productivity_profiler_->update_join_res(Di, res_size);

            window_map_[stream_id].push(tuple);
        } else if (tuple.ts > T_op_ - window_map_[stream_id].size()) {
            window_map_[stream_id].push(tuple);
        }
    }

}





