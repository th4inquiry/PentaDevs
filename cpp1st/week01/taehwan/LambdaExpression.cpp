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
    void test3();
    void test4();
};

/// test class for example
class testClassForTest3 {
public:
    testClassForTest3() {
        array = {60, 20, 30, 80, 50};
    }

    void Print() {
        for(auto &n : array)
            cout << n << '\t';

        cout << endl;
    }

    void Sort(function<int(int, int)> cmp) {
        sort(array.begin(), array.end(), cmp);
    }

private:
    array<int, 5> array;
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

/// test3: Sort using function object as lambda expression
void LambdaExample::test3() {
    cout << "**** begin test3 ****" << endl;

    testClassForTest3 testClass;
    testClass.Sort([](int a, int b)->int { return a < b; });
    testClass.Print();

    testClass.Sort([](int a, int b)->int { return b < a; });
    testClass.Print();

    cout << "**** end test3 ****" << endl;
}

/// test4: basic usages of lambda capture
void LambdaExample::test4() {
    cout << "**** begin test4 ****" << endl;

    auto nData = 10;
    cout << nData << endl;

    auto TestFunc1 = [nData] {   /// by-copy capture, [nData] is same as [nData](void)->void
        cout << nData << endl;
    };
    TestFunc1();

    auto TestFunc2 = [nData](void) mutable -> void {    /// by-copy capture, it allows to change the value, but restrict to inner
        cout << ++nData << endl;
    };
    TestFunc2();
    cout << nData << endl;      /// the nData value is not changed

    auto a = 10, b = 20, c = 0;
    auto TestFunc3 = [a, b]() -> int {      /// multiple by-copy capture
        return a + b;
    };
    cout << TestFunc3() << endl;

    auto TestFunc4 = [&]()->int {       /// default by-reference capture
        return ++a + ++b;
    };
    cout << TestFunc4() << endl;

    auto TestFunc5 = [=, &c] {      /// default by-copy capture
        c = a + b;
        return c;
    };
    cout << TestFunc5() << endl;

    cout << "**** end test4 ****" << endl;
}

void LambdaExample::goTest() {
    test1();
    test2();
    test3();
    test4();
}

int main(int argc, char * argv[]) {
    LambdaExample example;
    example.goTest();

    return 0;
}