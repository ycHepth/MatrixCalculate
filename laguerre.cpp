//
// Created by azurec on 2020/9/12.
//
#include "laguerre.h"

Matrix<double> laguerre(double a, unsigned int N){
    Vector<double> V(N);
    Vector<double> L0(N);
    Matrix<double> A(N,N);
    V[0] = a;
    L0[0] = 1;

    for(int i = 1; i<N;i++){
        V[i] = pow(-a,i-1)*(1-a*a);
        L0[i]= pow(-a,i);
    }
    L0 = sqrt(1-a*a) * L0;

    std::cout << "L0 : " << std::endl;
    std::cout << L0 << std::endl;

    A.setColumn(0,V);
    std::cout << A << std::endl;

    std::cout << L0.LShift(2) << std::endl;

    for(int j = 1;j < N-1;j++){
        // How to change entry vector? ... hand write <.Rshift> function
        std::cout << L0.LShift(1) << std::endl;

    }

    return A;
}