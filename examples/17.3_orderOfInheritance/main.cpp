#include <iostream>

class Base
{
    public:
    Base()
    {
        std::cout << "Base\n";
    }
};

class Intermediate : public Base
{
    public:
    Intermediate()
    {
        std::cout << "Intermediate\n";
    }
};

class Final : public Intermediate
{
    public:
    Final()
    {
        std::cout << "Final\n";
    }
};

int main()
{
    std::cout << "Instanciating Base:\n";
    Base b{};

    std::cout << "Instanciating Intermediate:\n";
    Intermediate i{};

    std::cout << "Instanciating Final:\n";
    Final f;

    return 0;
}
