#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";

    std::string userName{};
    std::getline(std::cin >> std::ws, userName);

    std::cout << "Enter your age: ";

    int age{};
    std::cin >> age;

    std::cout << "Your age + lenth of name is: " << age + static_cast<int>( userName.length() );

    return 0;
}
