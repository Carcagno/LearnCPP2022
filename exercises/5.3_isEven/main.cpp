#include <iostream>

int getInt()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;

    return x;

}

bool isEven(int x)
{
    return (x % 2 == 0);
}

int main()
{
    int userNumber{getInt()};

    if (isEven(userNumber))
        std::cout << userNumber << " is even";
    else
        std::cout << userNumber << " is odd";

    return 0;
}
