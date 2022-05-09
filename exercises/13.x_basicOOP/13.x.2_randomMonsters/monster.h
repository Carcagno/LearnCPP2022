#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <iostream>
#include <string>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };
  Type m_type{};
  std::string m_name{}, m_roar;
  int m_hp;

  std::string_view getTypeString() const;

  public:

    Monster(const Type t = Type::orc, const std::string& name = "Unknown"
    , const std::string& roar = "Grrr", const int hp = 100);
    void print() const;
};

#endif // MONSTER_H_INCLUDED
