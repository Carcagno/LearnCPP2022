#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "creature.h"

class Player : public Creature
{
    protected:
    int m_playerLvl{1};

    public:
    Player(const std::string& name);

    int getPlayerLvl() const;
    bool hasWon() const;
    void levelUp();
};


#endif // PLAYER_H_INCLUDED
