//
// Created by azurec on 2020/9/12.
//

#ifndef MATRIXCALCULATE_MATRIX_H
#define MATRIXCALCULATE_MATRIX_H

#include "Array.h"


Matrix<double> EyeMatrix(const unsigned int n, const unsigned int m);
Matrix<double> ZeroMatrix(const unsigned int n, const unsigned int m);
Matrix<double> transposeVector(const Vector<double> &v);

Matrix<double> exp(const Matrix<double>&m, unsigned int n);
#endif //MATRIXCALCULATE_MATRIX_H
