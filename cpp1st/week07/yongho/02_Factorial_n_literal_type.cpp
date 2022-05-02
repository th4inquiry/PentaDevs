#include <iostream>
#include <stdexcept>

//C++ contexpr functions use recursion rather than iteration
//(C++14 constexpr functions may use local variables and loops)
constexpr int factorial(int n)
{
    int result = 0;

    if (n <= 1)
    {
        result = 1;
    }
    else
    {
        result = n * factorial(n-1);
    }

    return result;
    //return n <= 1 ? 1:(n*factorial(n-1));
}

//literal class
class conststr
{
    const char* p;
    std::size_t str_size;

public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]): p(a), str_size(N-1) {}

    //constexpr functions signal errors by throwing exceptions
    // in C++11, they must do so from the conditional operator ?:
    constexpr char operator[](std::size_t n) const
    {
        return n < str_size ? p[n] : throw std::out_of_range("");
    }

    constexpr std::size_t size() const 
    { 
        return str_size; 
    }
};

// C++11 constexpr functions had to put everything in a single return statement
// (C++14 doesn't have that requirement)
constexpr std::size_t countlower(conststr s, std::size_t total_cnt=0, std::size_t lower_cnt=0)
{
    std::size_t result = 0;

    if (total_cnt == s.size())
    {
        result = lower_cnt;
    }
    else
    {
        if ('a' <= s[total_cnt] && s[total_cnt] <= 'z') //lower charater
        {
            result = countlower(s, ++total_cnt, lower_cnt+1);
        }
        else
        {
            result = countlower(s, ++total_cnt, lower_cnt);
        }
    }

    return result;

    //return n==s.size() ? c: 'a' <= s[n] && s[n] <= 'z' ? countlower(s, n+1, c+1) : countlower(s, n+1,c);
}

//output function that requires a compile-time constant, for testing
template<int n>
struct constN
{
    constN() 
    {
        std::cout << n << '\n';
    }
};

int main()
{
    std::cout << "4! = "; //24
    constN<factorial(4)> out1; //computed at compile time

    volatile int k = 8; //disallow optimization using volatile
    std::cout << k << "! = " << factorial(k) << '\n'; //computed at run time //40320

    std::cout << "the number of lowercase letters in \"Hello, world!\" is ";
    constN<countlower("Hello, world!")> out2;  //implicitly converted to constr //9
}
