#pragma once

#include <vector>
#include <string>

using namespace std;

class ExceptionTest
{
public:
    void throwRunTimeError();
    void throwStdException();
    void throwNewException();
    void testBasicException(int select);
};

