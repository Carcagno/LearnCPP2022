#include <iostream>
#include <utility>

int main()
{
    int arr[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    for (int iteration{0}; iteration < std::size(arr); ++iteration)
    {
        bool flagSwap {0};
        for (int i{0}; i < (std::size(arr) - iteration - 1); ++i)
        {
            if (arr[i] > arr[i+1])
                {
                    std::swap(arr[i], arr[i+1]);
                    flagSwap = true;
                }
        }
        std::cout << "Itération: " << iteration + 1 << '\n';
        if (!flagSwap)
            break;
    }


    for (int j{0}; j < std::size(arr); ++j)
        std::cout << arr[j] << ' ';

    return 0;
}
