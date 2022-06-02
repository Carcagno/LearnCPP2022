#include <iostream>
#include <limits>
#include <exception>
#include <stdexcept>

class Fraction
{
private:
    int m_numerator{}, m_denominator{};
public:
    Fraction(const int numerator, const int denominator) try
        : m_numerator{numerator}, m_denominator{denominator}
    {
        if (m_denominator == 0)
            throw std::runtime_error("Invalid denominator: 0");
    }
    catch (const std::exception& excep)
    {
        std::cerr << "In class:\n" << excep.what() << '\n';
    }

    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

int getInt()
{
    while (true)
    {
        std::cout << "Enter an int: ";

        int userNumber {0};
        std::cin >> userNumber;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please, try again\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return userNumber;
        }
    }
}

int main()
{
    try
    {
        Fraction f1{getInt(), getInt()};

        f1.print();
    }
    catch (const std::exception& excep)
    {
        std::cerr << "In main():\n" << excep.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown exception !\n";
    }
    return 0;
}
