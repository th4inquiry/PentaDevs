//constexpr sample code
#include <iostream>

//C++14: allow local variable, for loop
constexpr int factorial1(int N)
{
    int total = 0;
    for (int i=1; i <=N; ++i)
    {
        total+=i;
    }
    return total;
}

//C++11 style : no local variable, only one return
constexpr int factorial2(int N)
{
    return N <=1 ? 1 : (N + factorial2(N-1));
}

template <int N>
struct A 
{
    int operator()()
    {
        return N;
    }
};

int main()
{
    A<factorial1(10)> a;
    std::cout << "C++14 style:" << a() << std::endl;

    A<factorial2(10)> b;
    std::cout << "C++11 style:" << b() << std::endl;
}