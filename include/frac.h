#ifndef FRAC
#define FRAC

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

class Frac {
    private:
        int m_num;
        int m_den;

    public:
        Frac();
        Frac(int num);
        Frac(int num, int den);

        double value() const;
        void simplify();

        friend std::ostream& operator<<(std::ostream& os, const Frac& a);
        friend std::istream& operator>>(std::istream& is, Frac& a);
        
        friend Frac operator+(const Frac& a, const Frac& b);
        friend Frac operator-(const Frac& a, const Frac& b);
        friend Frac operator*(const Frac& a, const Frac& b);
        friend Frac operator/(const Frac& a, const Frac& b);

        Frac operator=(const int& n);
};

Frac operator+=(Frac& a, const Frac& b);
Frac operator-=(Frac& a, const Frac& b);
Frac operator*=(Frac& a, const Frac& b);
Frac operator/=(Frac& a, const Frac& b);

#endif
