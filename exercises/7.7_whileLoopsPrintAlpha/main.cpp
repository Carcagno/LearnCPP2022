#include <iostream>


int main()
{
    char c{'a'};

    while (c <= 'z')
    {
        std::cout << "Letter: " << c << "\tASCII: " << static_cast<int>(c) << '\n';

        ++c;
    }

    return 0;
}
