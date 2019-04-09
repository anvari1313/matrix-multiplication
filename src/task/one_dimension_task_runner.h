//
// Created by ahmad on 4/8/19.
//

#ifndef MATRIX_MULTIPLICATION_ONE_DIMENSION_TASK_RUNNER_H
#define MATRIX_MULTIPLICATION_ONE_DIMENSION_TASK_RUNNER_H

#include "task_runner.h"

namespace matrix_multiplication::task {
    class OneDimensionTaskRunner : public matrix_multiplication::task::TaskRunner {
    private:
    public:
        OneDimensionTaskRunner(size_t dataset_row, size_t dataset_col);
        void RunParallel() override;
    };
}   // namespace matrix_multiplication::task

#endif //MATRIX_MULTIPLICATION_ONE_DIMENSION_TASK_RUNNER_H
