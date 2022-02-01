#include <iostream>

int sumTo(int numberTo)
{
    int result {0};
    for (int i {1}; i <= numberTo; ++i)
        result += i;

    return result;
}

int main()
{
    for (int i = 0; i <= 20; ++i)
        std::cout << i << '\n';

    std::cout << "\n\n\n\n\n";

    std::cout << sumTo(5) << '\n';

    return 0;
}
