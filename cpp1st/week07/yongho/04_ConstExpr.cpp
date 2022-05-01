//Reference : https://docs.microsoft.com/ko-kr/cpp/cpp/constexpr-cpp?view=msvc-170
//constexpr.cpp
// Compile with: c1 /EHsc /W4 constexpr.cpp
#include <iostream>

//Pass by value
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 : n%2 == 0 ? exp(x*x, n/2) : exp(x*x, (n-1)/2) *x;
}

//Pass by reference
constexpr float exp2(const float& x, const int& n)
{
    return n == 0 ? 1 : n%2 == 0 ? exp(x*x, n/2) : exp(x*x, (n-1)/2) *x;
}

//Compile-time computation of array length
template<typename T, int N>
constexpr int length(const T(&)[N])
{
    return N;
}

//Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n-1);
}

//User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }
private:
    int _i;
};

int main()
{
    //foo is const;
    constexpr Foo foo(5);
    std::cout << "The value of foo is " << foo.GetValue() << std::endl;
    //foo = Foo(6); //Error!

    //Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y { exp(2,5)};
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[] {1,2,3,4};
    const int nums2[length(nums)*2] {1,2,3,4,5,6,7,8};

    //run time:
    std::cout << "The value of foo is " << foo.GetValue() << std::endl;
}

