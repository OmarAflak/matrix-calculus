#include "../include/frac.h"

Frac::Frac(){
    m_num = 0;
    m_den = 1;
}

Frac::Frac(int num){
    m_num = num;
    m_den = 1;
}

Frac::Frac(int num, int den){
    assert(den!=0);
    m_num = num;
    m_den = den;
    simplify();
}

double Frac::value() const{
    return m_num/m_den;
}

void Frac::simplify(){
    int pgcd = 1;
    int c = m_num>m_den?m_num:m_den;
    for(int i=c ; i>=1 ; i--){
        if(m_num%i==0 && m_den%i==0){
            pgcd = i;
            break;
        }
    }

    if(pgcd>1){
        m_num /= pgcd;
        m_den /= pgcd;
    }
}

std::ostream& operator<<(std::ostream& os, const Frac& a){
    if(a.m_den==1){
        os << a.m_num;
    }
    else if(a.m_num%a.m_den==0){
        os << a.m_num/a.m_den;
    }
    else{
        os << a.m_num << "/" << a.m_den;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Frac& a){
    std::string word;
    is >> word;
    int pos = word.find("/");
    if(pos==-1){
        a.m_num = std::stoi(word);
        a.m_den = 1;
    }
    else{
        a.m_num = std::stoi(word.substr(0, pos));
        a.m_den = std::stoi(word.substr(pos+1));
    }
    return is;
}

Frac operator+(const Frac& a, const Frac& b){
    Frac f(a.m_num*b.m_den+b.m_num*a.m_den, a.m_den*b.m_den);
    f.simplify();
    return f;
}

Frac operator-(const Frac& a, const Frac& b){
    Frac f(a.m_num*b.m_den-b.m_num*a.m_den, a.m_den*b.m_den);
    f.simplify();
    return f;
}

Frac operator*(const Frac& a, const Frac& b){
    Frac f(a.m_num*b.m_num, a.m_den*b.m_den);
    f.simplify();
    return f;
}

Frac operator/(const Frac& a, const Frac& b){
    Frac f(a.m_num*b.m_den, a.m_den*b.m_num);
    f.simplify();
    return f;
}

Frac operator+=(Frac& a, const Frac& b){
    a = a + b;
    return a;
}

Frac operator-=(Frac& a, const Frac& b){
    a = a - b;
    return a;
}

Frac operator*=(Frac& a, const Frac& b){
    a = a * b;
    return a;
}

Frac operator/=(Frac& a, const Frac& b){
    a = a / b;
    return a;
}

Frac Frac::operator=(const int& n){
    m_num = n;
    m_den = 1;
    return *this;
}
