//
// Created by azurec on 2020/9/12.
//
#include "laguerre.h"

void laguerre(double a, unsigned int N, Matrix<double> &A, Vector<double> &L0){
    Vector<double> V(N);
    L0.resize(N);
    A.resize(N,N);
    V[0] = a;
    L0[0] = 1;

    for(int i = 1; i<N;i++){
        V[i] = pow(-a,i-1)*(1-a*a);
        L0[i]= pow(-a,i);
    }
    L0 = sqrt(1-a*a) * L0;

    A.setColumn(0,V);

    for(int j = 1;j < N;j++){
        A.setColumn(j,V.RShift(j));
    }
}