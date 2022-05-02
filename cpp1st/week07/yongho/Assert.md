# Assert

In c++, preprocessor indicators such as #error and macros such as asser could be processed.

### <b>Understanding static_assert in C++11</b>

<b>What is static assertion?</b>

Static assertions are a way to check if a condition is true when the code is compiled.

If it isn't, the complier is required to issue an error message and stop the compiling process.

The condition that needs to be checked is a constant expression.

*Performs compile-time assertion checking
*Syntax:
```C++
static_assert(constant_expression, string_literal);
```

<b>How has static assertion been done prior to C++11 standard?</b>

Prior to the C++11 standard the primary mean of producing a compile-time error message was via the #error directive,

which causes the implementation to produce a diagnostic message that includes the message that followed it.

```C++
//Static assertion using #error directive
#include <iostream>
using namespace std;
#if !defined(__penta)
#error "Penta hasn't been defined yet".
#endif
int main()
{
    return 0;
}
```

<b>What is the problem with #error directive?</b>

The #error directive works well will simple tasks. 

However, it fails when compile time assertion needs to be done for complex tasks such as checking the size of a data type using the sizeof operator.

It is because the tokens such as 'sizeof' are not converted to source tokens until after the preprocessing translation stage at 
which point you can no longer use preprocessing directives.

<b>How to do static assertion since C++11 standard?</b>

The C++11 standard introduced a feature named static_assert() which can be used to test a software assertion at the compile time.

Syntax:
```C++
static_assert(constant_expression, string_literal);
Parameter:
constant_expression : An integral constant expression that can be converted to a Boolean.
string_literal: The error message that is displayed when the constant_expression parameter is false.
```

The 'constant_expression' parameter represents a software assertion (a condition that you expect to be true at a particular point in your program)
that needs to be checking during the compile time. 

If the conditions is true, the static_assert declaration has no effect.

If the condition is false, the assertion fails, the compiler displays the message in string_literal parameter and the compilation fails with an error.

It is, however, important to note that the string_listeral parameter is optional.

```C++
//CPP code to demonstrate
//static assertion using static_assert
#include <iostream>
using namespace std;

template <class T, int Size>
class Vector
{
    //Compile time assertion to check if the size of the vector is greater than 3 or not.
    //If any vector is declared whose size is less than 4, the assertion will fail and display the string_literal
    static_assert(Size > 3, "Vector size is too small");
    T m_values[Size];
};

int main()
{
    Vector<int, 4> four; //OK
    Vector<short, 2> two; //Fail

    return 0;
}
```

<b>What are the advantages of static_assert over #error?</b>

1. Unlike #error, assertion using static_assert takes place after the preprocessing translation stage.
Therefore, it is possible to check for the size of a datatype with sizeof using static_assert.

```C++
//Datatype
#include <iostream>

using namespace std;
//No error produced.
//The program compiles well because the size of long datatype is 8 bytes
static_assert(sizeof(long)==8, "ode relies on 'long' being exactly 8 bytes");

int main()
{
    return 0;
}

```

2. Libraries can detect common usage errors at compile time
3. Implementations of the C++ Standard Library can detect and diagnose common usage errors, improving usability.

<b>Declaration Scopes</b>

static_assert can be used in namespace scope, class scope, as well as block scope.

The examples of each of the aforementioned scopes are as follows:

1. Namespace scope:
```C++
//CPP program to illustrate
//declaring static_assert in namespace scope
#include <iostream>
static_assert(sizeof(void*) ==8, "DIAMDL(*LLP64) is not allowed for this module.");

int main()
{
    cout << "Assettion passed. The program disn't product an error";
    return 0;
}
```

2. Class scope
```C++
//CPP code to demonstrate
//static assertion using static_assert
#include <iostream>
using namespace std;

template <class T, int Size>
class Vector
{
    //Compile time assertion to check if the size of the vector is greater than 3 or not.
    //If any vector is declared whose size is less than 4, the assertion will fail and display the string_literal
    static_assert(Size > 3, "Vector size is too small");
    T m_values[Size];
};

int main()
{
    Vector<int, 4> four; //OK
    Vector<short, 2> two; //Fail

    return 0;
}
```

3.Block scope
```C++
//CPP program to illustrate
//declaring static_assert in block scope
template <typename T, int N>
void f()
{
    static_assert(N >=0, "length of array a is negative.");
    T a[N];
}

int main()
{
    //assertion fails here because the length of the array passed is below 0
    f<int, -1>();
    return 0;
}
```

<b>Erroneous static_assert</b>

The constant_expression passed in static_assertion needs to be a valid expression.

```C++
//CPP program to illustrate
//demonstrating an errorneous static_assert declaration

int main()
{
    static_assert(1/0, "never shows up!");
    return 0;
}
```
The expression '1/0' is not a valid constant expression. 

Therefor, When this is compiled, instead of showing the string literal in the static_assert declaration, the compiler issues an error message indicating that the divisor must not be zero.

<br>

### <b>std::abort</b>

Defined in header <cstdlib>

void abort(); (until C++11)
[[noreturn]] void abort() noexcept; (since C++11)

Refer '07_abort_cppref.cpp' file

Causes abnormal program termination unless SIGABRT is being caught by a signal by a signal handler passed to std::signal and the handler does not return.

Destructors of variables with automatic, thread local (since C++11) and static storage durations are not called.

Functions registered with std::atexit() and std::at_quick_exit (since C++11) are also not called.

Whether open resources such as files are closed is implementation defined. 

An implementation defined status is returned to the host environment that indicates unsuccessfule execution.

#### <b>References</b>

<https://docs.microsoft.com/en-us/cpp/cpp/static-assert?view=msvc-170>

<https://en.cppreference.com/w/cpp/language/static_assert>

<https://www.geeksforgeeks.org/understanding-static_assert-c-11/>

Compiler Explorer

<https://godbolt.org/>

Understanding Lvalues, PRvalues and Xvalues in C/C++ with Examples

<https://www.geeksforgeeks.org/understanding-lvalues-prvalues-and-xvalues-in-ccwith-examples/?ref=rp>
