#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <utility>

namespace MoveCon
{
    struct A
    {
        std::string s;
        int k;
        A() : s("test"), k(-1) { }
        A(const A& o) : s(o.s), k(o.k) { std::cout << "move failed!\n"; }
        A(A&& o) noexcept :
            s(std::move(o.s)),       // explicit move of a member of class type
            k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
        { }
    };

    A f(A a)
    {
        return a;
    }

    struct B : A
    {
        std::string s2;
        int n;
        // implicit move constructor B::(B&&)
        // calls A's move constructor
        // calls s2's move constructor
        // and makes a bitwise copy of n
    };

    struct C : B
    {
        ~C() { } // destructor prevents implicit move constructor C::(C&&)
    };

    struct D : B
    {
        D() { }
        ~D() { }          // destructor would prevent implicit move constructor D::(D&&)
        D(D&&) = default; // forces a move constructor anyway
    };
}
