#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class ArrayException : public std::runtime_error
{
private:

public:
    ArrayException(const std::string& error)
        : std::runtime_error{error.c_str()}
    {}

};

class IntArray
{
private:
    int m_data[3]{};

public:
    IntArray(){}

    int getLength() const
    {
        return 3;
    }

    int& operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayException("Invalid index");

        return m_data[index];
    }
};

int main()
{
    IntArray array;

    try
    {
        int value{array[5]};
    }
    catch (const ArrayException& exception) //Derived class catch first
    {
        std::cerr << "An array exception occured (" << exception.what() << ")\n";
    }
    catch (const std::exception& exception) //Derived class catch first
    {
        std::cerr << "A generic exception occured (" << exception.what() << ")\n";
    }

    return 0;
}
