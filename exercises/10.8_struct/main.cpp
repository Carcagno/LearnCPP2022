#include <iostream>
#include <limits>

struct Adv
{
    int shown {};
    double percentageClicked {};
    double avgGainFromClick {};
};

auto getValue()
{
    while (true)
    {
        std::cout << "Enter a value: ";

        auto userNumber {0};
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

double getDouble()
{
    while (true)
    {
        std::cout << "Enter a value: ";

        double userNumber {0};
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

void printAdv(Adv adv)
{
    std::cout << "Number of adds showns: " << adv.shown << '\n';
    std::cout << "Number of adds clicked on: " << adv.percentageClicked << '\n';
    std::cout << "Gain on a single click: " << adv.avgGainFromClick << '\n';

    std::cout << "Total gain: " << adv.shown * adv.percentageClicked * adv.avgGainFromClick << '\n';
}

int main()
{
    std::cout << "nbSHown, precentage clicked, avfGain:";
    Adv adv1 {getValue(), getDouble(), getDouble()};

    printAdv(adv1);

    return 0;
}
