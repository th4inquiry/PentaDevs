
#include "SmartPtrTest.h"
#include <iostream>
#include <memory>

int main()
{
    SmartPtrTest uniPtrTest;
    uniPtrTest.testUniquePtrBasic();
    uniPtrTest.testUniquePtrMethod();
    uniPtrTest.testUniquePtrCustomDeleter();
}

