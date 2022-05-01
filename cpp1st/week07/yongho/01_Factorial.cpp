#include <iostream>

constexpr int factorial(int N)
{
    int total = 0;
    for (int i=1; i <=N; ++i)
    {
        total+=i;
    }
    //std::cout << total << std::endl; //error
    return total;
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
    A<factorial(10)> a;

    std::cout << a() << std::endl;
}