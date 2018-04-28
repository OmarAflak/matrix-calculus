#include <iostream>
#include "../include/Matrix.h"

int main(int argc, char const *argv[]) {
    Matrix matrix;
    if(matrix.load("data/mat")){
        Matrix inverse = matrix.inv();
        std::cout << "A = " << std::endl;
        std::cout << matrix << std::endl;
        std::cout << std::endl;
        std::cout << "inv(A) = " << std::endl;
        std::cout << inverse << std::endl;
    }
    return 0;
}
