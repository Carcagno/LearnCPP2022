#include <iostream>
#include <limits>
#include <utility>

int main()
{
    int arr[] {6, 3, 2, 9, 7, 1, 5, 4, 8};

    for (int i = 0; i < std::size(arr); ++i)
    {
        int indexToSwap {i};
        for (int j = i+1; j < std::size(arr); ++j)
        {
            if (arr[j] < arr[i] && arr[indexToSwap] > arr[j])
                indexToSwap = j;
        }
        if (indexToSwap > -1)
            std::swap(arr[indexToSwap], arr[i]);
    }

    for (int k = 0; k < std::size(arr); ++k)
        std::cout << arr[k] << '\n';

    return 0;
}
