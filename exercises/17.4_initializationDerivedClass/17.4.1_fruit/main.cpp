#include <iostream>
#include <string>

class Fruit
{
    protected:
    std::string m_name{}, m_color{};

    public:
    Fruit(const std::string& name, const std::string& color)
    : m_name(name), m_color(color)
    {}

    friend std::ostream& operator<<(std::ostream& out, const Fruit& f);
};

std::ostream& operator<<(std::ostream& out, const Fruit& f)
{
    out << '(' << f.m_name << ", " << f.m_color << ')';
    return out;
}

class Apple : public Fruit
{
    private:
    double m_fiber{};

    public:
    Apple(const std::string& name = "Granny Smith"
        , const std::string& color = "Green", double fiber = .0)
            : Fruit{name, color}, m_fiber{fiber}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Apple& f);
};

std::ostream& operator<<(std::ostream& out, const Apple& f)
{
    out << '(' << f.m_name << ", " << f.m_color << ", " << f.m_fiber << ')';
    return out;
}

class Banana : public Fruit
{
    private:

    public:
    Banana(const std::string& name = "Guinean Bananas"
        , const std::string& color = "Yellow")
            : Fruit{name, color}
    {}
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
