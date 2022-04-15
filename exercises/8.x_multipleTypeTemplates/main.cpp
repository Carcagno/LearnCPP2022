#include <iostream>

template <typename T, typename U>

auto mult(T x, U y)
{
    return (x * y);
}

//|| C++20 -fconcepts

/*auto mult(auto x, auto y)
{
    return (x * y);
}*/

int main()
{
    std::cout << mult(2, 3) << '\n';
    std::cout << mult(1.2, 3) << '\n';

    return 0;
}
