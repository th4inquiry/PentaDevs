///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Examples of bad_alloc (referenced from CppReference)

#include <iostream>
#include <new>

int main()
{
    try {
        while (true) {
            new int[100000000ul];
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}