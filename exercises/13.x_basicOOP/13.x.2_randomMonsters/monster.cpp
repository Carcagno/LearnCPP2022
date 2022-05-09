#include "monster.h"


Monster::Monster(const Type t, const std::string& name
    , const std::string& roar, const int hp)
    : m_type{t}, m_name{name}, m_roar{roar}, m_hp{hp}
{}

std::string_view Monster::getTypeString() const
{
    switch (m_type)
    {
        case Type::dragon:
            return "dragon";
        case Type::goblin:
            return "goblin";
        case Type::ogre:
            return "ogre";
        case Type::orc:
            return "orc";
        case Type::skeleton:
            return "skeleton";
        case Type::troll:
            return "troll";
        case Type::vampire:
            return "vampire";
        case Type::zombie:
            return "zombie";
        default:
            return "unknown";
    }
}

void Monster::print() const
{
    std::cout << m_name << " the " << getTypeString()
        << " has " << m_hp << "hp & says " << m_roar << '\n';
}
