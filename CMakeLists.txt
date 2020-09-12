cmake_minimum_required(VERSION 3.17)
project(MatrixCalculate)

set(CMAKE_CXX_STANDARD 20)

add_executable(MatrixCalculate main.cpp Matrix.cpp Matrix.h Array.h Array.cpp laguerre.cpp laguerre.h)