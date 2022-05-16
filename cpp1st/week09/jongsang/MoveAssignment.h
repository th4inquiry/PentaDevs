#pragma once

#include <string>
#include <iostream>
#include <utility>

namespace MoveAss
{
    struct A
    {
        std::string s;
        A() : s("test") { }
        A(const A& o) : s(o.s) { std::cout << "move failed!\n"; }
        A(A&& o) : s(std::move(o.s)) { }
        A& operator=(const A& other)
        {
            s = other.s;
            std::cout << "copy assigned\n";
            return *this;
        }
        A& operator=(A&& other)
        {
            s = std::move(other.s);
            std::cout << "move assigned\n";
            return *this;
        }
    };

    A f(A a) { return a; }

    struct B : A
    {
        std::string s2;
        int n;
        // implicit move assignment operator B& B::operator=(B&&)
        // calls A's move assignment operator
        // calls s2's move assignment operator
        // and makes a bitwise copy of n
    };

    struct C : B
    {
        ~C() { } // destructor prevents implicit move assignment
    };

    struct D : B
    {
        D() { }
        ~D() { } // destructor would prevent implicit move assignment
        D& operator=(D&&) = default; // force a move assignment anyway 
    };

}

