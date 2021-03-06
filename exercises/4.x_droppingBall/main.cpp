#include "constants.h"

#include <iostream>
#include <limits>

double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    while (true)
    {
        double userNumber {.0};
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

double calculateDropInMeter(int elapsedSeconds)
{
    return ( myConstants::gravityConstant * (elapsedSeconds * elapsedSeconds) / 2);
}

void printHeight(int elapsedSecond, double currentHeight)
{
    if (currentHeight > .0)
        std::cout << "At " << elapsedSecond << " seconds, the ball is at height: " << currentHeight << "\n";
    else
        std::cout << "At " << elapsedSecond << " seconds, the ball is on the ground \n";
}

int main()
{
    double height{getHeight()};
    int elapsedSecond{0};
    double dropInMeter {calculateDropInMeter(elapsedSecond)};

    while ((height - dropInMeter) > .0)
    {
        printHeight(elapsedSecond, height - dropInMeter);
        elapsedSecond++;
        dropInMeter = calculateDropInMeter(elapsedSecond);
    }

    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));

    return 0;
}
