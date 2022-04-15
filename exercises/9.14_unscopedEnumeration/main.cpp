#include <iostream>

namespace monsters
{
    enum MonsterType
    {
        orcs,
        goblins,
        trolls,
        ogres,
        skeletons,
        endMonsterType
    };
}

int main()
{
    monsters::MonsterType monsterType{monsters::trolls};

    std::cout << monsterType << std::endl;

    return 0;
}
