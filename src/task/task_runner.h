/**
 * This class will handler concurrent task
 */
#ifndef MATRIX_MULTIPLICATION_TASK_RUNNER_H
#define MATRIX_MULTIPLICATION_TASK_RUNNER_H

#include "../data/dataset.h"

namespace matrix_multiplication::task {
    class TaskRunner {
    private:
    protected:
        size_t dataset_row_;
        size_t dataset_col_;

        int thread_num_;

        matrix_multiplication::data::Dataset dataset_;

    public:
        TaskRunner(size_t dataset_row, size_t dataset_col, int thread_num);

        virtual void RunParallel() = 0;
    };  // class TaskRunner

}   // namespace matrix_multiplication::task


#endif //MATRIX_MULTIPLICATION_TASK_RUNNER_H
