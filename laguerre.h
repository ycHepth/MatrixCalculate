//
// Created by azurec on 2020/9/12.
//

#ifndef MATRIXCALCULATE_LAGUERRE_H
#define MATRIXCALCULATE_LAGUERRE_H

#include "Matrix.h"
/**
 * @param a : laguerre network pole
 * @param N : laguerre network rank
 * @return tuple : {A,L0}
 */
void laguerre(double a, unsigned int N, Matrix<double> &A, Vector<double> &L0);

#endif //MATRIXCALCULATE_LAGUERRE_H
