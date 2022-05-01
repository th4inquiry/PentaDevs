// main.cpp
//

#include "ConstExprTest.h"
#include "TypeTraitTest.h"
#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

template <int N = 1, typename T>
auto const_pow_n(const T& v)
{
    // static_assert() will refuse to compile if the condition isn't fulfilled.
    static_assert(N >= 0, "N must be positive");
    auto product = T{ 1 };
    for (int i = 0; i < N; ++i)
    {
        product *= v;
    }
    return product;
}

void testStaticAssert()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto x = const_pow_n<5>(2);
    //auto y = const_pow_n<-1>(10);
}

int main()
{
    testStaticAssert();

    TypeTraitTest typeTraitTest;
    typeTraitTest.testTypeTraitCategory();
    typeTraitTest.testTypeTraits();
    typeTraitTest.testLambdaWithAuto();

    ConstExprTest constExprTest;
    constExprTest.testIntegralConst();
    constExprTest.testIfConstexpr();
}

// Reference : C++ High Performance
