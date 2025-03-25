#ifndef FUNCMATRIX_H
#define FUNCMATRIX_H
#include "dMatrix.h"
#endif // FUNCMATRIX_H



class FuncMatrix:public Matrix<std::function<double(double)>>{
public:
    FuncMatrix(std::vector<std::function<double(double)>>, size_t rows, size_t columns);
    FuncMatrix(std::vector<double (*)(double)>, size_t rows, size_t columns);
    Matrix<double> operator() (double t);
private:
    std::vector<std::function<double(double)>> func_vector;
};

FuncMatrix::FuncMatrix(std::vector<std::function<double(double)>>, size_t rows, size_t columns){

}
