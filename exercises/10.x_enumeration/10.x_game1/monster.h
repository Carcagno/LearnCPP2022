#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <string>

struct Monster
{
    enum class MonsterType
    {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime,
        MonsterTypeMax
    };

    MonsterType type {MonsterType::orc};
    std::string name {"Unknown"};
    int health;
};

#endif // MONSTER_H_INCLUDED
