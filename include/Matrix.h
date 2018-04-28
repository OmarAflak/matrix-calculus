#ifndef MATRIX
#define MATRIX

#include "Frac.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

class Matrix {
    private:
        int m_height;
        int m_width;
        std::vector<std::vector<Frac> > m_mat;

    public:
        Matrix();
        Matrix(int height, int width);

        int getHeight() const;
        int getWidth() const;

        Frac det() const;
        Matrix subMatrix(int h, int w) const;
        Matrix transpose() const;
        Matrix comatrix() const;
        Matrix inv() const;

        bool load(const char* filename);
        bool save(const char* filename) const;

        void print(std::ostream& os) const;
};

std::string operator*(const std::string& str, const int& n);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif
