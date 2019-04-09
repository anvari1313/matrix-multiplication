//
// Created by ahmad on 4/8/19.
//

#include "one_dimension_task_runner.h"
#include <vector>

matrix_multiplication::task::OneDimensionTaskRunner::OneDimensionTaskRunner(size_t dataset_row, size_t dataset_col)
        : TaskRunner(dataset_row, dataset_col) {

}

void matrix_multiplication::task::OneDimensionTaskRunner::RunParallel() {
    auto partial_result = new matrix_multiplication::data::Matrix<int>[dataset_row_];

    for (size_t i = 0; i < dataset_row_; ++i) {
        partial_result[i].SetDimensions(dataset_row_, dataset_col_);
    }

    for (size_t i = 0; i < dataset_row_; ++i) {

    }

    delete[](partial_result);
}
