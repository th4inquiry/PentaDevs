#pragma once
#include <initializer_list>

template <typename T, size_t ARRAY_SIZE = 10>
class MyArrayLimited
{
public:
    MyArrayLimited() = default;
    MyArrayLimited(std::initializer_list<T> args);

    T& operator[](size_t index);

private:
    T mArray[ARRAY_SIZE];
};
