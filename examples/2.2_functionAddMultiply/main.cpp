#include <iostream>

int add(int a, int b)
{
    return (a + b);
}

int multiply(int a, int b)
{
    return (a + b);
}

int main()
{
    std::cout << add(3, 9) << '\n';
    std::cout << add(2+7, 9+4) << '\n';

    int a{5};
    std::cout << add(a, a) << '\n';

    std::cout << add(a, multiply(a, 4)) << '\n';
    std::cout << add(add(a, 89), multiply(multiply(2, 2), add(a, 4))) << '\n';
    return 0;
}
