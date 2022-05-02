#pragma once

#include <iostream>

class ConstExprTest
{
public:
    struct Bear
    {
        auto roar() const
        {
            std::cout << "roar";
        }
    };
    struct Duck
    {
        auto quack() const
        {
            std::cout << "quack";
        }
    };
    template <typename T>
    auto speak(const T& a);

    void testIntegralConst();
    void testIfConstexpr();
};

// Reference : C++ High Performance
