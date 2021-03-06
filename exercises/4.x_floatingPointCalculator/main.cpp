#include <iostream>

double askDoubleToUser()
{
    std::cout << "Enter a double value: ";

    double d{};
    std::cin >> d;

    return d;
}

char askSignToUser()
{
    std::cout << "Enter one of the following sign: \'+\' \'-\' \'*\' \'/\': ";

    char sign{};
    std::cin >> sign;

    return sign;
}

bool isValidSign(char sign)
{
    if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
        return true;
    return false;
}

void printResult(double d1, double d2, char sign)
{
    if (sign == '+')
        std::cout << d1 << " + " << d2 << " = " << d1 + d2 << std::endl;
    if (sign == '-')
        std::cout << d1 << " - " << d2 << " = " << d1 - d2 << std::endl;
    if (sign == '*')
        std::cout << d1 << " * " << d2 << " = " << d1 * d2 << std::endl;
    if (sign == '/')
        std::cout << d1 << " / " << d2 << " = " << d1 / d2 << std::endl;
}

int main()
{
    double d1{askDoubleToUser()}, d2{askDoubleToUser()};
    char sign{askSignToUser()};

    if (!isValidSign(sign))
        return 1;

    printResult(d1, d2, sign);

    return 0;
}
