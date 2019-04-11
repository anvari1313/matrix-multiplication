//
// Created by ahmad on 4/4/19.
//

#ifndef MATRIX_MULTIPLICATION_DATASET_H
#define MATRIX_MULTIPLICATION_DATASET_H

#include "matrix.h"

namespace matrix_multiplication::data {
    class Dataset {
    private:
        size_t row_;
        size_t col_;

    public:

        Matrix<int> mat1_;
        Matrix<int> mat2_;

        Dataset(size_t row, size_t col);
        void FillRandom(double low_bound, double high_bound);
        Matrix<int> PartialMultiply(size_t mat1_start_index, size_t mat1_end_index, size_t mat2_start_index, size_t mat2_end_index);
        Matrix<int> Multiply();
        ~Dataset();
    };
} // namespace matrix_multiplication::data

#endif //MATRIX_MULTIPLICATION_DATASET_H
