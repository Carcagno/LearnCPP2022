#include <iostream>

double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";

    double height{};
    std::cin >> height;

    return height;
}

double calculateDropInMeter(int elapsedSeconds)
{
    constexpr double gravityConstant {9.8};

    return (gravityConstant * (elapsedSeconds * elapsedSeconds) / 2);
}

void printHeight(int elapsedSecond, double currentHeight)
{
    if (currentHeight > 0)
        std::cout << "At " << elapsedSecond << " seconds, the ball is at height: " << currentHeight << "\n";
    else
        std::cout << "At " << elapsedSecond << " seconds, the ball is on the ground \n";
}

int main()
{
    double height{getHeight()};
    int elapsedSecond{0};

    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;
    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;
    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;
    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;
    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;
    printHeight(elapsedSecond, height - calculateDropInMeter(elapsedSecond));
    elapsedSecond++;

    return 0;
}
