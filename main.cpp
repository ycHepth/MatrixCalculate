#include <iostream>
#include "Array.h"

int main() {
//    std::set<unsigned int> index;
//    index = {0,1};
//
//    int a[3] = {1,2,3};
//
//    Vector<int> first(a,3);
//    Vector<int> second;
//    second = first + 2;
////    second(a,3);
//    std::cout << "first" << std::endl;
//    std::cout << first << std::endl;
//
////    second.set(a,3);
//    std::cout << "second" << std::endl;
//    std::cout << second << std::endl;
//
//    Vector<int> third = second.extract(index);
//    std::cout << "third" << std::endl;
//    std::cout << third << std::endl;
//
//    double ele[] = {1,4,9};
//    Vector<double> fourth(ele,3);
//    std::cout << "fourth" << std::endl;
//    std::cout << fourth << std::endl;
//
//    std::cout << sqrt(fourth) << std::endl;
//
////    Matrix
//    Matrix<int> m1(1,3,4);
//    std::cout << m1 << std::endl;
//
//    Matrix<int> m2(2,2,4);
//    m1.setRows(std::set<unsigned int> {1,2},m2);
//    std::cout << m1 << std::endl;

    double a1[] = {0,1,1,1,1,0};
    Matrix<double> A(a1,3,2);
    std::cout << "A: " << std::endl;
    std::cout << A << std::endl;
    Matrix<double> U,V;
    Vector<double> W;

    svd(A,U,W,V);

    std::cout << "U : " << U << std::endl;
    std::cout << "W : " << W << std::endl;
    std::cout << "V : " << V << std::endl;

    Matrix<double> S(DIAG,W,0,2,2);
    std::cout << "S : " << S << std::endl;

    std::cout << "Verification of SVD: " << std::endl;
    Matrix<double> A_svd = (dot_prod(dot_prod(U,S),t(V)));
    std::cout <<  A_svd  << std::endl;


    /**
     * Matrix initial Assignment
     */
    Matrix<int> B;
    B.resize(0,2,2);
    B[0][0] = 1;
    B[0][1] = 2;
    B[1][0] = 3;
    B[1][1] = 4;

    std::cout << B << std::endl;


    return 0;
}
