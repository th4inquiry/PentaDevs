
#include "ConstExprTest.h"
#include <type_traits>
#include <iostream>


// /////////////////////////////////////////////////////////////////////

constexpr int sum(int x, int y, int z)
{
    return x + y + z;
}

void ConstExprTest::testIntegralConst()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    // std::integral_constant can be used to check that constexpr is evaluated at compile time

    // compile OK
    std::integral_constant<int, sum(1, 2, 3)> int_const;

    int x;
    std::cout << "intput number : ";
    std::cin >> x;
    // compile error
    //std::integral_constant<int, sum(x, x, x)> int_const2;

    std::cout << "##### Ends #####" << std::endl;

}

// /////////////////////////////////////////////////////////////////////


// /////////////////////////////////////////////////////////////////////
template <typename T>
auto ConstExprTest::speak(const T& a)
{
    if constexpr (std::is_same_v<T, Bear>)
    {
        a.roar();
    }
    else if constexpr (std::is_same_v<T, Duck>)
    {
        // Actually, this line is never executed, but it makes error in compile time.
        // However if constexpr removes this part because it is not used.
        a.quack();
    }
    // This body will be created with constexpr as the below.
    // ...
    // if (true)
    // {
    //     a. roar();
    // }
    // ... ends..
}
void ConstExprTest::testIfConstexpr()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    Bear bear;
    speak(bear);
}

// // Reference : C++ High Performance
