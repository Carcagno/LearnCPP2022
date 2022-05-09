#include "monster.h"
#include "monsterGenerator.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
