#include <iostream>
#include <limits>

int getInt()
{
    while (true)
    {
        std::cout << "Enter an int: ";

        int userNumber {0};
        std::cin >> userNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please, try again\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return userNumber;
        }
    }
}

int main()
{

    return 0;
}
