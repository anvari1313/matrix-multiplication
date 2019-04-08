cmake_minimum_required(VERSION 3.13)
project(matrix_multiplication)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

set(CMAKE_CXX_STANDARD 17)

add_executable(matrix_multiplication src/main.cpp src/data/dataset.cpp src/data/dataset.h src/data/matrix.cpp src/data/matrix.h src/task/task_runner.cpp src/task/task_runner.h src/task/one_dimension_task_runner.cpp src/task/one_dimension_task_runner.h)