#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string& make, const std::string& model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend bool operator<(const Car& c1, const Car& c2);
};

bool operator<(const Car& c1, const Car& c2)
{
    int cmpMake{c1.m_make.compare(c2.m_make)};

    if (!cmpMake)
    {
        int cmpModel{c1.m_model.compare(c2.m_model)};

        if (cmpModel > 0)
            return false;
        return true;
    }
    if (cmpMake > 0)
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Car& c)
{
    out << '(' << c.m_make << ", " << c.m_model << ")\n";
    return out;
}

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

int main()
{
  std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}
