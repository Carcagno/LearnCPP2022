#include <iostream>
#include <vector>

class Shape
{
    public:

    virtual ~Shape() = default;
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }
};

class Point
{
    private:
    int m_x{}, m_y{}, m_z{};

    public:
    Point(int x = 0, int y = 0, int z = 0): m_x{x}, m_y{y}, m_z{z}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << "Point(" << p.m_x << ", " << p.m_y << ". " << p.m_z << ')';
        return out;
    }

};

class Triangle: public Shape
{
    private:
    Point m_p1, m_p2, m_p3;

    public:
    Triangle(const Point& p1 = Point{}, const Point& p2 = Point{}
        , const Point& p3 = Point{})
            : m_p1{p1}, m_p2{p2}, m_p3{p3}
    {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle("  << m_p1 << ", " << m_p2 << ", " << m_p3 << ")\n";
        return out;
    }

};

class Circle: public Shape
{
    private:
    Point m_center;
    int m_radius{};

    public:
    Circle(const Point& center = Point{}, int radius = 0)
    : m_center{center}, m_radius{radius}
    {}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle("  << m_center << ", radius " << getRadius() << ")\n";
        return out;
    }

    int getRadius() const
    {
        return m_radius;
    }

};

int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadiusSeen{-1};
    Circle *c;

    for (auto* element : v)
    {
        c = dynamic_cast<Circle*>(element);
        if (c)
        {
            if (c->getRadius() > largestRadiusSeen)
                largestRadiusSeen = c->getRadius();
        }
    }

    return largestRadiusSeen;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{1, 2, 3}, 7},
	  new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
	  new Circle{Point{4, 5, 6}, 3}
	};

	// print each shape in vector v on its own line here

	for(auto* element: v)
	{
        std::cout << *element;
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    for (auto* element: v)
    {
        delete element;
    }
	return 0;
}
