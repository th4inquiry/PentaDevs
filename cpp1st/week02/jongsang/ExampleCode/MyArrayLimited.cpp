
#include "MyArrayLimited.h"
#include <stdexcept>


template <typename T, size_t ARRAY_SIZE>
MyArrayLimited<T, ARRAY_SIZE>::MyArrayLimited(std::initializer_list<T> args)
{
    int i = 0;
    for (const auto& val : args)
    {
        mArray[i++] = val;
    }
}

template <typename T, size_t ARRAY_SIZE>
T& MyArrayLimited<T, ARRAY_SIZE>::operator[](size_t index)
{
    if (index >= ARRAY_SIZE)
    {
        throw std::out_of_range("");
    }
    return mArray[index];
}

// Speicfy template type
template class MyArrayLimited<int>;
