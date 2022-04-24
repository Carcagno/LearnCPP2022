#include <iostream>
#include <iterator>

int* find(int* bgn, int* nd, int value)
{
    for (int* currVal {bgn}; currVal != nd; ++currVal)
    {
        if (*currVal == value)
            return currVal;
    }
    return nd;
}

int main()
{
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};

    int* found{find(std::begin(arr), std::end(arr), 20)};

    if (found != std::end(arr))
        std::cout << *found << '\n';

    return 0;
}
