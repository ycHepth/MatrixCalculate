//
// Created by azurec on 2020/9/18.
//
#include "dmpc.h"

void dmpc(Matrix<double> A_e,Matrix<double> B_e, double a, unsigned int N,
          unsigned int Np, Matrix<double> Q, Matrix<double> R, Matrix<double> &E, Matrix<double> &H)
{
    // for SISO case: Np = 1
    unsigned int n, n_in;
    B_e.size(n,n_in);
    E = ZeroMatrix(1,1);
    H = ZeroMatrix(1,n);

    auto S_in = ZeroMatrix(n,1);
    Matrix<double> A;
    Vector<double> L0;
    laguerre( a,  N, A, L0);
    S_in = dot_prod(B_e,transposeVector(L0));

    auto S_sum = S_in;
    auto Phi = S_in;
    E = dot_prod(dot_prod(t(Phi),Q),Phi);
    H = dot_prod(dot_prod(t(Phi),Q),A_e);

    for(int i = 2; i<Np;i++){
        auto Eae = exp(A_e,i);
        laguerre( a,  N, A, L0);
        S_sum = dot_prod(A_e,S_sum) + dot_prod(S_in,t(exp(A,i-1)));

        Phi = S_sum;
        E += dot_prod(dot_prod(t(Phi),Q),Phi);
        H += dot_prod(dot_prod(t(Phi),Q),A_e);
    }

    E = E + R;
}
