//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Examples of template in C++


#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

void foo() {
    std::cout << "Call: " << __func__ << endl;
}

int bar(int u, char* c_str) {
    std::cout << "Call: " << __func__ << "(" <<  u << ", " << c_str << ")" << endl;
}

/// Example 1: basic usage of class template
template<typename T>
class TestExample_1 {
public:
    TestExample_1(T param) : data(param) {}

    operator T() { return data; }
    T GetData() const { return data; }
    void SetData(T param) { data = param; }
private:
    T data;
};

/// Example 2: class template
template<typename T>
class TestExample_2 {
public:
    explicit TestExample_2(int a_size) : size(a_size) {
        pt_Data = new T[size];
    }

    ~TestExample_2() { delete [] pt_Data; }

    /// Copy constructor
    TestExample_2(const TestExample_2 &temp) {
        pt_Data = new T[temp.size];
        memcpy(pt_Data, temp.pt_Data, sizeof(T) * temp.size);
        size = temp.size;
    }

    /// Assignment operator
    TestExample_2& operator=(const TestExample_2 &temp) {
        if(this == &temp) {
            return * this;
        }

        delete pt_Data;
        pt_Data = new T[temp.size];
        memcpy(pt_Data, temp.pt_Data, sizeof(T) * temp.size);
        size = temp.size;

        return * this;
    }

    /// Move assignment operator
    TestExample_2& operator=(const TestExample_2 &&temp) {
        pt_Data = temp.pt_Data;
        size = temp.size;
        temp.pt_Data = nullptr;
        temp.size = 0;
    }

    /// Array operator
    T& operator[](int index) {
        if(index < 0 || index >= size) {
            cout << "Error: Index out of range." << endl;
            exit(1);
        }

        return pt_Data[index];
    }

    /// Const-array operator
    T& operator[](int index) const {
        return operator[](index);
    }

    int GetSize() { return size; }

private:
    T * pt_Data = nullptr;
    int size;
};

/// Example 3: member function template
template<typename T>
class TestExample_3 {
public:
    TestExample_3() {};
    T TestFunc() {
        return pt_Data;
    }

protected:
    static T pt_Data;
};

template<typename T>
T TestExample_3<T>::pt_Data = 15;

/// Example 4: function template specialization
template<typename T>
T Add(T a, T b) { return a + b; }

template <>
char * Add(char * left, char * right) {
    int lengthLeft = strlen(left);
    int lengthRight = strlen(right);
    char * string = new char[lengthLeft + lengthRight + 1];

    strcpy_s(string, lengthLeft + 1, left);
    strcpy_s(string + lengthLeft, lengthRight + 1, right);

    return string;
}

/// Example 5: class template specialization
template<typename T>
class TestExample_5 {
public:
    TestExample_5(T parameter) : data(parameter) {}

    T GetData() const { return data; }
    void SetData(T parameter) { data = parameter; }
private:
    T data;
};

template<>
class TestExample_5<char *> {
public:
    TestExample_5(char * parameter) {
        int length = strlen(parameter);
        data = new char[length + 1];
        strcpy_s(data, length, parameter);
    }

    ~TestExample_5() { delete [] data; }
    char * GetData() const { return data; }

private:
    char * data;
};

/// example: function pointer wrapper with NULL checking
template<typename T>
class Test_WrapFuncObj;

template<typename T, typename ... Args>
class Test_WrapFuncObj<T(Args ...)> {
    T (*f)(Args ...);
public:
    Test_WrapFuncObj(T (*t)(Args ...)) {
        f = t;
    }

    T operator()(Args&& ... args) {
        if(f != nullptr) {
            return (*f)(std::forward<Args>(args) ...);
        }
        else {
            return T();
        }
    }
};

class TemplateExample {
public:
    void GoTest();
    void Test1();
    void Test2();
    void Test3();
    void Test4();
    void Test5();
    void Test();
private:
    void Wrapper(void (TemplateExample::*f)());

    void (TemplateExample::*f)();
    int counter = 0;
};

void TemplateExample::Test1() {
    TestExample_1<int> Foo(5);
    cout << Foo << endl;

    TestExample_1<double> Bar(3.14);
    cout << Bar << endl;

    TestExample_1<char *> FooBar("Hello world!");
    cout << FooBar << endl;
}

void TemplateExample::Test2() {
    TestExample_2<int> obj1(5);

    obj1[0] = 1;
    obj1[1] = 2;
    obj1[2] = 3;
    obj1[3] = 4;
    obj1[4] = 5;

    for(int i = 0; i < 5; i++) {
        cout << obj1[i] << "\t";
    }
    cout << endl;

    TestExample_2<int> obj2(3);
    obj2 = obj1;

    for(int i = 0; i < 5; i++) {
        cout << obj2[i] << "\t";
    }
    cout << endl;
}

void TemplateExample::Test3() {
    TestExample_3<double> test;
    cout << test.TestFunc() << endl;
}

void TemplateExample::Test4() {
    int sum_int = Add<int>(3, 4);
    cout << sum_int << endl;

    char * sum_char = Add<char *>("Hello ", "World!");
    cout << sum_char << endl;
    delete[] sum_char;
}

void TemplateExample::Test5() {
    TestExample_5<char *> test("Hello world!");
    cout << test.GetData() << endl;
}

void TemplateExample::Test() {
    Test_WrapFuncObj<void()> wrap_foo(&foo);
    wrap_foo();

    Test_WrapFuncObj<int(int, char*)> wrap_bar(&bar);
    wrap_bar(0, "test");

    Test_WrapFuncObj<void()> wrap_null(nullptr);
    wrap_null();    // prints nothing
}

void TemplateExample::Wrapper(void (TemplateExample::*f)()) {
    counter++;

    cout << "===\tTest-" << counter << " start\t===" << endl;

    (this->*f)();

    cout << "===\tTest-" << counter << " end\t===" << endl;
    cout << endl;
}

void TemplateExample::GoTest() {
    Wrapper(&TemplateExample::Test1);
    Wrapper(&TemplateExample::Test2);
    Wrapper(&TemplateExample::Test3);
    Wrapper(&TemplateExample::Test4);
    Wrapper(&TemplateExample::Test5);
    Wrapper(&TemplateExample::Test);
}

int main(int argc, char * argv[]) {
    TemplateExample templateExample;
    templateExample.GoTest();

    return 0;
}
