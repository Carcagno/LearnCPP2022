#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,

    MAX_RANK
};

enum Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,

    MAX_SUIT
};

struct Card
{
    Rank s_rank{};
    Suit s_suit{};
};

void printCard(const Card&);
int getCardValue(const Card& c);


#endif // CARD_H_INCLUDED
