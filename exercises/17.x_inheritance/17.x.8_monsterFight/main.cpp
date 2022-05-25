#include "monster.h"
#include "player.h"
#include "creature.h"

#include <iostream>
#include <string>
#include <random>

void test()
{
    //TEST creature
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

	//TEST player
    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    Player player{name};
    std::cout << "Welcome, " << player.getName() << ".\n";
    std::cout << "You have " << player.getHealth() << " health and are carrying "
        << player.getGold() << " gold.\n";


    //TEST monster
    Monster m{ Monster::Type::ORC };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";


	//TEST randomMonster
	for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "A " << m.getName() << " ("
            << m.getSymbol() << ") was created.\n";
	}
}

std::string getPlayerName()
{
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

namespace Random // capital R to avoid conflicts with functions named random()
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
		return die(mt); // and then generate a random number from our global generator
	}
}

bool playMonsterTurn(Player& player, const Monster& monster)
{
    std::cout << "The " << monster.getName() << " hit you for "
        << monster.getDmg() << " damage\n";

    player.reduceHealth(monster.getDmg());
    return (player.isDead());
}

bool playPlayerTurn(const Player& player, Monster& monster)
{
    std::cout << "You hit the " << monster.getName() << " for "
        << player.getDmg() << " damage\n";

    monster.reduceHealth(player.getDmg());
    return (monster.isDead());
}

bool combat(Player& player, Monster& monster)
{
    bool isCombatEnded{false};

    do
    {
        std::cout << "(R)un or (F)ight ?: ";
        std::string decision{};
        std::getline(std::cin >> std::ws, decision);

        if (decision == "r" || decision == "R")
        {
            if (Random::get(0, 1))
            {
                std::cout << "You failed to flee\n";
                if (playMonsterTurn(player, monster))
                    return true;
            }
            else
            {
                std::cout << "You successfully fled\n";
                isCombatEnded = true;
            }
        }
        else if (decision == "f" || decision == "F")
        {
            if (playPlayerTurn(player, monster))
                return false;
            if (playMonsterTurn(player, monster))
                return true;
        }
        else
            std::cout << "Bad input!\n";
    } while (!(isCombatEnded));

    return false;
}

int main()
{
    Player player{getPlayerName()};

    std::cout << "Welcome, " << player.getName() << ".\n";

    while (!(player.isDead()) && !(player.hasWon()))
    {
        Monster m{ Monster::getRandomMonster() };

        std::cout << "You encountered a " << m.getName() << " ("
            << m.getSymbol() << ")\n";
        if (combat(player, m))
        {
            std::cout << "You died at level " << player.getPlayerLvl()
                << " and with " << player.getGold() << " gold(s)."
                << "\nToo bad you can't take it with you!\n";
        }
        else
        {
            if (m.isDead())
            {
                std::cout << "You killed the " << m.getName() << '\n';
                player.levelUp();
                std::cout << "You are now level " << player.getPlayerLvl() << '\n';
                std::cout << "You found " << m.getGold() << " golds\n";

                player.addGold(m.getGold());

                if (player.hasWon())
                    std::cout << "You won !\n";
            }
        }
    }
	return 0;
}
