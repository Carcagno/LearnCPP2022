#include <array>

#include "monsterGenerator.h"

Monster MonsterGenerator::generateMonster()
{
    static std::array<std::string, 6> monsterNames{"Elmo", "Zorg"
        , "Zlurp", "Chichtu", "Purzok", "Shlappi"};
    static std::array<std::string, 6> monsterRoars{"Grrrrr", "SsSssSsSs"
        , "Frrrfrrrr", "AAAAAAAAAAAH", "wolololo", "pshhhhhhht"};

    return Monster(static_cast<Monster::Type>(getRandomNumber(0
        , static_cast<int>(Monster::Type::max_monster_types) - 1))
        , monsterNames[getRandomNumber(0, 5)]
        , monsterRoars[getRandomNumber(0, 5)]
        , getRandomNumber(1, 100));

}

int MonsterGenerator::getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}
