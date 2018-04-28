#include "../include/Matrix.h"

Matrix::Matrix(){
    m_height = 0;
    m_width = 0;
}

Matrix::Matrix(int height, int width){
    m_height = height;
    m_width = width;
    m_mat = std::vector<std::vector<Frac> >(height, std::vector<Frac>(width));
}

int Matrix::getHeight() const{
    return m_height;
}

int Matrix::getWidth() const{
    return m_width;
}

Matrix Matrix::subMatrix(int h, int w) const{
    assert(m_height>1 && m_width>1);
    Matrix submatrix(m_height-1, m_width-1);

    for(int i=0 ; i<m_height ; i++){
        for(int j=0 ; j<m_width ; j++){
            if(i!=h && j!=w){
                submatrix.m_mat[i<h?i:i-1][j<w?j:j-1] = m_mat[i][j];
            }
        }
    }
    return submatrix;
}

Frac Matrix::det() const{
    assert(m_height==m_width && m_height>0);

    if(m_height==1){
        return m_mat[0][0];
    }

    Frac d = 0;
    for(int i=0 ; i<m_height ; i++){
        Matrix tmp = subMatrix(i, 0);
        d += pow(-1, i)*m_mat[i][0]*tmp.det();
    }

    return d;
}

Matrix Matrix::transpose() const{
    Matrix matrix(m_width, m_height);
    for(int i=0 ; i<m_height ; i++){
        for(int j=0 ; j<m_width ; j++){
            matrix.m_mat[j][i] = m_mat[i][j];
        }
    }
    return matrix;
}

Matrix Matrix::comatrix() const{
    Matrix matrix(m_height, m_width);
    for(int i=0 ; i<m_height ; i++){
        for(int j=0 ; j<m_width ; j++){
            matrix.m_mat[i][j] = pow(-1, i+j)*subMatrix(i, j).det();
        }
    }
    return matrix;
}

Matrix Matrix::inv() const{
    Frac d = det();
    Matrix tcom = comatrix().transpose();
    for(int i=0 ; i<m_height ; i++){
        for(int j=0 ; j<m_width ; j++){
            tcom.m_mat[i][j] /= d;
        }
    }
    return tcom;
}

bool Matrix::load(const char* filename){
    std::ifstream file(filename);
    if(file){
        std::string line;
        getline(file, line);
        m_height = std::stoi(line);
        getline(file, line);
        m_width = std::stoi(line);

        m_mat = std::vector<std::vector<Frac> >(m_height, std::vector<Frac>(m_width));
        for(int i=0 ; i<m_height ; i++){
            getline(file, line);
            std::stringstream ss(line);
            for(int j=0 ; j<m_width ; j++){
                ss >> m_mat[i][j];
            }
        }

        file.close();
        return true;
    }
    return false;
}

bool Matrix::save(const char* filename) const{
    std::ofstream file(filename);
    if(file){
        file << m_height << std::endl;
        file << m_width << std::endl;

        for(int i=0 ; i<m_height ; i++){
            for(int j=0 ; j<m_width ; j++){
                file << m_mat[i][j] << " ";
            }
            file << std::endl;
        }

        file.close();
        return true;
    }
    return false;
}

void Matrix::print(std::ostream& os) const{
    int max = 0;
    for(int i=0 ; i<m_height ; i++){
        for(int j=0 ; j<m_width ; j++){
            std::stringstream ss;
            ss << m_mat[i][j];
            int tmp = ss.str().size();
            if(tmp>max){
                max = tmp;
            }
        }
    }

    int spaces = 4;
    std::string str = " ";
    for(int i=0 ; i<m_height ; i++){
        os << "[ ";
        for(int j=0 ; j<m_width ; j++){
            std::stringstream ss;
            ss << m_mat[i][j];
            int tmp = ss.str().size();

            os << m_mat[i][j];
            os << str*(j<m_width-1?max-tmp+spaces:max-tmp);
        }
        os << "]";
        if(i<m_height-1){
            os << std::endl;
        }
    }
}

std::string operator*(const std::string& str, const int& n){
    std::stringstream ss;
    for(int i=0 ; i<n ; i++){
        ss << " ";
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    matrix.print(os);
    return os;
}
