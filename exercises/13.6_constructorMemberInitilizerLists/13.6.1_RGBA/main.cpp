#include <iostream>
#include <cstdint>

class RGBA
{
    std::uint8_t m_red{}, m_blue{}, m_green{}, m_alpha{255};

    public:

    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0
        , std::uint8_t alpha = 255)
        : m_red{red}
        , m_blue{blue}
        , m_green{green}
        , m_alpha{alpha}
        {
        }

    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red)
            << "\tg=" << static_cast<int>(m_green)
            << "\tg=" << static_cast<int>(m_blue)
            << "\ta=" << static_cast<int>(m_alpha)
            << '\n';
    }
};

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}
