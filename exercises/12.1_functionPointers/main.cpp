#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<double(double, double)>;

double add(double d1, double d2)
{
    return (d1 + d2);
}

double sub(double d1, double d2)
{
    return (d1 - d2);
}

double mult(double d1, double d2)
{
    return (d1 * d2);
}

double divide(double d1, double d2)
{
    return (d1 / d2);
}

ArithmeticFunction getArithmeticFunction(const char &sign)
{
    if (sign == '+')
        return add;
    else if (sign == '-')
        return sub;
    else if (sign == '*')
        return mult;
    else if (sign == '/')
        return divide;
    else
        return nullptr;
}

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

void printResult(double d1, double d2, ArithmeticFunction aFunction)
{
    if (aFunction)
        std::cout << "Result: " << aFunction(d1, d2) << std::endl;
}

int main()
{
    double d1{askDoubleToUser()}, d2{askDoubleToUser()};
    char sign{askSignToUser()};

    if (!isValidSign(sign))
        return 1;

    printResult(d1, d2, getArithmeticFunction(sign));

    return 0;
}
