#include <iostream>

int calculate(int op1, int op2, char sign)
{
    switch (sign)
    {
        case('+'):
            return (op1 + op2);
        case('-'):
            return (op1 - op2);
        case('*'):
            return (op1 * op2);
        case('/'):
            return (op1 / op2);
        case('%'):
            return (op1 % op2);
        default:
            {
                std::cout << "Unknown sign: " << sign;
                return 0;
            }
    }
}

int main()
{
    std::cout << calculate(2, 4, '+');

    return 0;
}
