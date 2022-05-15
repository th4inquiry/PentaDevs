///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Examples of future_error (referenced from CppReference)

#include <future>
#include <iostream>

int main()
{
    std::future<int> empty;
    try {
        int n = empty.get(); // The behavior is undefined, but
        // some implementations throw std::future_error
    } catch (const std::future_error& e) {
        std::cout << "Caught a future_error with code \"" << e.code()
                  << "\"\nMessage: \"" << e.what() << "\"\n";
    }
}