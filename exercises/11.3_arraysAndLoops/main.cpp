#include <iostream>

int getInt()
{
    while (true)
    {
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
    constexpr int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5};
    int arrayLength {std::size(array)};
    int userNbr {0};
    int indexUserNbr {-1};

    while (userNbr > 9 || userNbr < 1)
    {
        std::cout << "Enter a number between 1 and 9 included: ";
        userNbr = getInt();
    }

        for (int i = 0; i < arrayLength; ++i)
    {
        std::cout << array[i];
        if (array[i] == userNbr)
        {
            std::cout << " NUMBER FOUND";
            indexUserNbr = i;
        }

        std::cout << '\n';
    }

    std::cout << "User number " << userNbr << "is at the index: " << indexUserNbr << '\n';

    return 0;
}
