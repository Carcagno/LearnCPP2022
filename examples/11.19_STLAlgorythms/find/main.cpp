#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array arr{13, 90, 99, 5, 40, 80};

    std::cout << "Enter a value to search fo and replace with: ";
    int search{};
    int replace{};

    std::cin >> search >> replace;

    auto found{std::find(arr.begin(), arr.end(), search)};

    if (found == arr.end())
        std::cout << "Could not find " << search << '\n';
    else
    {
        std::cout << "Replaced " << *found;
        *found = replace;
        std::cout << " with " << *found << '\n';
    }

    for (int i : arr)
        std::cout << i << ' ';

    std::cout << std::endl;

    return 0;
}
