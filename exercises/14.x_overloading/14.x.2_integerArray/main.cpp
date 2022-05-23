#include <iostream>


class IntArray
{
    private:
    int* m_array{nullptr};
    int m_arraySize{};

    public:
    IntArray(int arraySize);
    IntArray(const IntArray& intArray);
    ~IntArray();

    int& operator[](int nb);
    IntArray& operator=(const IntArray& i1);

    friend std::ostream& operator<<(std::ostream& out, const IntArray& intArray);
    friend bool operator==(const IntArray& i1, const IntArray& i2);
};

IntArray& IntArray::operator=(const IntArray& i1)
{
    if (&i1 == this)
        return *this;

    m_arraySize = i1.m_arraySize;
    delete[] m_array;
    m_array = new int[m_arraySize];

    for (int i{0}; i < i1.m_arraySize; ++i)
    {
        m_array[i] = i1.m_array[i];
    }

    return *this;
}

bool operator==(const IntArray& i1, const IntArray& i2)
{
    if (i1.m_arraySize != i2.m_arraySize)
        return false;
    for (int i{0}; i < i1.m_arraySize; ++i)
    {
        if (i1.m_array[i] != i2.m_array[i])
            return false;
    }
    return true;
}

IntArray::IntArray(const IntArray& intArray)
{
    if (&intArray == this)
        return;

    m_arraySize = intArray.m_arraySize;
    m_array = new int[m_arraySize];

    for (int i{0}; i < intArray.m_arraySize; ++i)
    {
        m_array[i] = intArray.m_array[i];
    }
}

std::ostream& operator<<(std::ostream& out, const IntArray& intArray)
{
    for (int i{0}; i < intArray.m_arraySize; ++i)
    {
        out << intArray.m_array[i] << ' ';
    }

    return out;
}

int& IntArray::operator[](int index)
{
    if (index >= m_arraySize || index < 0)
        {
            std::cerr << "Index out of range!" << std::endl;
            exit(-1);
        }
    return m_array[index];
}

IntArray::IntArray(int arraySize): m_arraySize{arraySize}
{
    m_array = new int[arraySize];
}

IntArray::~IntArray()
{
    delete[] m_array;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}
