#include <iostream>

// https://en.cppreference.com/w/cpp/language/final
// Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be derived from.

struct Base
{
    virtual void foo();
};

struct A : Base
{
    void foo() final;   //Base::foo is overridden and A::foo is the final override
    void bar() final;   //Error: bar cannot be final as it is non-virtual    
};

struct B final : A //struct B is final
{
    void foo() override;    //Error: foo cannot be overridden as it is final in A
};

struct C : B {};    //Error: B is final