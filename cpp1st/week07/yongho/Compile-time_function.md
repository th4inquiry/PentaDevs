# Compile-time function execution

## Terms
<br>

#### <b>Constant Expressions</b>

* A constant expression is an expression that can be evaluated at compile time. Compiler can determine a value of expression at compile time.

* Constants of integral or enumerated type are required in several different situaltions, such as array bounds, enumerator values, and case labels.

* Null pointer constants(NULL) are a special case of integral constants.


#### <b>Integral Constant Expressions</b>

* An integral constant expression is an expression that can be evaluated at compile time, and whose type is integral or an enumeration.

* The situation that require integral constant expression include array bounds, enumerator values, case labels, bit-field sizes, static member initializers, and value template arguments. 

* The compiler must be able to evaluate the expression at compile time, so you can use only literals, enumerators, const objects that have constant initializers, integral or enumerated template parameters, sizeof expressions and constant addresses. 

* The address of a static lvalue object is a constant address, as is the address of a fuction.

* A string literal, being a static array of characters, is also a constant address.

* An integral static const data member can be initialized in the class definition if the initializer is a constant or enumerated expression.

* The member can then be used as a constant expression elsewhere in the class definition.

* For example

```C++
enum A { a = number, b, c}

template<typename T, size_t size>
class array {
    public:
        static const size_t SIZE = size;
        ...
    privates:
        T data[SIZE];
};
```

<b>Top-Level const</b> 

* As we've seen, a pointer is an object that can point to a different object.

* As a result, we can talk independently about whether a pointer is const and whether the objects to which it can point are const.

* We use the term top-level const to indicate that the pointer itself is a const. 

* When a pointer can point to a const object, we refer to that const as a low-level const.

<b>Two type of constant</b>

* listeral type
    * void, scalar type, reference type, an array of literal type, class type that has all of the following properties
    ```C++
    bool isChanged = true; //bool literal 'true'
    int xValue {5}; //interal literal '5'
    std::cout << 2*3 //'2','3' are integral literal
    double pi {3.14159}; //'3.14159' is a double literal
    double abogadro {6.02e23}; // "6.02 x 10^23" is literal
    double electron {1.6e-19}; // "1.6 x 10^-19" is literal
    unsigned int nValue {5u};
    long nValue2 {5L}; 
    float fValue {5.0f};
    char c='A'; //'A' is a char literal
    std::cout << "Hello,world!"; //"Hello,world" is a C-style string literal
    std::cout << "Hello,""world!"; //C++ will concatenate sequential string literals
    ```

* symbolic type
    * The symbolic constants are constant identifier. Before the symbolic constants are used they be initialized.
    * So, after a symbolic constant is initialized as per the rules, its value cannot be changed during program execution.
    * Using 'const' keyword

    ```C++
    const float PI = 3.1417;
    ```
    * Using 'define' directive

    ```C++
    #define PI 3.1417;
    ```

    | **Define Directive**	 | **const Qualifier**	 |
    | :--: | :--: |
    | It is used as preprocessor directive	 | It is used as statement	 |
    | It is not terminated with semicolon(;) | It is terminated with semicolon.	 |
    | Data type of constant identifier is not specified	| Data type of constant identifier is specified	|

<br>

## constexpr specifier (since c++11)

The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.

Such variables and functions can then be used where only compile time constant expressions are allowed (provided that appropriate arguments are given).

A constexpr specifier used in an object declaration or non-static member function (until C++14) implies const.

A constexpr specifier used in a function or static data member (since c++17) declaration implies inline.

If any declaration of a function or function template has a constexpr specifier, then every declaration must contain that specifier.

Constant expression: 

Integral constant expression:

Advantages
A constant expression
* can be evaluated at compile time
* give the compiler deep insight into the code
* are implicitly thread-safe
* can be constructed in the read-only memory (ROM-able).

Three Forms

<b>Constexpr Variables</b>

The primary difference between const and constexpr variables is that the initialization of a const variable can be deferred until run time.

A constexpr variable must be initialized at compile time. All const variable are const.

* A variable can be declared with constexpr, when it has a literal type and is initialized. If the initialization is performed by a constructor, the constructor must be declared as constexpr. (have to be initialized by a constant exxpression)

* A reference may be declared as constexpr when both these conditions are met: The referenced object is initialized by a constant expression, and any implicit conversions invoked during initialization are also constant expressions.

* All declarations of a constexpr variable or function must have the constexpr specifier.

```C++
constexpr double pi = 3.14;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; //Error! Not Initialized
int j=0;
constexpr int k = j + 1; //Error! j is not a constant expression
```

<b>Constexpr Functions</b>

A constexpr function is one whose return value is computable at compile time when consuming code requires it.

Consuming code requires the return value at compile time to initialize a constexpr variable,or to provide a non-type tempate argument. (자료형이 아닌 템플레이트 매개변수)

When its argument are constexpr values, a constexpr function produces a compile-time constant.

When called with non-constexpr arguments, or when its value isn't required at compile time, it produces a value at run time like a regular function.
(This dual behavior saves you from having to write constexpr and non-constexpr versions of the save function.)

constexpr functions in C++14 are quite comfortable. They can
* invoke other constexpr functions
* can have variables that have to be initialized by a constant expression
* can conditional expressions or loops
* are implicit inline
* cannot have static or thred_local data

User-defined types
* have to have a constructor which is a constant expression
* cannot have virtual functions
* cannot have a virtual base class
The rules for constexpr functions or methods are quite simple. In short, I call both functions.

constexpr functions can only depend on functionality which is a constant expression.

It's often a question of the compiler and the optimization level if a contexpr function runs at compile time or runtime.

1. The constexpr function is executed in a context that is evaluated at compile time.

This can be a static_assert expression such as with the type-traits library or the initialization of a C-array.

2. The value of a constexpr function is requested during compile time with constexpr: constexpr auto res = func(5);

Review sample code "04_1_ConstExpr_Function.cpp"


## Understanding constexpr specifier in C++

constexpr is a feature added in C++11.

The main idea is performance improvement of programs by doing computations at compile time rather than run time.

Note that once a program is compiled and finalized by developer, it is run multiple times by users.

The idea is to spend time in compilation and save time at run time (similar to template metaprogramming)

constexpr specifies that the value of an object or a function can be evaluated at compile time and the expression can be used in other constant expressions.

For example, in below code product() is evaluated at compile time.

```C++
//constexpr function for product of two numbers.
//By specifying constexpr, we suggest compiler to 
// evaluate value at compile time

constexpr int product(int x, int y)
{
    return (x*y);
}

int main()
{
    contexpr int x = product(10, 20);
    cout << x;
    return 0;
}
```

A function be declared as constexpr

1. In C++11, a constexpr function should contain only one return statement. C++14 allows more than one statement.
2. constexpr function should refer only to constant global variables.
3. constexpr can call only other contexpr function not simple function.
4. Function should not be of a void type and some operators like prefix increment (++v) are not allowed in constexpr function.

constexpr vs inline functions : Both are for performance improvements, inline functions request the compiler to expand at compile
time and save time of function call overheads. In inline functions, expressions are always evaluated at run time.
constexpr is different, here expressions are evaluated at compile time. 

Example of performance improvement by constexpr: Consider the following C++ program

```C++
//A C++ program to demonstrate the use of constexpr
#include <iostream>
using namespace std;

constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}

int main()
{
    //value of res is computed at compile time.
    constexpr long int res = fib(30);
    cout << res;
    return 0;
}
```

When the above program is run on GCC, it takes 0.003 seconds (We can measure time using time command)
If we remove const from below line, then the value of fib(5) is not evaluated at compile time, because result of constexpr is not used in const expression.

```C++
//Change,
    constexpr long int res = fib(30);
//To,
    long int res = fib(30);
```

After making above change, time taken by program becomes higher 0.017 seconds.

constexpr with constrcutors:
constexpr can be used in constructors and objects also.

```C++
// C++ program to demonstrate uses of constexpr in constructor
#include <bits/stdc++.h>
using namespace std;
 
// A class with constexpr constructor and function
class Rectangle
{
    int _h, _w;
public:
    // A constexpr constructor
    constexpr Rectangle (int h, int w) : _h(h), _w(w) {}
     
    constexpr int getArea () { return _h * _w; }
};
 
// driver program to test function
int main()
{
    // Below object is initialized at compile time
    constexpr Rectangle obj(10, 20);
    cout << obj.getArea();
    return 0;
}
```

<b>constexpr vs const</b>

* The serve different purpose. constexpr is mainly for optimization while const is for practically const objects like value of PI.

* Unlike const, constexpr can also be applied to functions and class constructors.

* Both of them can be applied to member methods.

* Member methods are made const to make sure that there are no accident changes by the method.

* On the other hand, the idea of using constexpr is to compute exressions at compile time so that time can be saved when code is run.

* const can only be used with non-static member function whereas constexpr can be used with member and non-member functions,

* even with constructors but with condition that argument and return type must be of literal types.

<br>

#### <b>Compilation Steps</b>

Phases of translation

<https://en.cppreference.com/w/cpp/language/translation_phases>

Preprocessor

<https://en.cppreference.com/w/cpp/preprocessor>

Compilation Steps

<https://www.microforum.cc/blogs/entry/37-about-translation-units-and-how-c-code-is-compiled/>

Back to Basics: Compiling and Linking -Ben Saks-CppCon 2021

<https://www.youtube.com/watch?v=cpkDQaYttR4>

<br>

### <b>References</b>

<https://en.wikipedia.org/wiki/Compile-time_function_execution>

<https://en.cppreference.com/w/cpp/language/constexpr>

<https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-170>

<https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/>

<https://www.modernescpp.com/index.php/c-core-guidelines-programming-at-compile-time-with-constexpr>

<https://www.oreilly.com/library/view/c-in-a/059600298X/ch03s03.html>

<https://www.oreilly.com/library/view/c-primer-fifth/9780133053043/ch02lev2sec15.html>

Thread Local Storage
<https://docs.microsoft.com/en-us/windows/win32/procthread/thread-local-storage?redirectedfrom=MSDN>

Compiler Explorer

<https://godbolt.org/>

Understanding Lvalues, PRvalues and Xvalues in C/C++ with Examples

<https://www.geeksforgeeks.org/understanding-lvalues-prvalues-and-xvalues-in-ccwith-examples/?ref=rp>
