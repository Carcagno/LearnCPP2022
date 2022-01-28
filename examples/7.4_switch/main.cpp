#include <iostream>

void printDigitName(int x)
{
    switch (x)
    {
        case 1:
            std::cout << "One";
            break;
        case 2:
            std::cout << "Two";
            break;
        case 3:
            std::cout << "Three";
            break;
        case 4:
            std::cout << "Four";
            break;
        case 5:
            std::cout << "Five";
            break;
        default:
            std::cout << "Unknown";
            break;
    }

    std::cout << " Ah Ah Ah ! \n";
}

int main()
{
    printDigitName(3);
    printDigitName(9);

    return 0;
}
