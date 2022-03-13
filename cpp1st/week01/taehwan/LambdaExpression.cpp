//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Examples of Lambda Expression in C++


#include <iostream>
#include <functional>

using namespace std;

class LambdaExample {
public:
    void goTest();
    void test1();
    void test2();
};

/// test function for example
void testFuncForTest2(char* pszParam, std::function<int(char*, int)> param) {
    cout << pszParam << endl;
    param("Hello", 10);
}

/// test1: basic usage of lambda expression
void LambdaExample::test1() {
    cout << "**** begin test1 ****" << endl;

    /// declaration and definition of lambda expression
    auto func = [](int nParam) -> int {
        cout << "Lambda: " << nParam << endl;

        return nParam;
    };

    /// invocation of lambda expression
    /// output -> Lambda: 5
    func(5);

    /// invocation using function pointer
    /// output -> Lambda: 10
    auto pfTest = func;
    pfTest(10);

    cout << "**** end test1 ****" << endl;

}

/// test2: usage of lambda expression for another function's parameter
void LambdaExample::test2() {
    cout << "**** begin test2 ****" << endl;

    /// output -> Hello : 10
    ::testFuncForTest2(
            "TestFunc()",

            /// describes a lambda function as real parameter of the test function
            [](char *pszParam, int nParam)->int {
                cout << pszParam << " : " << nParam << endl;

                return 0;
            }

    );

    cout << "**** end test2 ****" << endl;
}

void LambdaExample::goTest() {
    test1();
    test2();
}

int main(int argc, char * argv[]) {
    LambdaExample example;
    example.goTest();

    return 0;
}