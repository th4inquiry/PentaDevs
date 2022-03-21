#include <iostream>
#include <string>
using namespace std::string_literals; // enables s-suffix for std::string literals

class VariadicTest
{
public:
    void testAll();
protected:
    template <typename T>
    T add(T p)
    {
        std::cout << __FUNCSIG__ << std::endl << std::endl;
        return p;
    }

    template <typename T, typename... Ts>
    T add(T first, Ts... others)
    {
        std::cout << __FUNCSIG__ << std::endl << std::endl;
        return first + add(others...);
    }
};

void VariadicTest::testAll()
{
    auto a = add(1,2,3,4,5,6,7,8,9,10);
    auto s = add("this"s," "s,"is"s," a "s,"test"s);

    std::cout << a << std::endl;
    std::cout << s << std::endl;
}

int main()
{
    VariadicTest tester;
    tester.testAll();

    return 0;
}