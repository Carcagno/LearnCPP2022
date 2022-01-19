#include <iostream>

int doubleNumber(int number)
{
    return (number * 2);
}

int askUserNumber()
{
    std::cout << "Enter a number to be doubled: ";

    int userNumber{};
    std::cin >> userNumber;

    return userNumber;
}

void printNumber(int number)
{
    std::cout << number << '\n';
}

int main()
{
    printNumber(doubleNumber(askUserNumber()));
    return 0;
}
