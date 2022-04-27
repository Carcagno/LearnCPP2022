#include <iostream>
#include <limits>

#include "card.h"
#include "deck.h"
#include "player.h"

int getInt()
{
    while (true)
    {
        std::cout << "Enter an int: ";

        int userNumber {0};
        std::cin >> userNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please, try again\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return userNumber;
        }
    }
}

int PlayBlackJack(const Deck& deck)
{
    int currCard{0};
    Player player{0, false}, dealer{0, true};

    playPlayerTurn(player, deck, currCard);

    if (player.s_score > 21)
    {
        std::cout << "Player looses with a score of: " << player.s_score
            << '\n';
        return -21;
    }

    playPlayerTurn(dealer, deck, currCard);

    if (dealer.s_score > 21)
    {
        std::cout << "Player won.\nPlayer score: " << player.s_score
            << "\nDealer score: " << dealer.s_score << '\n';
        return 0;
    }
    else if (dealer.s_score < player.s_score)
    {
        std::cout << "Player won.\nPlayer score: " << player.s_score
            << "\nDealer score: " << dealer.s_score << '\n';
            return 0;
    }
    else if (dealer.s_score > player.s_score)
    {
        std::cout << "Dealer won.\nPlayer score: " << player.s_score
            << "\nDealer score: " << dealer.s_score << '\n';
        return 1;
    }
    else
    {
        std::cout << "Tie.\nPlayer score: " << player.s_score
            << "\nDealer score: " << dealer.s_score << '\n';
        return 2;
    }
}

int main()
{
    Deck d1{createDeck()};

    shuffleDeck(d1);

    PlayBlackJack(d1);

    return 0;
}
