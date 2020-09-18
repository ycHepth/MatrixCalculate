//
// Created by azurec on 2020/9/17.
//

#ifndef MATRIXCALCULATE_EXTMODEL_H
#define MATRIXCALCULATE_EXTMODEL_H

#include "Matrix.h"
/**
 * calculated augmented model of given discrete system (A,B,C)
 * @param A
 * @param B
 * @param C
 * @return
 */
//std::tuple<Matrix<double>,Matrix<double>,Matrix<double>> augmented(Matrix<double> A,Matrix<double> B,Matrix<double> C);
void augmented(Matrix<double> A, Matrix<double> B, Matrix<double> C, Matrix<double> &Ae, Matrix<double> &Be, Matrix<double> &Ce);

#endif //MATRIXCALCULATE_EXTMODEL_H
