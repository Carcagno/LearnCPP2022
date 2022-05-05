#include <iostream>

class Something
{
    static inline int s_value{0};

    public:

    static int getValue() {return s_value;}

};

int main()
{
    std::cout << Something::getValue() << '\n';
    return 0;
}
