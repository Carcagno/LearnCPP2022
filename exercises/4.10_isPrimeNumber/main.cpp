#include <iostream>

int getUserInput()
{
    std::cout << "Enter a number between 0 and 9:";

    int userInput{};
    std::cin >> userInput;

    if (userInput < 0 || userInput > 9)
        userInput = getUserInput();
    return userInput;
}

bool isPrime(int number)
{
    return (number == 2 || number == 3 || number == 5 || number == 7);
}

int main()
{
    int userInput{getUserInput()};

    if (isPrime(userInput))
        std::cout << userInput << " is Prime" << "\n";
    else
        std::cout << userInput << " is not Prime" << "\n";

    return 0;
}
