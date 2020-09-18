//
// Created by azurec on 2020/9/12.
//
#include "Matrix.h"

/**
 * generate eye-matrix
 * @tparam T
 * @param n
 * @param m
 * @return
 */
Matrix<double> EyeMatrix(const unsigned int n, const unsigned int m) {
    Matrix<double> E;
    E.resize(n,m);
    E = Matrix(DIAG,1.0,0.0,n,m);
    return E;
}

Matrix<double> ZeroMatrix(const unsigned int n, const unsigned int m){
    Matrix<double> T;
    T.resize(n,m);
    T = Matrix(DIAG,0.0,0.0,n,m);
    return T;
}

Matrix<double> transposeVector(const Vector<double> &v){
    unsigned int rows = v.size();
    Matrix<double> T = Matrix(TRANS,v,0.0,1,rows);
    return T;
}

//template <typename T>
Matrix<double> exp(const Matrix<double>&m, unsigned int n){
    Matrix<double> tmp(m.nrows(), m.ncols());
    if (n == 0) {
        tmp = EyeMatrix(m.nrows(), m.ncols());
        return tmp;
    }
    tmp = m;
    for (int j = 1; j < n; j++)
        tmp = dot_prod(m,tmp);
    return tmp;
}