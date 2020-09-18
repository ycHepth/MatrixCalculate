//
// Created by azurec on 2020/9/18.
//

#ifndef MATRIXCALCULATE_DMPC_H
#define MATRIXCALCULATE_DMPC_H

#include "laguerre.h"
void dmpc(Matrix<double> A_e,Matrix<double> B_e, double a, unsigned int N, unsigned int Np, Matrix<double> Q, Matrix<double> R, Matrix<double> &E, Matrix<double> &H);


#endif //MATRIXCALCULATE_DMPC_H
