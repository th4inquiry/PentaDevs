#pragma once
#include "Person.h"
#include <vector>

class AutoDeduction
{
public:
    void testTypeDeduction0();
    void testTypeDeduction1();
    void testTypeDeduction2();
    void testTypeDeduction3();

private:
    std::vector<Person>& addElem(std::vector<Person>& perVector, std::wstring name);
};

