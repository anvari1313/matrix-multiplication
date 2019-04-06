//
// Created by ahmad on 4/5/19.
//

#ifndef MATRIX_MULTIPLICATION_MATRIX_H
#define MATRIX_MULTIPLICATION_MATRIX_H

#include <cstddef>
#include <ostream>
#include <algorithm>

namespace matrix_multiplication::data
{
    template <class T>
    class Matrix {
    private:
        size_t row_;
        size_t col_;
        T **matrix;

    public:
        Matrix(size_t row, size_t col);

        size_t get_row();
        size_t get_col();

        void Initialize(T value);

        T *operator [](size_t index);

        std::string to_string(std::ostream &os);

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


template <class T>
matrix_multiplication::data::Matrix<T>::Matrix(size_t row, size_t col): row_(row), col_(col)
{
    this->matrix = new T*[col_];
    for (size_t i = 0; i < col_; ++i) this->matrix[i] = new T[row_];
}



template <class T>
void matrix_multiplication::data::Matrix<T>::Initialize(T value)
{
    for (size_t i = 0; i < row_; ++i) std::fill_n(this->matrix[i], col_, value);
}

template<class T>
T *matrix_multiplication::data::Matrix<T>::operator[](size_t index) {
    return this->matrix[index];
}

template<class T>
matrix_multiplication::data::Matrix<T>::~Matrix()
{
    for (size_t i = 0; i < col_; ++i)  delete[] this->matrix[i];
    delete[] this->matrix;
}

template<class T>
size_t matrix_multiplication::data::Matrix<T>::get_row() {
    return this->row_;
}

template<class T>
size_t matrix_multiplication::data::Matrix<T>::get_col() {
    return this->col_;
}

#endif //MATRIX_MULTIPLICATION_MATRIX_H
