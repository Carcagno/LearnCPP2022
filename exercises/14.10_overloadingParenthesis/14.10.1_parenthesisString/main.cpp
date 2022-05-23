#include <iostream>

class MyString
{
    private:
    std::string m_str{};

    public:
    MyString(std::string str): m_str(str)
    {}

    std::string operator()(int startChar, int numberOfChar) const
    {
        int endingChar{startChar + numberOfChar};
        if (endingChar >= m_str.length())
            endingChar -= (endingChar - m_str.length());

        std::string cuttedStr{};
        while (startChar < endingChar)
        {
            cuttedStr += m_str[startChar];
            startChar++;
        }
        return cuttedStr;
    }
};


int main()
{
    MyString string{ "Hello, world!" };

    std::cout << string(7, 888) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
