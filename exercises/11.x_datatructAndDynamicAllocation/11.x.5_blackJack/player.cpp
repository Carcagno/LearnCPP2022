#include "player.h"

#include <string>
#include <iostream>

void giveACard(Player &p, const Deck &deck, int &currCard)
{
    p.s_score += getCardValue(deck.s_cards[currCard]);
    currCard++;
}

void playPlayerTurn(Player &p, const Deck &deck, int &currCard)
{
    std::string choice{};

    giveACard(p, deck, currCard);

    if (p.s_isDealer)
    {
        giveACard(p, deck, currCard);
        while (p.s_score < 17)
        {
            giveACard(p, deck, currCard);
        }
    }
    else
    {
        giveACard(p, deck, currCard);
        do
        {
            do
            {
                choice = "";
                std::cout << "Your cards have a score of " << p.s_score
                    << "\nhit or stand ?";
                std::getline(std::cin >> std::ws, choice);
            } while (choice != "hit" && choice != "stand");
            if (choice == "hit")
                giveACard(p, deck, currCard);
        } while (choice != "stand" && p.s_score < 22);
    }
}
