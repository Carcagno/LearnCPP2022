#include <iostream>

#include "fraction.h"

int main()
{
    Fraction fraction {2, 4};

    std::cout << fraction.numerator << "/" << fraction.denominator << '\n';

    return 0;
}
