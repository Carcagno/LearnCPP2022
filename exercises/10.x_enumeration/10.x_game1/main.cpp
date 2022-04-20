#include <iostream>
#include <limits>
#include <string_view>

#include "monster.h"

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

std::string getMonsterType(const Monster &m)
{
    switch (m.type)
    {
    case Monster::MonsterType::dragon:
        return "Dragon";
        break;
    case Monster::MonsterType::giantSpider:
        return "Giant spider";
        break;
    case Monster::MonsterType::ogre:
        return "Ogre";
        break;
    case Monster::MonsterType::orc:
        return "Orc";
        break;
    case Monster::MonsterType::slime:
        return "Slime";
        break;
    default:
        return "Error_Unknown_MonsterType";
    }
}

void printMonster(const Monster &m)
{
    std::cout << "This " << getMonsterType(m) << " is named " << m.name << " and has " << m.health << " health.\n";
}

int main()
{
    Monster m1 {Monster::MonsterType::ogre, "Torg", 145}, m2 {Monster::MonsterType::slime, "Blurp", 23};

    printMonster(m1);
    printMonster(m2);

    return 0;
}
