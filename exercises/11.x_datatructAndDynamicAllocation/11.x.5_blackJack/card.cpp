#include "card.h"

#include <string>
#include <iostream>
#include <array>

void printCard(const Card& card)
{
    std::string suits{"CDHS"}, ranks{"23456789TJQKA"};

    std::cout << ranks[card.s_rank] << suits[card.s_suit];
}

int getCardValue(const Card& c)
{
    std::array cardValues{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    return cardValues[static_cast<int>(c.s_rank)];
}
