
#include "VectorTest.h"
#include "MapTest.h"
#include <vector>
#include <iostream>

int main()
{
    try
    {
        VectorTest vectorTest;
        vectorTest.testUniquePtrVector();
        vectorTest.testFixedSizeVector();
        vectorTest.testVectorAssign();

        MapTest mapTest;
        mapTest.testBasic();
        mapTest.testIndexing();

        // Exception could occur here
        vectorTest.testIndexingOutOfRange();
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << "\n!!! Exception catched : "<< ex.what() << std::endl;
    }
    catch (...)
    {
        std::wcout << "\n!!! Exception catched" << std::endl;
    }


}

