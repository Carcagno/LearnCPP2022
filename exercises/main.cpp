#include <iostream>

using namespace std;

int main()
{
    std::cout << "Enter an Integer: ";

    int firstUserInput{};
    std::cin >> firstUserInput;

    std::cout << "Enter another Integer: ";

    int secondUserInput{};
    std::cin >> secondUserInput;

    std::cout << firstUserInput << " + " << secondUserInput << " is " << firstUserInput + secondUserInput << ".\n";
    std::cout << firstUserInput << " - " << secondUserInput << " is " << firstUserInput - secondUserInput << std::endl;

    return 0;
}
