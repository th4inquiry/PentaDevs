#include "SortingTest.h"
#include "Person.h"
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

void SortingTest::testSortCppref()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    std::array<int, 10> s = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    auto print = [&s](std::string const rem) {
        for (auto a : s) {
            std::cout << a << ' ';
        }
        std::cout << ": " << rem << '\n';
    };

    std::sort(s.begin(), s.end());
    print("sorted with the default operator<");

    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object");

    struct {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object");

    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
        });
    print("sorted with a lambda expression");
}

void SortingTest::testSort()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto comp = [](Person& p1, Person& p2) {
        return p1.getName().compare(p2.getName()) < 0;
    };

    std::vector<Person> vecPerson = {
        {L"Jack", 10, Person::DebugSwitch::On},
        {L"Levin", 50},
        {L"Ben", 40},
        {L"Rocky", 22},
        {L"Zenis", 80}
    };

    std::sort(vecPerson.begin(), vecPerson.end(), comp);

    for (const auto& elem : vecPerson)
    {
        elem.printInfo();
    }
}

void SortingTest::testPartialSort()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto printVector = [](auto& vec) {
        std::cout << "{ ";
        for (const auto& elem : vec)
        {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
    };

    auto myfunction = [](int i, int j) {
        return i < j;
    };

    int myints[] = { 6, 2, 5, 1, 3, 8, 0, 10, 9};
    std::vector<int> myvector(myints, myints + 9);

    std::cout << "Origianl contains: ";
    printVector(myvector);

    // using default comparison (operator <):
    std::partial_sort(myvector.begin(), myvector.begin() + 3, myvector.end());
    std::cout << "myvector contains (middle number [3]:";
    printVector(myvector);

    // using function as comp
    std::partial_sort(myvector.begin(), myvector.begin() + 6, myvector.end(), myfunction);

    // print out content:
    std::cout << "myvector contains (middle number [6]:";
    printVector(myvector);
}

void SortingTest::testNthElement()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto printVec = [](auto& vec) {
        std::cout << "{ ";
        for (const auto& elem : vec)
        {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
    };

    std::vector<int> v{ 5, 10, 6, 4, 3, 2, 6, 7, 9, 3 };
    printVec(v);

    auto m = v.begin() + v.size() / 2;
    std::cout << "middle vaule : " << *m << std::endl;
    std::nth_element(v.begin(), m, v.end());
    std::cout << "\nThe median is " << v[v.size() / 2] << '\n';
    // The consequence of the inequality of elements before/after the Nth one:
    assert(std::accumulate(v.begin(), m, 0) < std::accumulate(m, v.end(), 0));
    printVec(v);

    // Note: comp function changed
    std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>{});
    std::cout << "\nThe second largest element is " << v[1] << '\n';
    std::cout << "The largest element is " << v[0] << '\n';
    printVec(v);
}




