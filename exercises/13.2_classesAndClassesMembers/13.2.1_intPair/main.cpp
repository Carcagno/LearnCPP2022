#include <iostream>

class IntPair
{
    public:
    int p1{}, p2{};

    void set(int num1, int num2)
    {
        p1 = num1;
        p2 = num2;
    }

    void print()
    {
        std::cout << "Pair(" << p1 << ", " << p2 << ")\n";
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}
