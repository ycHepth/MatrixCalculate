//
// Created by azurec on 2020/9/12.
//
#include "laguerre.h"

Matrix<double> laguerre(double a, unsigned int N){
    Vector<double> V[N];
    Vector<double> L0[N];
    Matrix<double> A;
    V[0] = a;
    L0[0] = 1;

    for(int i = 1; i<N;i++){
        std::cout << pow(-0.8,0) << std::endl;
        V[i] = pow(-a,i-1)*(1-a*a);
        L0[i]= pow(-a,i);
        std::cout << V << std::endl;
    }

    return A;
}