#include <iostream>

int add(int nb1, int nb2)
{
    return (nb1 + nb2);
}

int add(int nb1, int nb2, int nb3)
{
    return (nb1 + nb2 + nb3);
}

double add(double nb1, double nb2)
{
    return (nb1 + nb2);
}

int main()
{
    std::cout << add(1, 2) << " | " << add(.1, .2) << " | " << add(2, 4, 6) << " | " << add(.2, static_cast<double>(4)) << " | " << add('a', 'z');
    return 0;
}
