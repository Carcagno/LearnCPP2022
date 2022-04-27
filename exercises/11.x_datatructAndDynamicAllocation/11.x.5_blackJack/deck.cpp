#include "deck.h"

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>

Deck createDeck()
{
    Deck d{};
    int i{0};

    for (int iteratorSuit{0};
     iteratorSuit < Suit::MAX_SUIT; iteratorSuit += 1)
    {
        for (int iteratorRank{0};
         iteratorRank < Rank::MAX_RANK; ++iteratorRank)
        {
            d.s_cards[i].s_rank = static_cast<Rank>(iteratorRank);
            d.s_cards[i].s_suit = static_cast<Suit>(iteratorSuit);
            ++i;
        }
    }

    return d;
}

void printDeck(const Deck &d)
{
    for (Card c : d.s_cards)
    {
        printCard(c);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(Deck &d)
{
    static std::mt19937 mt
    {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(d.s_cards.begin(), d.s_cards.end(), mt);
}
