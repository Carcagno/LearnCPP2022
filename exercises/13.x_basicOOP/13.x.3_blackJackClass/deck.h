#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "card.h"

#include <array>
#include <random>
#include <ctime>
#include <algorithm> // std::shuffle


class Deck
{
    std::array<Card, 52> m_deck{};
    int m_cardIndex{};
public:
    Deck();
    void print() const;
    void shuffle();
    const Card& dealCard();
};

#endif // DECK_H_INCLUDED
