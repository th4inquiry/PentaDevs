#include <iostream>
#include <map>
#include <string>

using namespace std::string_literals; // enables s-suffix for std::string literals

// alias template
template <class T>
using IndexedMap = std::map<int, T>;

class TemplateTest
{
public:
    void testAll();
    void testAliasTemplate();

private:
    IndexedMap<std::string> indexMap_;
};

void TemplateTest::testAll()
{
    testAliasTemplate();
}

void TemplateTest::testAliasTemplate()
{
    indexMap_[indexMap_.size()] = "1st test item"s;
    indexMap_[indexMap_.size()] = "2nd test item"s;

    // range-based for loop
    for (auto i : indexMap_)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }
}


int main()
{
    TemplateTest tester;
    tester.testAll();

    auto s = "test string, okay"s;
    // Range-based for statements with initializer ISO/IEC JTC1 SC22 WG21 P0614R1
    for (auto p = s.substr(s.find("str")); auto i : p) // needs compiler option /std:c++20 or /std:c++latest
    {
        std::cout << i << std::endl;
    }

    return 0;
}
