#include <iostream>
#include <functional>

//int TestFunc1(int param)
//{
//    std::cout << "Function Pointer" << param << std::endl;
//    return param;
//}

void TestFunc2(const char* functionName, std::function<int(const char*, int)> param)
{
    std::cout << functionName << std::endl;
    param("Hello", 10);
}

int main()
{
    std::cout << "***Begin***" << std::endl;

    ::TestFunc2(
        "TestFunc2()",
        [](const char* functionName, int param)->int
        {
            std::cout << functionName << " : " << param << std::endl;
            return 0;
        }
    );


    std::cout << "***End***" << std::endl;

    //auto func = [](int param) -> int
    //{
    //    std::cout << "Lambda: " << param << std::endl;
    //    return param;
    //};

    //call lambda
    //func(5);

    ////call by function pointer
    //auto functionPointer = TestFunc1;
    //functionPointer(10);

    return 0;
}