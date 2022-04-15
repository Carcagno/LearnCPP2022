#include <iostream>

/*template <typename T, typename U>

T max(T x, U y)
{
    return ((x > y) ? x : y);
}*/

// or since C++20
template <typename T, typename U>

auto max(T x, U y)
{
    return ((x > y) ? x : y);
}

int main()
{
    std::cout << max(2.5, 3);
    return 0;
}
