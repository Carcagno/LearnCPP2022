#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "deck.h"

// Maximum score before losing.
constexpr int g_maximumScore{ 21 };
constexpr int g_minimumDealerScore{ 17 };

class Player
{
    int m_score{};

    public:
    Player();
    int drawCard(Deck& deck);
    bool isBust();
    int score();

};


#endif // PLAYER_H_INCLUDED
