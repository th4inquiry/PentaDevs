///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Examples of bad_function_call (referenced from CppReference)

#include <iostream>
#include <functional>

int main()
{
    std::function<int()> f = nullptr;
    try {
        f();
    } catch(const std::bad_function_call& e) {
        std::cout << e.what() << '\n';
    }
}