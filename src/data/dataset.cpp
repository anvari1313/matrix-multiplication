//
// Created by ahmad on 4/4/19.
//
#include <random>
#include "dataset.h"

matrix_multiplication::data::Dataset::Dataset(size_t row, size_t col): row_(row), col_(col), mat1_(row, col), mat2_(col, row)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 10);

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            mat1_[i][j] = dist(mt);
            mat2_[j][i] = dist(mt);
        }
    }
}

matrix_multiplication::data::Matrix<int>
matrix_multiplication::data::Dataset::PartialMultiply(size_t mat1_start_index, size_t mat1_end_index,
                                                      size_t mat2_start_index, size_t mat2_end_index) {
    Matrix<int> result(row_, row_);
    result.Initialize(0);
    for (size_t i = mat1_start_index; i < mat1_end_index; ++i) {
        for (size_t j = mat2_start_index; j < mat2_end_index; ++j) {
            for (size_t k = 0; k < col_; ++k) {
                result[i][j] += mat1_[i][k] * mat2_[k][j];
            }
        }
    }
    return result;
}

matrix_multiplication::data::Matrix<int> matrix_multiplication::data::Dataset::Multiply() {
    return this->PartialMultiply(0, col_, 0, row_);
}

matrix_multiplication::data::Dataset::~Dataset()
= default;