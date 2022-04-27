#include <iostream>

void swap(int& a, int&b)
{
    int c{a};
    a = b;
    b = c;
}

int main()
{
    int a{11}, b{99};

    std::cout << "before:\na: " << a << "\nb: " << b << '\n';

    swap(a, b);

    std::cout << "\nafter:\na: " << a << "\nb: " << b << '\n';

    return 0;
}
