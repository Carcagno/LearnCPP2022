#include "io.h"

int readNumber()
{
    std::cout << "Enter an Integer: ";

    int userNumber{};
    std::cin >> userNumber;

    return userNumber;
}

void writeAnswer(int result)
{
    std::cout << result << "\n";
}
