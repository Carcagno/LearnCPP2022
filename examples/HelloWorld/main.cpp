#include <iostream>

using namespace std;

int main()
{
    std::cout << "Enter a number: "; //Ask the user to enter a number

    int x{};
    std::cin >> x; //get the number from the user

    std::cout << "You entered the number: " << x << '\n';
    return 0;
}
