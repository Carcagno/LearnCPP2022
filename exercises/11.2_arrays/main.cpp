#include <iostream>

namespace animals
{
    enum animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };
};

int main()
{
    double temperatures[365] {};

    int animalsLegs[animals::max_animals] {2, 4, 4, 4, 2, 0};

    std::cout << "An elephant has " << animalsLegs[animals::elephant] << " legs !\n";

    return 0;
}
