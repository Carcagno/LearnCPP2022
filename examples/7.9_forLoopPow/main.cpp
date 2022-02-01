#include <iostream>

int pow(int base, int exponent) // risks of overflow here
{
    int total {1};

    for (int count{0}; count < exponent; ++count)
        total *= base;

    return total;
}

int main()
{
    std::cout << pow(4, 4) << std::endl;
    return 0;
}
