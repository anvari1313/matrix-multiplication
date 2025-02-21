//
// Created by ahmad on 4/5/19.
//

#ifndef MATRIX_MULTIPLICATION_MATRIX_H
#define MATRIX_MULTIPLICATION_MATRIX_H

#include <cstddef>
#include <ostream>
#include <algorithm>

namespace matrix_multiplication::data {
    template<class T>
    class Matrix {
    private:
        size_t row_;
        size_t col_;
        T **matrix;

        void AllocateMemory();

    public:
        Matrix();

        Matrix(size_t row, size_t col);

        void SetDimensions(size_t row, size_t col);

        size_t get_row();

        size_t get_col();

        void Initialize(T value);

        T *operator[](size_t index);

        bool operator==(Matrix<T> m) const;

        std::string to_string(std::ostream &os);

        void Add(Matrix<T> matrix);

        void dispose();

        ~Matrix();


    };
} // namespace matrix_multiplication::data

//template <class T>
//std::ostream & operator << (std::ostream &os, const matrix_multiplication::data::Matrix<T> &matrix)   {
//    for (size_t i = 0; i < matrix.get_row(); ++i) {
//        for (size_t j = 0; j < matrix.get_col(); ++j) {
//            os << matrix[i][j];
//        }
//        os << std::endl;
//    }
//    return os;
//}

// TODO: Change to string function to stream operator
template<class T>
std::string matrix_multiplication::data::Matrix<T>::to_string(std::ostream &os) {
    std::string result;
    for (size_t i = 0; i < row_; ++i) {
        for (size_t j = 0; j < col_; ++j) {
            os << matrix[i][j] << "\t";
        }
//        result +=  "\n";
        os << std::endl;
    }
    return result;
}
//
//matrix_multiplication::data::Matrix<int> & operator +(matrix_multiplication::data::Matrix<int> lhs, matrix_multiplication::data::Matrix<int> & rhs){
//    for (size_t i = 0; i < lhs.get_row(); ++i) {
//        for (size_t j = 0; j < lhs.get_col(); ++j) {
//            lhs[i][j] += rhs[i][j];
//        }
//    }
//    return lhs;
//}


template<class T>
matrix_multiplication::data::Matrix<T>::Matrix(size_t row, size_t col): row_(row), col_(col) {
    AllocateMemory();
}


template<class T>
void matrix_multiplication::data::Matrix<T>::Initialize(T value) {
    for (size_t i = 0; i < row_; ++i) std::fill_n(this->matrix[i], col_, value);
}

template<class T>
T *matrix_multiplication::data::Matrix<T>::operator[](size_t index) {
    return this->matrix[index];
}

#include <iostream>

template<class T>
matrix_multiplication::data::Matrix<T>::~Matrix() {

}

template<class T>
size_t matrix_multiplication::data::Matrix<T>::get_row() {
    return this->row_;
}

template<class T>
size_t matrix_multiplication::data::Matrix<T>::get_col() {
    return this->col_;
}


template<class T>
void matrix_multiplication::data::Matrix<T>::Add(matrix_multiplication::data::Matrix<T> matrix) {
    for (size_t i = 0; i < matrix.row_; ++i) {
        for (size_t j = 0; j < matrix.col_; ++j) {
            this->matrix[i][j] = this->matrix[i][j] + matrix[i][j];
        }
    }
}

template<class T>
bool matrix_multiplication::data::Matrix<T>::operator==(matrix_multiplication::data::Matrix<T> m) const {
    if (m.get_row() != this->row_) return false;
    if (m.get_col() != this->col_) return false;

    for (size_t i = 0; i < m.get_row(); ++i) {
        for (size_t j = 0; j < m.get_col(); ++j) {
            if (this->matrix[i][j] != m[i][j]) return false;
        }
    }

    return true;
}

template<class T>
matrix_multiplication::data::Matrix<T>::Matrix() {

}

template<class T>
void matrix_multiplication::data::Matrix<T>::AllocateMemory() {
    this->matrix = new T *[col_];
    for (size_t i = 0; i < col_; ++i) this->matrix[i] = new T[row_];
}

template<class T>
void matrix_multiplication::data::Matrix<T>::SetDimensions(size_t row, size_t col) {
    row_ = row;
    col_ = col;
    AllocateMemory();
}

template<class T>
void matrix_multiplication::data::Matrix<T>::dispose() {
    for (size_t i = 0; i < col_; ++i) delete[] this->matrix[i];
    delete[] this->matrix;
}

#endif //MATRIX_MULTIPLICATION_MATRIX_H
