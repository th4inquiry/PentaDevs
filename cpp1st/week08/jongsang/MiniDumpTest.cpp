#include "MiniDumpTest.h"
#include <iostream>
#include <dbghelp.h>
#include <shellapi.h>
#include <shlobj.h>
#include <strsafe.h>

int MiniDumpTest::GenerateDump(EXCEPTION_POINTERS* pExceptionPointers)
{
    BOOL bMiniDumpSuccessful;
    WCHAR szPath[MAX_PATH];
    WCHAR szFileName[MAX_PATH];
    const WCHAR* szAppName = L"ExceptionErrorHandlingTest";
    const WCHAR* szVersion = L"v1.0";
    DWORD dwBufferSize = MAX_PATH;
    HANDLE hDumpFile;
    SYSTEMTIME stLocalTime;
    MINIDUMP_EXCEPTION_INFORMATION ExpParam;

    GetLocalTime(&stLocalTime);

    // MSDN original source
    //GetTempPath(dwBufferSize, szPath);

    // Generate the dump file in the current directory
    StringCchPrintf(szPath, MAX_PATH, L".\\");

    StringCchPrintf(szFileName, MAX_PATH, L"%s%s", szPath, szAppName);
    CreateDirectory(szFileName, NULL);

    StringCchPrintf(szFileName, MAX_PATH, L"%s%s\\%s-%04d%02d%02d-%02d%02d%02d-%ld-%ld.dmp",
        szPath, szAppName, szVersion,
        stLocalTime.wYear, stLocalTime.wMonth, stLocalTime.wDay,
        stLocalTime.wHour, stLocalTime.wMinute, stLocalTime.wSecond,
        GetCurrentProcessId(), GetCurrentThreadId());
    hDumpFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);

    ExpParam.ThreadId = GetCurrentThreadId();
    ExpParam.ExceptionPointers = pExceptionPointers;
    ExpParam.ClientPointers = TRUE;

    bMiniDumpSuccessful = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
        hDumpFile, MiniDumpWithDataSegs, &ExpParam, NULL, NULL);

    return EXCEPTION_EXECUTE_HANDLER;
}


int MiniDumpTest::divide(int a, int b)
{
    if (b == 0)
    {
        throw std::exception();
    }
    return a / b;
}

void MiniDumpTest::testMiniDump()
{
    std::cout << "\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    __try
    {
        auto ret = divide(100, 0);
        std::cout << "ret = " << ret << std::endl;
    }
    __except (GenerateDump(GetExceptionInformation()))
    {
        std::cout << "Exception occurred : mini dump is performed" << std::endl;
    }
}

// Reference : MSDN
