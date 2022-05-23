#include <iostream>
#include <iomanip>
#include <cmath>

class FixedPoint2
{
    private:
    int_least16_t m_nonFractionnalDigits{};
    int_least8_t m_fractionnalDigits{};
    bool m_isNeg{false};

    public:
    FixedPoint2(int nonFractionnalDigits, int fractionnalDigits);
    FixedPoint2(double d);
    operator double() const
    {
        double fp{m_nonFractionnalDigits};

        fp += (static_cast<double>(m_fractionnalDigits) / 100);

        if (m_isNeg)
            fp *= -1;

        return fp;
    }


    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& f);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& f)
{
    if (f.m_isNeg)
        out << '-';

    out << f.m_nonFractionnalDigits << '.' << std::setw(2) << std::setfill('0')
        << static_cast<int>(f.m_fractionnalDigits) << '\n';

    return out;
}

FixedPoint2::FixedPoint2(int nonFractionnalDigits, int fractionnalDigits)
    : m_nonFractionnalDigits{nonFractionnalDigits}
    , m_fractionnalDigits(fractionnalDigits)
{
    if (m_nonFractionnalDigits < 0 || m_fractionnalDigits < 0)
        {
            m_isNeg = true;
            m_nonFractionnalDigits = std::abs(m_nonFractionnalDigits);
            m_fractionnalDigits = std::abs(m_fractionnalDigits);
        }
}



int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	return 0;
}
