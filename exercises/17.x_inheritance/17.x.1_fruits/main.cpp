#include <iostream>
#include <string>

class Fruit
{
    protected:
    std::string m_name{}, m_color{};

    public:
    Fruit(const std::string& name = "Fruitz", const std::string& color = "red" )
        : m_name{name}, m_color{color}
    {}

    const std::string& getName()
    {
        return m_name;
    }

    const std::string& getColor()
    {
        return m_color;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fruit& f);
};

std::ostream& operator<<(std::ostream& out, const Fruit& f)
{
    out << "My " << f.m_name << " is " << f.m_color << '\n';
    return out;
}

class Apple : public Fruit
{
    public:
    Apple(const std::string& name = "apple", const std::string& color = "red")
    : Fruit{name, color}
    {}
};

class GrannySmith : public Apple
{
    public:
    GrannySmith()
    : Apple{"granny smith", "green"}
    {
    }
};

class Banana : public Fruit
{
    public:
    Banana(): Fruit("banana", "yellow")
    {}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
