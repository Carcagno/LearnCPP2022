#include "player.h"

Player::Player() : m_score{0}
{

}

int Player::drawCard(Deck& deck)
{
    return (m_score += deck.dealCard().value());
}

bool Player::isBust()
{
    return (m_score < g_maximumScore);
}

int Player::score()
{
    return m_score;
}
