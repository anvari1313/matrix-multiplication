/**
 * This class will handler concurrent task
 */
#ifndef MATRIX_MULTIPLICATION_TASK_RUNNER_H
#define MATRIX_MULTIPLICATION_TASK_RUNNER_H

#include "../data/dataset.h"

namespace matrix_multiplication::task {
    class TaskRunner {
    private:
        matrix_multiplication::data::Dataset dataset;

    public:
        TaskRunner(size_t dataset_row, size_t dataset_col);

        virtual void RunParallel() = 0;
    };  // class TaskRunner

}   // namespace matrix_multiplication::task


#endif //MATRIX_MULTIPLICATION_TASK_RUNNER_H
