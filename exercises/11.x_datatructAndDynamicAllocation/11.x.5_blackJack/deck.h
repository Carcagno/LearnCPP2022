#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <array>


#include "card.h"

struct Deck
{
    std::array<Card, 52> s_cards{};
};

Deck createDeck();
void printDeck(const Deck& d);
void shuffleDeck(Deck &d);

#endif // DECK_H_INCLUDED
