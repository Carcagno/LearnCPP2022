#include <iostream>

int getDigitAdded(int nb)
{
    int res{nb % 10};

    nb /= 10;

    if (nb)
        return res + getDigitAdded(nb);
    else
        return res;
}

int main()
{
    std::cout << getDigitAdded(93427) << '\n';
    return 0;
}
