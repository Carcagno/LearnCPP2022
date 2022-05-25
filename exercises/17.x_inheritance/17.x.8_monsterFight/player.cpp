#include "player.h"

Player::Player(const std::string& name)
    : Creature{name, '@', 10, 1, 0}
    , m_playerLvl{1}
{
}

int Player::getPlayerLvl() const

{
    return m_playerLvl;
}

bool Player::hasWon() const
{
    return (m_playerLvl >= 20);
}

void Player::levelUp()
{
    ++m_playerLvl;
    ++m_dmg;
}
