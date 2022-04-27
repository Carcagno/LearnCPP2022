#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "deck.h"
#include "card.h"

struct Player
{
    int s_score{};
    bool s_isDealer{};
};

void playPlayerTurn(Player &p, const Deck &deck, int &currCard);
void giveACard(Player &p, const Deck &deck, int &currCard);

#endif // PLAYER_H_INCLUDED
