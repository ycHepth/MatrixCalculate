//
// Created by azurec on 2020/9/17.
//
#include "extmodel.h"

void augmented(Matrix<double> A, Matrix<double> B, Matrix<double> C, Matrix<double> &Ae, Matrix<double> &Be, Matrix<double> &Ce){
    unsigned int m1, n1,in_1;
    C.size(m1,n1);
    B.size(n1,in_1);

    Ae = EyeMatrix(n1+m1,n1+m1);
    Ae.range_set({0,n1-1},{0,n1-1},A);
    Ae.range_set({n1,n1+m1-1},{0,n1-1},dot_prod(C,A));

    Be = EyeMatrix(n1+m1,in_1);
    Be.range_set({0,n1-1},{0,in_1-1},B);
    Be.range_set({n1,n1+m1-1},{0,in_1-1},dot_prod(C,B));

    Ce = ZeroMatrix(m1,n1+m1);
    Ce.range_set({0,m1-1},{n1,n1+m1-1},EyeMatrix(m1,m1));
}