#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view arrNames[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string name;

    std::cout << "Enter the name: ";
    std::getline(std::cin >> std::ws, name);

    for (const auto& n : arrNames)
    {
        if (n == name)
        {
            std::cout << name << " was found !\n";
            return 0;
        }
    }

    std::cout << name << " was NOT found!\n";

    return 0;
}
