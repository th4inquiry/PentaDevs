#pragma once
class TypeTraitTest
{
public:
    template <typename T>
    decltype(auto) sign_func(const T& v);

    void testTypeTraitCategory();
    void testTypeTraits();
    void testLambdaWithAuto();
};

// Reference : C++ High Performance
