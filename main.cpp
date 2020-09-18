#include <iostream>
#include <vector>
#include "laguerre.h"
#include "extmodel.h"

void MatrixGenerateTest(){
    std::set<unsigned int> index;
    index = {0,1};

    int a[3] = {1,2,3};

    Vector<int> first(a,3);
    Vector<int> second;
    second = first + 2;
//    second(a,3);
    std::cout << "first" << std::endl;
    std::cout << first << std::endl;

//    second.set(a,3);
    std::cout << "second" << std::endl;
    std::cout << second << std::endl;

    Vector<int> third = second.extract(index);
    std::cout << "third" << std::endl;
    std::cout << third << std::endl;

    double ele[] = {1,4,9};
    Vector<double> fourth(ele,3);
    std::cout << "fourth" << std::endl;
    std::cout << fourth << std::endl;

    std::cout << sqrt(fourth) << std::endl;

//    Matrix
    Matrix<int> m1(1,3,4);
    std::cout << m1 << std::endl;

    Matrix<int> m2(2,2,4);
    m1.setRows(std::set<unsigned int> {1,2},m2);
    std::cout << m1 << std::endl;

    /**
 * Matrix initial Assignment
 */
    Matrix<int> B;
    B.resize(0,2,2);
    B[0][0] = 1;
    B[0][1] = 2;
    B[1][0] = 3;
    B[1][1] = 4;

}

void SVDTest(){
    /**
     *  SVD verification
     */
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

}

void laguerreTest(){
    /**
     * Laguerre Network verification
     */
    Matrix<double> lag_A;
    Vector<double> lag_l0;

    laguerre(0.8,5,lag_A,lag_l0);
    std::cout << "laguerre A: " << std::endl;
    std::cout << lag_A << std::endl;
    std::cout << "laguerre L0: " << std::endl;
    std::cout << lag_l0 << std::endl;


    /**
     * Below test independent with Laguerre construction.
     * return rows and cols of given matrix in-place
     */
    unsigned int rows, cols;
    lag_A.size(rows,cols);
    std::cout << rows << std::endl;
    std::cout << cols << std::endl;

    Matrix<double> sub_A(1,6,6);
    std::cout << sub_A << std::endl;

    std::vector<unsigned int> r_index = {0,rows-1};
    std::vector<unsigned int> c_index = {0,cols-1};

    sub_A.range_set({1,rows},c_index,lag_A);
    std::cout << sub_A << std::endl;
}

void AugmentedSystemTest(){
    /**
 * augmented system generation verified.
 * Notice: the index differ from MATLAB since the construction of std::vector
 */
    Matrix<double> Ap,Bp,Cp,Ae,Be,Ce;
    Ap.resize(0,2,2);
    Bp.resize(0,2,1);
    Cp.resize(0,1,2);

    Ap[0][0] = 0.8988;
    Ap[0][1] = -0.8605;
    Ap[1][0] = 0.0956;
    Ap[1][1] = 0.9562;
    Bp[0][0] = 0.0956;
    Bp[1][0] = 0.0049;
    Cp[0][0] = 0;
    Cp[0][1] = 1;

    std::cout << Ap << std::endl;
    std::cout << Bp << std::endl;
    std::cout << Cp << std::endl;

    augmented(Ap,Bp,Cp,Ae,Be,Ce);

    std::cout << Ae << std::endl;
    std::cout << Be << std::endl;
    std::cout << Ce << std::endl;

}

void transVectorTest(){
    Matrix<double> T;
    double ele[] = {1,4,9};
    Vector<double> V(ele,3);
    std::cout << "before transpose: " << std::endl;
    std::cout << V << std::endl;

    std::cout << "after transpose: " << std::endl;
    std::cout <<  transposeVector(V) << std::endl;
}

void N_expTest(unsigned int N){
    auto T = Matrix(2.0,2,2);
//    std::cout << T << std::endl;
//    std::cout << dot_prod(T,T) << std::endl;
    std::cout << exp(T,N) << std::endl;
}

void dmpcTest(){

}

int main() {

//    MatrixGenerateTest();
//    SVDTest();
//    laguerreTest();
//    AugmentedSystemTest();
//    N_expTest(5);


    Vector<double> A;
    A.resize(2,4);
    std::cout << A << std::endl;
    Matrix<double> m;
    m = Matrix(TRANS,A,0.0,A.size(),1);
    std::cout << m << std::endl;


    return 0;
}
