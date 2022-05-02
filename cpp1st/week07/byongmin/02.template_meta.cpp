#include <iostream>

using namespace std;

template <int N>
struct Factorial
{
    static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<0>
{
    static const int result = 1;
};

int main() 
{
    std::cout << "6! = " << Factorial<6>::result << std::endl;
}