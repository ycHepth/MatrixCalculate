//
// Created by azurec on 2020/9/12.
//
#include "Matrix.h"


Matrix<double> EyeMatrix(const unsigned int n, const unsigned int m) {
    Matrix<double> E;
    E.resize(n,m);
    E = Matrix(DIAG,1.0,0.0,n,m);
    return E;
}

Matrix<double> ZeroMatrix(const unsigned int n, const unsigned int m){
    Matrix<double> T;
    T.resize(n,m);
    T = Matrix(DIAG,0.0,0.0,n,m);
    return T;
}

Matrix<double> transposeVector(const Vector<double> &v){
    unsigned int rows = v.size();
    Matrix<double> T = Matrix(TRANS,v,0.0,1,rows);
    return T;
}

Matrix<double> exp(const Matrix<double>&m, unsigned int n){
    if(m.nrows() != m.ncols()) {
        std::cout << "Matrix is not squared. can not be powered." << std::endl;
        return m;
    }
    Matrix<double> tmp(m.nrows(), m.ncols());
    if (n == 0) {
        tmp = EyeMatrix(m.nrows(), m.ncols());
        return tmp;
    }
    tmp = m;
    for (int j = 1; j < n; j++)
        tmp = dot_prod(m,tmp);
    return tmp;
}

std::vector<Matrix<double>> get_powers(const Matrix<double> a, int n){
    std::vector<Matrix<double>> res;

    if(a.nrows() != a.ncols()) {
        std::cout << "Matrix is not squared. can not be powered." << std::endl;
        return res;
    }

    // A^0 = I
    res.push_back(EyeMatrix(a.nrows(),a.ncols()));
    // A^1 = A
    res.push_back(a);

    for (int j = 2; j<=n; j++)
        res.push_back(dot_prod(res[j-1],a));
    return res;
}

void extend_matrix(Matrix<double> &m, unsigned int r, unsigned int c){
    if(r<m.nrows() || c<m.ncols()) {
        std::cout << "can not extend matrix since the modified matrix will less than original." << std::endl;
        return;
    }
    unsigned int old_rows = m.nrows();
    unsigned int old_cols = m.ncols();
    Matrix<double> tmp;
    tmp = m;
    m.resize(0,r,c);
    m.range_set({0,old_rows-1},{0,old_cols-1},tmp);
}

void set_subvector(Vector<double> &a, const Vector<double> &b, unsigned int pos){
    for (int i = pos; i < pos+b.size();i++)
        a[i] = b[i-pos];
}

void extend_vector(Vector<double> &v, int n) {
    if (n < v.size()){
        std::cout << "can not extend vector since the modified vector will less than original." << std::endl;
        return;
    }
    Vector<double> tmp = v;
    v.resize(0,n);
    set_subvector(v,tmp,0);
}

Matrix<double> bind_matrices(const Matrix<double> &a, const Matrix<double> &b) {
    Matrix<double> m;
    if (a.ncols() != b.ncols()) {
        std::cout << "first matrix ncols : " << a.ncols() << std::endl;
        std::cout << "second matrix ncols : " << b.ncols() << std::endl;
        std::cerr << "Cannot bind matrices. Mismatching column number\n";
    }
    else {
        m = a;
        extend_matrix(m, a.nrows() + b.nrows(), a.ncols());
        set_submatrix(m,b,a.nrows(),0);
    }
    return m;
}


void set_submatrix(Matrix<double> &dst, const Matrix<double> &src, int row, int col) {
    int i, j;
    for (i = row; i < row + src.nrows(); i++) {
        for (j = col; j < col + src.ncols(); j++) {
            dst[i][j] = src[i - row][j - col];
        }
    }
}

Vector<double> bind_vectors(const Vector<double> &a, const Vector<double> &b) {
    Vector<double> v;
    v = a;
    extend_vector(v, a.size() + b.size());
    set_subvector(v, b, a.size());
    return v;
}
