#pragma once

#include <Windows.h>

class MiniDumpTest
{
public:
    int GenerateDump(EXCEPTION_POINTERS* pExceptionPointers);
    int divide(int a, int b);
    void testMiniDump();
};

