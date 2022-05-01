//A C++ program to demonstrate the use of constexpr
//Performance check between normal and const

#include <iostream>
#include <chrono>

constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}

int main()
{
    auto start = std::chrono::steady_clock::now();

    //value of res is computed at compile time.
    //constexpr long int res = fib(30); //0.0011209 
    //const long int res = fib(30); //0.0010294
    long int res = fib(30); //0.0015972
    std::cout << res << std::endl;

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds = end - start;
    std::cout << "elasped time: " << elasped_seconds.count() << " s\n";

    return 0;
}