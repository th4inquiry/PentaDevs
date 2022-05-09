#include "ExceptionTest.h"
#include "MyExceptionError.h"

#include <fstream>
#include <iostream>

void ExceptionTest::throwRunTimeError()
{
    throw runtime_error("Throw runtime error");
}

void ExceptionTest::throwStdException()
{
    throw exception("Throw std::exception");
}

void ExceptionTest::throwNewException()
{
    const std::string fileName = "test.txt";
    ifstream inputStream(fileName);
    if (inputStream.fail())
    {
        throw MyFileOpenError(fileName);
    }
}

void ExceptionTest::testBasicException(int select)
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    try
    {
        switch (select)
        {
        case 0: throwStdException(); break;
        case 1: throwRunTimeError(); break;
        case 2: throwNewException(); break;
        }
    }
    catch (const runtime_error& e)
    {
        cout << "runtimte error!!" << endl;
        cout << e.what() << endl;
    }
    catch (const exception& e)
    {
        cout << "std::excpetion error!!" << endl;
        cout << e.what() << endl;
    }
}
