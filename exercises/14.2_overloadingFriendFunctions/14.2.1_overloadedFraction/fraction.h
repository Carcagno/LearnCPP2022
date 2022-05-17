#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>
#include <string>
#include <numeric>

class Fraction
{
    int m_numerator{}, m_denominator{1};

    void reduce();

    public:
    Fraction(int numerator = 0, int denominator = 1);
    void print();

    friend Fraction operator*(const Fraction& f1, const Fraction&  f2);
};


#endif // FRACTION_H_INCLUDED
