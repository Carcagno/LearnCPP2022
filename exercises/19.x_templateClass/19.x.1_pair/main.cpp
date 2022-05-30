#include <iostream>
#include <string>

template<typename T>
class Pair1
{
private:
    T m_value1{}, m_value2{};
public:
    Pair1(const T& value1, const T& value2): m_value1{value1}, m_value2{value2}
    {}
    const T& first() const
    {
        return m_value1;
    }

    const T& second() const
    {
        return m_value2;
    }
};

template<typename T1, typename T2>
class Pair
{
private:
    T1 m_value1{};
    T2 m_value2{};
public:
    Pair(const T1& value1, const T2& value2): m_value1{value1}, m_value2{value2}
    {}

    const T1& first() const
    {
        return m_value1;
    }

    const T2& second() const
    {
        return m_value2;
    }
};

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
	StringValuePair(const std::string& key, const S& value)
		: Pair<std::string, S> { key, value }
	{
	}
};

int main()
{
	Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << "\t\t" << p1.second() << '\n';

	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << '\t' << p2.second() << '\n';

	std::cout << "\n\n**********SECOND TESTS PARTS************\n";


    Pair<int, double> ps1 { 5, 6.7 };
    std::cout << "Pair: " << ps1.first() << "\t\t" << ps1.second() << '\n';

	const Pair<double, int> ps2 { 2.3, 4 };
	std::cout << "Pair: " << ps2.first() << '\t' << ps2.second() << '\n';

    std::cout << "\n\n**********SECOND TESTS PARTS************\n";

    StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
