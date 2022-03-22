#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std::string_literals; // enables s-suffix for std::string literals

class TypedefTest
{
protected:
    typedef int Integer;
    typedef int IntegerArray[5];
    typedef int* IntegerPointer;
    typedef int(*Func)(int a1, int a2);

    static int foo(int, int)
    {
        return 0;
    }

public:
    void testAll();
};

void TypedefTest::testAll()
{
    Integer i = 0;
    IntegerArray ia = {1,2,3,4,5};
    IntegerPointer ip = ia;
    Func func = foo;

    func(i, *ip);
}

class UsingTest
{
protected:
    using Integer = int;
    using IntegerArray = int[5];
    using IntegerPointer = int*;
    using Func = int(*)(int a1, int a2);
    using Func2 = void(*)(int a1, int a2);
    using IntegerVector = std::vector<Integer>;
    template <typename T>
    using IntegerIndexedMap = std::map<Integer, T>;

    static int foo(int, int)
    {
        return 0;
    }

    static void foo2(int, int)
    {
    }

public:
    void testAliasTemplate();
    void testAll();
};


void UsingTest::testAliasTemplate()
{
    IntegerIndexedMap<std::string> indexMap;
    indexMap[indexMap.size()] = "1st test item"s;
    indexMap[indexMap.size()] = "2nd test item"s;

    // range-based for loop
    for (auto i : indexMap)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }
}

void UsingTest::testAll()
{
    Integer i = 0;
    IntegerArray ia = {1,2,3,4,5};
    IntegerPointer ip = ia;
    Func func = foo;
    Func2 func2 = foo2;
    IntegerVector v = {1,2,3,4,5};

    func(i, *ip);
    func2(i, *ip);

    testAliasTemplate();
}

int main()
{
    TypedefTest tester;
    tester.testAll();

    UsingTest tester2;
    tester2.testAll();

    return 0;
}

