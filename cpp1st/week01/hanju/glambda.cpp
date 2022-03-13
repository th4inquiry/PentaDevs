#include <algorithm>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class GenericLambdaTest
{
public:
    void testCompare();
    void testMultiply();
    void testAll();

private:
    void printName()
    {
        std::cout << "GenericLambdaTest" << std::endl;
    }
};

void GenericLambdaTest::testCompare()
{
    auto comp = [](auto a, auto b){return a>b;};
    std::vector<std::string> sdata = {"1", "A", "2"};
    for (auto d : sdata) std::cout << d << " ";
    std::cout << std::endl;

    std::sort(sdata.begin(), sdata.end(), comp); // same as std::sort(sdata.begin(), sdata.end(), [](std::string a, std::string b){return a>b;});
    for (auto d : sdata) std::cout << d << " ";
    std::cout << std::endl;


    std::vector<int> idata = {1, 10, 2};
    for (auto d : idata) std::cout << d << " ";
    std::cout << std::endl;

    std::sort(idata.begin(), idata.end(), comp); // same as std::sort(idata.begin(), idata.end(), [](int a, int b){return a>b;});
    for (auto d : idata) std::cout << d << " ";
    std::cout << std::endl;
}

void GenericLambdaTest::testMultiply()
{
    auto mul = [](auto n1, auto n2){return n1*n2;};
    auto muld = [](auto n1, auto n2){
        std::cout << "n1=" << n1 << " as " << typeid(n1).name() << std::endl;
        std::cout << "n2=" << n2 << " as " << typeid(n2).name() << std::endl;
        auto r = n1*n2;
        std::cout << "r=" << r << " as " << typeid(r).name() << std::endl;
        return r;
    };

    std::cout << mul(0.5f, 200ul) << std::endl;
    muld(0.5f, 200ul);

    std::cout << mul(0.5, 200ul) << std::endl;
    muld(0.5, 200ul);
}

void GenericLambdaTest::testAll()
{
    testCompare();
    testMultiply();
}

int main()
{
    GenericLambdaTest tester;
    tester.testAll();

    return 0;
}