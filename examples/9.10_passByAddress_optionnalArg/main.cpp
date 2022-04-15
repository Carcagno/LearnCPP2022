#include <iostream>
#include <limits>

void greet(std::string* name=nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "Guest") << '\n';
}

int main()
{
    greet();

    std::string joe{"Joe"};
    greet(&joe);
    return 0;
}
