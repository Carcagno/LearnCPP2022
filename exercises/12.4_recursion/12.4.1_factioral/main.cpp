#include <iostream>

int getFactorial(int nb)
{
    int res(nb);

    if (nb > 1)
        res *= getFactorial(--nb);

    return res;
}

int main()
{
    std::cout << getFactorial(7) << '\n';

    return 0;
}
