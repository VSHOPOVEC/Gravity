#include "Matrix_test.h"
#include <vector>
#include <chrono>
#include <random>

typedef std::vector<std::vector<double>> double_vector;
typedef Matrix<double> dMatrix;

template <typename T>
Matrix<T> generateRandomMatrix(size_t n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(-100.0, 100.0); // Диапазон случайных чисел

    std::vector<std::vector<T>> randomMatrix(n, std::vector<T>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            randomMatrix[i][j] = dis(gen);
        }
    }

    return Matrix<T>(randomMatrix);
}


int main(){

    size_t size = 30;

    Matrix temp = generateRandomMatrix<double>(size);

    auto b = std::chrono::high_resolution_clock::now();
    auto d = temp.InverseMatrix();
    auto e = std::chrono::high_resolution_clock::now();

    auto b1 = std::chrono::high_resolution_clock::now();
    auto n = temp.InverseMatrix_2();
    auto e1 = std::chrono::high_resolution_clock::now();


    auto p = std::chrono::duration_cast<std::chrono::microseconds>(t);
    auto p1 = std::chrono::duration_cast<std::chrono::microseconds>(t1);

    std::cout << p.count() << std::endl;
    std::cout << p1.count() << std::endl;
    return 0;
}
