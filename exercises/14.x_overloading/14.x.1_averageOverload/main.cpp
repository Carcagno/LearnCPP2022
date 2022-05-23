#include <iostream>

class Average
{
    private:
    int_least32_t m_sum{};
    int_least8_t m_howManyNumbers{};
    double m_avg{};

    public:
    Average& operator+=(int nbr);

    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

Average& Average::operator+=(int nbr)
{
    m_sum += nbr;
    ++m_howManyNumbers;
    m_avg = static_cast<double>(m_sum) / m_howManyNumbers;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{

    out << avg.m_avg;
    return out;
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
