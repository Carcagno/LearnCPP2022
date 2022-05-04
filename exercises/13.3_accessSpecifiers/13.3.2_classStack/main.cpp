#include <iostream>
#include <array>

class Stack
{
    std::array<int, 10> m_values{};
    int m_valuesLength{};

    public:
    void reset()
    {
        m_valuesLength = 0;
    }

    bool push(int val)
    {
        if (m_valuesLength == m_values.size())
            return false;

        m_values[m_valuesLength] = val;
        ++m_valuesLength;
        return true;
    }

    int pop()
    {
        return (m_values[m_valuesLength--]);
    }

    void print()
    {
        std::cout << "( ";

        for (int i{}; i < m_valuesLength; ++i)
            std::cout << m_values[i] << ' ';

        std::cout << ")\n";
    }
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
