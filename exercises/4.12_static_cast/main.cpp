#include <iostream>


int main()
{
    std::cout << "Enter a single character: ";

    char userChar{};
    std::cin >> userChar;

    std::cout << "You entered a \'" << userChar << "\', which has ASCII code " << static_cast<int>(userChar) << std::endl;

    return 0;
}
