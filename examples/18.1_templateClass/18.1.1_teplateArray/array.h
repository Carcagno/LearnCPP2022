#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <cassert>

template <typename T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:
    Array(int length);
    ~Array();

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    void erase();
    int getLength() const;

    T& operator[](int index);
};

#endif // ARRAY_H_INCLUDED
