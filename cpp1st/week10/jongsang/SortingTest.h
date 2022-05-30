#pragma once
#include <string>

class SortingTest
{
private:
    void debugPrint(std::wstring msg);
public:
    void testSortCppref();
    void testSort();
    void testPartialSort();
    void testNthElement();
};

