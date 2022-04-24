#include <iostream>
#include <algorithm>

int main()
{
    int numberOfNames{};
    std::string* names{nullptr};

    std::cout << "Enter the number of names you wish to enter: ";
    std::cin >> numberOfNames;

    std::cout << "You choose to enter " << numberOfNames << " names:\n";
    names = new std::string[numberOfNames] {};
    for (int i = 0; i < numberOfNames; ++i)
    {
        std::cout << '#' << i+1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + numberOfNames);

    std::cout << "List sorted: \n";

    for (int j = 0; j < numberOfNames; ++j)
    {
        std::cout << '#' << j+1 << ": " << names[j] << '\n';
    }

    delete[] names;

    return 0;
}
