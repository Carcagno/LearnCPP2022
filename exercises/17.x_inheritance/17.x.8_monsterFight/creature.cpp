#include "creature.h"

Creature::Creature(const std::string& name, const char symbol
     , const int health, const int dmg, const int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}
        , m_dmg{dmg}, m_gold{gold}
{
}

const std::string& Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getDmg() const
{
    return m_dmg;
}

int Creature::getGold() const
{
    return m_gold;
}

void Creature::reduceHealth(int amount)
{
    m_health -= amount;
}

bool Creature::isDead() const
{
    return m_health <= 0;
}

void Creature::addGold(int amount)
{
    m_gold += amount;
}
