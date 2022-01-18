#include <iostream>

int main()
{
    std::cout << "Enter an Integer: ";

    int userInteger{};
    std::cin >> userInteger;

    std::cout << "The double of that number is: " << userInteger * 2 << "\n";
    std::cout << "The triple of that number is: " << userInteger * 3 << std::endl;

    return 0;
}
