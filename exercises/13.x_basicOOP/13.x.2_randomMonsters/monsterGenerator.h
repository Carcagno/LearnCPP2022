#ifndef MONSTERGENERATOR_H_INCLUDED
#define MONSTERGENERATOR_H_INCLUDED

#include "monster.h"

class MonsterGenerator
{

    public:
    static Monster generateMonster();
    static int getRandomNumber(int min, int max);

};

#endif // MONSTERGENERATOR_H_INCLUDED
