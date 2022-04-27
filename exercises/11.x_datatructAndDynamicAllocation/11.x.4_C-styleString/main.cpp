#include <iostream>

void printCString(const char* c)
{
    while (*c != '\0')
    {
        std::cout << *c;
        ++c;
    }
}

int main()
{
    printCString("Hello, world!");
    return 0;
}
