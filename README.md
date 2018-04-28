# Matrix Calculus

Implementation of some maths formulas.

# Dowload & Compile

```
git clone https://github.com/OmarAflak/matrix-calculus.git
cd matrix-calculus
make
```

# Sample

```c++
Matrix matrix;
if(matrix.load("data/mat")){
    Matrix inverse = matrix.inv();
    std::cout << "M = " << std::endl;
    std::cout << matrix << std::endl;
    std::cout << std::endl;
    std::cout << "inv(M) = " << std::endl;
    std::cout << inverse << std::endl;
}
```
