//
// Created by azurec on 2020/9/12.
//

#ifndef MATRIXCALCULATE_MATRIX_H
#define MATRIXCALCULATE_MATRIX_H

#include "Array.h"

/**
 * generate identical matrix (eye in MATLAB)
 * @param n
 * @param m
 * @return
 */
Matrix<double> EyeMatrix(const unsigned int n, const unsigned int m);

/**
 * generate zero matrix
 * @param n
 * @param m
 * @return
 */
Matrix<double> ZeroMatrix(const unsigned int n, const unsigned int m);

/**
 * transfer column vector to row vector
 * @param v
 * @return
 */
Matrix<double> transposeVector(const Vector<double> &v);

/**
 * get power of square matrix
 * @param m
 * @param n
 * @return
 */
Matrix<double> exp(const Matrix<double>&m, unsigned int n);

/**
 * get power sequence of specified square matrix
 * @param a
 * @param n
 * @return
 */
std::vector<Matrix<double>> get_powers(const Matrix<double> a, int n);

/**
 * extend matrix with large dimensions. the inner function declared in Matrix class
 * @param m : operated matrix
 * @param r : extended rows
 * @param c : extended cols
 */
void extend_matrix(Matrix<double> &m, unsigned int r, unsigned int c);

/**
 * set
 * @param a : Target Vector
 * @param b : Origin Vector
 * @param pos : the start position of overwriting.
 */
void set_subvector(Vector<double> &a, const Vector<double> &b, unsigned int pos);

/**
 * set submatrix
 * @param dst : Target Matrix
 * @param src : Origin Matrix
 * @param row : start point of rows
 * @param col : start point of cols
 */
void set_submatrix(Matrix<double> &dst, const Matrix<double> &src, int row,
                   int col);
/**
 * extend vector with large dimensions.
 * @param v
 * @param n
 */
void extend_vector(Vector<double> &v, int n);

/**
 * bind compatible matrices in rows
 * @param a : matrix one
 * @param b : matrix two
 * @return  : bind matrix
 */
Matrix<double> bind_matrices(const Matrix<double> &a, const Matrix<double> &b);

/**
 * bind vector in rows
 * @param a : matrix one
 * @param b : matrix two
 * @return  : bind vector
 */
Vector<double> bind_vectors(const Vector<double> &a, const Vector<double> &b);

#endif //MATRIXCALCULATE_MATRIX_H
