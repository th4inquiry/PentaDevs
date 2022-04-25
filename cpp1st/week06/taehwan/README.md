# Type Deduction

## (```auto```-related) Template Type Deduction
General problem:

```c++
template<typename T>
void f(ParamType param);
f(expr);        // deduce T and ParamType from expr
```
Given type of ```expr```, what are these types?
* ```T```: The deduced type.
* ```ParamType```: Often different from ```T``` (e.g., ```const T&```)

Three general cases:
* ```ParamType``` is a reference or pointer, but not a universal reference.
* ```ParamType``` is a universal reference.
* ```ParamType``` is neither reference nor pointer.

## Non-URef Reference/Pointer Parameters
Type deduction very simple:
* If ```expr```'s type is a reference, ignore that.
* Pattern-match ```expr```'s type against ```ParamType``` to determine T.

```c++
template<typename T>
void f(T& param);           // param is a reference
                            // Note: T not a reference

int x = 22;                 // int
const int cx = x;           // copy of int
const int& rx = x;          // ref to const view of int
f(x);                       // T ≡ int, param's type ≡ int&
f(cx);                      // T ≡ const int, param's type ≡ const int&
f(rx);                      // T ≡ const int, param's type ≡ const int&
```

```ParamType``` of ```const T&``` ⇒ ```T``` changes, but ```param```'s type doesn't:

```c++
template<typename T>
void f(const T& param);     // param is a const reference
                            // Note: T not a reference

int x = 22;                 // as before
const int cx = x;           // as before
const int& rx = x;          // as before
f(x);                       // T ≡ int, param's type ≡ const int&
f(cx);                      // T ≡ int, param's type ≡ const int&
f(rx);                      // T ≡ int, param's type ≡ const int&
```

Behaviors with pointers essentially the same:

```c++
template<typename T>
void f(T* param);           // param now a pointer
                            // Note: T not a reference

int x = 22;                 // int
const int *pcx = &x;        // ptr to const view of int
f(x);                       // T ≡ int, param's type ≡ int*
f(pcx);                     // T ≡ const int, param's type ≡ const int*
```

## ```auto``` and Non-URef Reference/Pointer Variables
```auto``` plays role of ```T```:

```c++
int x = 22;                 // as before
const int cx = x;           // as before
const int& rx = x;          // as before

auto& v1 = x;               // v1's type ≡ int&, auto ≡ int
auto& v2 = cx;              // v2's type ≡ const int&, auto ≡ const int
auto& v3 = rx;              // v3's type ≡ const int&, auto ≡ const int
const auto& v4 = x;         // v4's type ≡ const int&, auto ≡ int
const auto& v5 = cx;        // v5's type ≡ const int&, auto ≡ int
const auto& v6 = rx;        // v6's type ≡ const int&, auto ≡ int
```

## Universal References
```c++
template<typename T>
void f(T&& param);
f(expr);
```
Treated like "normal" reference parameters, except:
* If ```expr``` is lvalue with deduced type ```E```, ```T``` deduced as ```E&```
  * Reference-collapsing yields type ```E&``` for ```param```.

```c++
template<typename T>
void f(T&& param);

int x = 22;                 // as before
const int cx = x;           // as before
const int& rx = x;          // as before
f(x);                       // x is lvalue ⇒ T ≡ int&, param's type ≡ int&
f(cx);                      // cx is lvalue ⇒ T ≡ const int&, param's type ≡ const int&
f(rx);                      // rx is lvalue ⇒ T ≡ const int&, param's type ≡ const int&
f(22);                      // x is rvalue ⇒ no special handling; T ≡ int, param's type ≡ int&&
```

## By-Value Parameters
Deduction rules a bit different:
* As before, if ```expr```'s type is a reference, ignore that.
* If ```expr``` is ```const``` or ```volatile```, ignore that.
* ```T``` is the result.

```expr```'s reference-/```const```-qualifiers always dropped in deducing ```T```.

```c++
template<typename T>
void f(T param);            // param passed by value

int x = 22;                 // as before
const int cx = x;           // as before
const int& rx = x;          // as before
f(x);                       // T ≡ int, param's type ≡ int
f(cx);                      // T ≡ int, param's type ≡ int
f(rx);                      // T ≡ int, param's type ≡ int
```

## Non-Reference Non-Pointer ```auto```s
auto again plays role of ```T```, and again, ```Expr```'s reference-/```const```-qualifiers always dropped in deducing ```T```.
* ```auto``` never deduced to be a reference.
  * It must be manually added. If present, use by-reference rulesets.

```c++
int x = 22;                 // as before
const int cx = x;           // as before
const int& rx = x;          // as before

auto v1 = x;                // v1's type ≡ int (auto ≡ int)
auto v2 = cx;               // v2's type ≡ int (auto ≡ int)
auto v3 = rx;               // v3's type ≡ int (auto ≡ int)
auto& v4 = rx;              // v4's type ≡ const int& (auto ≡ int)
auto&& v5 = rx;             // v5's type ≡ const int& (rx is lvalue, auto ≡ int)
```

## ``` const expr```s vs. ```expr```s Containing ```const```
From earlier:
* If ```expr``` is ```const``` or ```volatile```, ignore that.

More common wording:
* Top-level ```const```/```volatile``` is ignored.

```c++
void someFunc(const int * const param1,     // const ptr to const
              const int *       param2,     // ptr to const
                    int *       param3)     // ptr to non-const
{ 
    auto p1 = param1;       // p1's type ≡ const int * (param1's constness ignored)
    auto p2 = param2;       // p2's type ≡ const int *
    auto p3 = param3;       // p3's type ≡ int *
    ...
} 
```

## Special Cases
Special treatment for ```expr```s that are arrays or functions:
* When initializing a reference, array/function type deduced.
* Otherwise ```decay```s to a pointer before type deduction.

## ```auto``` Type Deduction
Same as template type deduction, except with braced initializers.
* Template type deduction fails.
* ```auto``` deduces ```std::initializer_list```.

```c++
template<typename T>
void f(T param);

f( { 1, 2, 3 } );           // error! type deduction fails
auto x1 { 1, 2, 3 };        // x's type ≡ std::initializer_list<int>
auto x2 = { 1, 2, 3 };      // x's type ≡ std::initializer_list<int>
```

Per N3922:
* Current rules for ```auto``` + copy list initialization (with "=").
* For ```auto``` + direct list initialization (without "="):
  * 1 element in braces ⇒ ```auto``` deduces type of element.
  * \>1 element ⇒ error (ill-formed).

If rules in N3922
```c++
auto x1 { 1, 2, 3 };        // error! direct init w/>1 element
auto x2 = { 1, 2, 3 };      // as in C++14, x2's type ≡ std::initializer_list<int>
auto x3 { 17 };             // direct init w/1 element, x3's type ≡ int
auto x4 = { 17 };           // as in C++14, x4's type ≡ std::initializer_list<int>
```
In C++14, all deduce ```std::initializer_list<int>```.

## Lambda Capture Type Deduction
Three kinds of capture:
* By reference: uses template type deduction (for reference params).
* C++14's init capture: uses ```auto``` type deduction.
* By value: uses template type deduction, except cv(```const``` and ```volatile```)-qualifiers are retained.

Simply by-value capture ≠ by-value init capture:

```c++
{
    const int cx = 0;
    auto lam = [cx] { ... };
    ...
}

class UpToTheCompiler11 {
    private:
    const int cx;
    ...
};
```
```c++
{
    const int cx = 0;
    auto lam = [cx = cx] { ... };
    ...
}

class UpToTheCompiler14 {
    private:
    int cx;
    ...
};
```

```const``` retention normally masked by default ```const```ness of operator():
```c++
{
    int cx = 0;                             // now non-const
    auto lam = [cx] { cx = 10; };           // error!
    ...
}

class UpToTheCompiler {
public:
    void operator()() const { cx = 10; }    // cause of error
private:
    int cx;
};
```

```mutable``` lambdas reveal the truth:
```c++
{
    const int cx = 0;                       // now const
    auto lam = [cx] mutable { cx = 10; };   // still error!
    ...
}

class UpToTheCompiler {
public:
    void operator()() { cx = 10; }
private:
    const int cx;                           // cause of error
};
```

## Observing Deduced Types
During compilation:
* Use declared-only template with type of interest:
```c++
template<typename T>                        // declaration for TD
class TD;                                   // TD == "Type Displayer"

template <typename T>                       // template w/types
void f(T& param)                            // of interest
{
    TD<T> tType;                            // cause T to be shown
    TD<decltype(param)> paramType;          // ditto for param's type
}
```

```c++
int x = 22;                         // as before
const int& rx = x;                  // as before
f(rx);                              // compiler diagnostics show types
```

gcc 4.8 (excerpt):

```c++
error: 'TD<const int> tType' has incomplete type
error: 'TD<const int &> paramType' has incomplete type
```

VS2013 (excerpt):

```c++
error C2079: 'tType' uses undefined class 'TD<T>'
        with
        [
            T=const int
        ]
        
error C2079: 'paramType' uses undefined class 'TD<T &>'
        with
        [
            T=const int
        ]        
```

Clang 3.2 (excerpt):
```c++
error: implicit instantiation of undefined template 'TD<const int>'
error: implicit instantiation of undefined template 'TD<const int &>'
```

* For ```auto``` variables, use ```decltype``` to get type:
```c++
int x = 22;                     // as before
const int& rx = x;              // as before

auto y = rx;                    // compiler diagnostics show type
TD<decltype(y)> yType;
```

gcc 4.8 (excerpt):

```c++
error: aggregate 'TD<int> yType' has incomplete type and cannot be defined
```

VS2013 (excerpt):

```c++
error C2079: 'yType' uses undefined class 'TD<int>'
```

Clang 3.2 (excerpt):
```c++
error: implicit instantiation of undefined template 'TD<int>'
```

* Avoid ```std::type_info::name``` for runtime deduction.
  * Language rules require incorrect results in some cases!

```c++
template<typename T>        // bad example using typeid()
void f(const T& param)
{
    using std::cout;
    cout << "T =        " << typeid(T).name() << '\n';      // show T
    cout << "param =    " << typeid(param).name() << '\n';  // show param's type
}
```

* Boost.TypeIndex provides accurate information for runtime deduction:
```c++
#include <boost/type_index.hpp>

template<typename T>        // good example using Boost.TypeIndex
void f(const T& param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    
    cout << "T =        "       // show T
         << type_id_with_cvr<T>.pretty_name() << '\n';
    cout << "param =    "       // show param's type
         << type_id_with_cvr<decltype(param)>().pretty_name()
         << '\n';
    ...
}
```

## ```decltype``` Type Deduction
```decltype(name)``` ≡ declared type of ```name```. Unlike ```auto```:
* Never strips ```const```/```volatile```/references.

```c++
int x = 10;             // decltype(x) ≡ int
const auto& rx = x;     // decltype(rx) ≡ const int&
```

```decltype(Lvalue expr of type T)``` ≡ ```T&```.
* Unsurprising. Almost all such expressions really have type ```T&```.

```c++
// return type is lvalue expr and has lvalue-reference type
const std::vector<Widget>& findVec(const VecHandle&);
```

* Exceptions act as if they did.
```c++
int arr[10];

arr[0] = 5;         // arr[0]'s type is int, but it acts like int&

decltype(arr[0]);   // ≡ int&, because arr[0] is lvalue expression
```

* Full rules for ```decltype``` more complex.
  * Relevant only to hard-core library developers.
  * Rules we've seen suffice for almost everybody almost all the time.

## Function Return Type Deduction
In C++11:
* Limited: single-statement lambdas only.

In C++14:
* Extensive: all lambdas + all functions.
  * Understanding type deduction more important than ever.

Deduced return type specifiers:
* ```auto```: Use template (not ```auto```!) type deduction rules.
  * No type deduced for braced initializers.
* ```decltype(auto)```: Use ```decltype``` type deduction rules.

```decltype(auto)``` sensitive to function implementation:
```c++
decltype(auto) lookupValue (context information)
{
    static std::vector<int> values = initValues();
    int idx = compute index values from context info;
    auto retVal = values[idx];      // retVal's type is int
    return retVal;                  // returns int
}

decltype(auto) lookupValue (context information)
{
    static std::vector<int> values = initValues();
    int idx = compute index values from context info;
    auto retVal = values[idx];      // retVal's type is int
    return (retVal);                // returns int& (to local variable!)
}
```

Rules of thumb:
* Use ```auto``` if a reference type would never be correct.
* Use ```decltype(auto)``` only if a reference type could be correct.

### Reference
[[1] Scott Meyers. 2014. Type Deduction and Why You Care. Video. CppCon.](https://youtu.be/wQxj20X-tIU) <br>
[[2] Scott Meyers. 2012. Universal References in C++11. Standard C++ Foundation.](https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers) <br>
[[3] C++ reference. 2022. std::decay.](https://en.cppreference.com/w/cpp/types/decay) <br>
[[4] C++ reference. 2022. std::initializer_list.](https://en.cppreference.com/w/cpp/utility/initializer_list) <br>
[[5] James Dennett. 2014. New Rules for auto deduction from braced-init-list. ISO/IEC JTC1.](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html) <br>
[[6] C++ reference. 2022. Lambda expressions (since C++11).](https://en.cppreference.com/w/cpp/language/lambda) <br>
[[7] C++ reference. 2022. cv (const and volatile) type qualifiers.](https://en.cppreference.com/w/cpp/language/cv) <br>
[[8] C++ reference. 2022. Placeholder type specifiers (since C++11).](https://en.cppreference.com/w/cpp/language/auto) <br>
[[9] C++ reference. 2022. decltype specifier.](https://en.cppreference.com/w/cpp/language/decltype) <br>
[[10] Antony Polukhin. 2015. Boost.TypeIndex 4.0. boost.org.](https://www.boost.org/doc/libs/1_59_0/doc/html/boost_typeindex.html) <br>
[[11] C++ reference. 2022. Templates.](https://en.cppreference.com/w/cpp/language/templates) <br>
[[12] Thomas Becker. 2013. C++ auto and decltype Explained.](http://thbecker.net/articles/auto_and_decltype/section_01.html) <br>
