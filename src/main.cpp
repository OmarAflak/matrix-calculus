#include <iostream>
#include "../include/matrix.h"
#include "../include/utils.h"

int main(int argc, char const *argv[]) {
    if(argc >= 2){
        const char* filename = argv[1];
        Matrix matrix;
        if(matrix.load(filename)){
            std::cout << "A = " << std::endl;
            std::cout << matrix << std::endl;

            if(hasFlag("-d", argc, argv) || hasFlag("--det", argc, argv)){
                std::cout << std::endl << "det(A) = " << matrix.det() << std::endl;
            }
            if(hasFlag("-i", argc, argv) || hasFlag("--inverse", argc, argv)){
                std::cout << std::endl << "inv(A) = " << std::endl << matrix.inv() << std::endl;
            }
            if(hasFlag("-c", argc, argv) || hasFlag("--com", argc, argv)){
                std::cout << std::endl << "com(A) = " << std::endl << matrix.comatrix() << std::endl;
            }
            if(hasFlag("-t", argc, argv) || hasFlag("--transpose", argc, argv)){
                std::cout << std::endl << "transpose(A) = " << std::endl << matrix.transpose() << std::endl;
            }
        }
        else{
            std::cout << "could not read : " << filename << std::endl;
        }
    }
    else{
        std::cout << "syntax is : " << argv[0] << " <filename> [OPTIONS]" << std::endl;
        std::cout << "\t-d\t--det                  : determinant" << std::endl;
        std::cout << "\t-i\t--inverse              : inverse" << std::endl;
        std::cout << "\t-c\t--com                  : comatrix" << std::endl;
        std::cout << "\t-t\t--transpose            : transposed matrix" << std::endl;
    }
    return 0;
}
