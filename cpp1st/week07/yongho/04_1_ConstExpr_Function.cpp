//This program calculates the greates common divisor or two numbers
#include <iostream>

constexpr auto gcd(int a, int b)
{
    while (b!=0)
    {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    std::cout << std::endl;
    constexpr int i = gcd(11, 121); //1) calculates the result i at compile time
    std::cout << "gcd(11, 121): " << i << std::endl;

    int a, b;
    std::cin >> a; //11
    std::cin >> b; //121
    int j = gcd(a, b); //2) cacluate the result i at run time
    std::cout << "gcd(" << a << ", " << b << "): " << j << std::endl;

    std::cout << std::endl;
}