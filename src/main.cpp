#include <iostream>
#include "../include/matrix.h"
#include "../include/utils.h"

int main(int argc, char const *argv[]) {
    if(hasArg("-f", argc, argv)){
        std::string filename = getArg("-f", argc, argv);
        Matrix matrix;
        if(matrix.load(filename.c_str())){
            Matrix inverse = matrix.inv();
            std::cout << "A = " << std::endl;
            std::cout << matrix << std::endl;
            std::cout << std::endl;
            std::cout << "inv(A) = " << std::endl;
            std::cout << inverse << std::endl;
        }
        else{
            std::cout << "could not read : " << filename << std::endl;
        }
    }
    else{
        std::cout << "syntax is : " << argv[0] << " -f <filename>" << std::endl;
    }
    return 0;
}
