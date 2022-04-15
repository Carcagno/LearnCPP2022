#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
    maxAnimal
};

constexpr std::string_view getAnimalName(Animal a)
{
    switch (a)
    {
    case Animal::pig:
        return "Pig";
        break;
    case Animal::chicken:
        return "Chicken";
        break;
    case Animal::goat:
        return "Goat";
        break;
    case Animal::cat:
        return "Cat";
        break;
    case Animal::dog:
        return "Dog";
        break;
    case Animal::duck:
        return "Duck";
        break;
    default:
        std::cerr << "Unknown Animal ";
        return "";
    }
}

void printNumberOfLegs(Animal a)
{
    switch (a)
    {
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:
        std::cout << "A " << getAnimalName(a) << " has 4 legs.\n";
        break;
    case Animal::chicken:
    case Animal::duck:
        std::cout << "A " << getAnimalName(a) << " has 2 legs.\n";
        break;
    default:
        std::cerr << "Unknown Animal ";
    }
}

int main()
{
    Animal a{Animal::cat};
    Animal b{Animal::chicken};

    printNumberOfLegs(a);
    printNumberOfLegs(b);

    return 0;
}
