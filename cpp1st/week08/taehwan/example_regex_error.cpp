///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Examples of regex_error (referenced from CppReference)

#include <regex>
#include <iostream>

int main()
{
    try {
        std::regex re("[a-b][a");
    }
    catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
}