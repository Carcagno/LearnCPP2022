#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "creature.h"

#include <array>
#include <iostream>
#include <random>

class Monster : public Creature
{
    public:
    enum class Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPE
    };

    static Monster getRandomMonster()
    {
      	static std::random_device rd;
        static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
        static std::mt19937 mt{ ss };

        static std::uniform_int_distribution monsterType{ 0
            , static_cast<int>(Type::MAX_TYPE) - 1 };

        return (Monster {static_cast<Type>(monsterType(mt))});
    }


    private:
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature
        , static_cast<std::size_t>(Type::MAX_TYPE)> monsterData
        {
            {
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

    public:
    Monster(const Type type);
};

#endif // MONSTER_H_INCLUDED
