#include <iostream>
#include <limits>

struct Fraction
{
    int numerator {};
    int denominator {1};
};


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

Fraction getFractionFromUser()
{
    return Fraction{getInt(), getInt()};
}

Fraction multiplyFractions(const Fraction &f1, const Fraction &f2)
{
    return Fraction {(f1.numerator * f2.numerator), (f1.denominator * f2.denominator)};
}

void printFraction(const Fraction &f)
{
    std::cout << f.numerator << '/' << f.denominator;
}

int main()
{
    Fraction f1{getFractionFromUser()}, f2{getFractionFromUser()};

    Fraction f3 {multiplyFractions(f1, f2)};

    printFraction(f1);
    std::cout << " * ";
    printFraction(f2);
    std::cout << " = ";
    printFraction(f3);

    return 0;
}
