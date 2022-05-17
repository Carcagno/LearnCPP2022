#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
    : m_numerator{numerator}, m_denominator{denominator}
{
    reduce();
}


void Fraction::print()
{
    std::cout << m_numerator << '/' << m_denominator << '\n';
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return (Fraction{(f1.m_numerator * f2.m_numerator)
        , (f1.m_denominator * f2.m_denominator)});
}

void Fraction::reduce()
{
    int gcd{std::gcd(m_numerator, m_denominator)};

    if (gcd)
    {
        m_numerator /= gcd;
        m_denominator /= gcd;
    }
}
