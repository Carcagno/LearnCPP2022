#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <string>

class Creature
{
    protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{}, m_dmg{}, m_gold{};

    public:
    Creature(const std::string& name = "Unknown", const char symbol = 'X'
        , const int health = 1, const int dmg = 1, const int gold = 1);

    const std::string& getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getDmg() const;
    int getGold() const;

    void reduceHealth(int amount);
    bool isDead() const;
    void addGold(int amount);
};

#endif // CREATURE_H_INCLUDED
