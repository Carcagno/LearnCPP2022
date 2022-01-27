#include <iostream>

int getInt()
{
    std::cout << "Enter an Integer: ";

    int x{};                                    //x created here
    std::cin >> x;

    return x;
}                                               // x destroyed here

int main()
{
    int smaller{getInt()}, larger{getInt()};    // smaller & larger reated here

    if (smaller > larger)
    {
        int temp{smaller};                      // temp created here

        std::cout << "Swapping values ..." << '\n';

        smaller = larger;
        larger = temp;
    }                                           // temp destroyed here

    std::cout << "The smaller variable is: " << smaller << '\n';
    std::cout << "The larger variable is: " << larger << '\n';

    return 0;
}                                               // smaller & greater destroyed here
