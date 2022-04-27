#include <iostream>
#include <array>
#include <numeric>

template <typename T>

int countTotalItems(T& inventory)
{
    return std::reduce(inventory.begin(), inventory.end());
}

int main()
{
    enum Items
    {
        potions,
        torchs,
        arrows,
        MAX_ITEMS
    };

    std::array inventory{2, 5, 10};

    std::cout << "Play has a total of " << countTotalItems(inventory) <<
        " items, and " << inventory[Items::torchs] << " are torchs !\n";

    return 0;
}
