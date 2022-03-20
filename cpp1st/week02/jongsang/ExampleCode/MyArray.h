#pragma once
#include <initializer_list>

template <typename T, size_t ARRAY_SIZE>
class MyArray
{
public:
    MyArray();
    MyArray(std::initializer_list<T> args);

    T& operator[](size_t index);

private:
    T mArray[ARRAY_SIZE];
};


template <typename T, size_t ARRAY_SIZE>
MyArray<T, ARRAY_SIZE>::MyArray()
{

}

template <typename T, size_t ARRAY_SIZE>
MyArray<T, ARRAY_SIZE>::MyArray(std::initializer_list<T> args)
{
    int i = 0;
    for (const auto& val : args)
    {
        mArray[i++] = val;
    }
}

template <typename T, size_t ARRAY_SIZE>
T& MyArray<T, ARRAY_SIZE>::operator[](size_t index)
{
    if (index >= ARRAY_SIZE)
    {
        throw std::out_of_range("");
    }
    return mArray[index];
}

