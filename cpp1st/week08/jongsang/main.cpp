// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ExceptionTest.h"
#include "MiniDumpTest.h"
#include <iostream>


void unhandledExceptionHandler()
{
    std::cout << "==> uncaught exception" << std::endl;
    exit(1);
}

int main()
{
    MiniDumpTest miniDumpTest;
    miniDumpTest.testMiniDump();

    ExceptionTest exceptionTest;
    exceptionTest.testBasicException(0);
    exceptionTest.testBasicException(1);
    exceptionTest.testBasicException(2);

    // unhandled exception test
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    set_terminate(unhandledExceptionHandler);

    int cmd;
    std::cout << "Input the number : ";
    std::cin >> cmd;
    if (cmd == 1)
    {
        std::cout << "Unhandled exception occured!!" << std::endl;
        throw exception();
    }

    std::cout << "Now program will be terminated..." << std::endl;

    return 0;

}

