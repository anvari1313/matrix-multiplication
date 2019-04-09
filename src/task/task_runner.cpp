//
// Created by ahmad on 4/8/19.
//

#include "task_runner.h"

matrix_multiplication::task::TaskRunner::TaskRunner(size_t dataset_row, size_t dataset_col) :
        dataset_(dataset_row, dataset_col),
        dataset_row_(dataset_row),
        dataset_col_(dataset_col) {

}