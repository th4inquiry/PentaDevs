
# Value category

Each C++ expression (an operator with its operands, a literal, a variable name, etc.) is characterized by two independent properties: a type and a value category. Each expression has some non-reference type, and each expression belongs to exactly one of the three primary value categories: prvalue, xvalue, and lvalue.Every C++ expression has a type, and belongs to a value category. The value categories are the basis for rules that compilers must follow when creating, copying, and moving temporary objects during expression evaluation.

```
              expression
            /           \
        glvaule        rvalue
       /       \      /      \
    lvalue      xvalue       prvalue
```

The C++17 standard defines expression value categories as follows:

A ```glvalue``` is an expression whose evaluation determines the identity of an object, bit-field, or function.<br>
A ```prvalue``` is an expression whose evaluation initializes an object or a bit-field, or computes the value of the operand of an operator, as specified by the context in which it appears.<br>
An ```xvalue``` is a glvalue that denotes an object or bit-field whose resources can be reused (usually because it is near the end of its lifetime).<br>
An ```lvalue``` is a glvalue that is not an xvalue.<br>
An ```rvalue``` is a prvalue or an xvalue.<br>
<br>

### Example of xvalue (C++ Standard $7.2.1)
*In general, the effect of this rule is that __named rvalue references__ are treated as __lvalues__ and __unnamed rvalue references__
to objects are treated as __xvalues__; rvalue references to functions are treated as lvalues whether named or not.*
```cpp
struct A {
    int m;
};

A&& operator+(A, A);
A&& f();

A a;
A&& ar = static_cast<A&&>(a);
```
The expressions ```f()```, ```f()```.m, ```static_cast```<A&&>(a), a+a are ```xvalues```. <br>
The expression ```ar``` is an ```lvalue```.   
<br>

### History
**C++11**<br>
With the introduction of move semantics in C++11, value categories were redefined to characterize two independent properties of expressions:

```has identity```: it's possible to determine whether the expression refers to the same entity as another expression, such as by comparing addresses of the objects or the functions they identify (obtained directly or indirectly)<br>
```can be moved from```: move constructor, move assignment operator, or another function overload that implements move semantics can bind to the expression.   
<br>

## Reference
1. https://docs.microsoft.com/en-us/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-170
2. https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe
3. International Standard ISO/IEC 14482, Programming languages - C++, Sixth edition, 2020-12
<br><br><br><br>

# Move semantics
In general, move semantics allows us to take an object from the current context and pass it to another one, avoiding copy when the original object is not needed anymore.
## Motivation
```cpp
#include <iostream>
 
using namespace std;
 
vector<int> doubleValues (const vector<int>& v)
{
    vector<int> new_values;
    new_values.reserve(v.size());
    for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr; ++itr )
    {
        new_values.push_back( 2 * *itr );
    }
    return new_values; // create temporal object with copy constructor, but it may be optimized
}
 
int main()
{
    vector<int> v;
    for ( int i = 0; i < 100; i++ )
    {
        v.push_back( i );
    }
    v = doubleValues( v ); // copied from temproal object returend by function
}
```
In C++03, there is no avoiding that the assignments to v will have to copy all the values again, which requires a new memory allocation and another iteration over the entire vector. <br>
The object returned from doubleValues is a temporary value that's no longer needed. <br>
When you have the line ```v = doubleValues( v )```, the result of doubleValues( v ) is just going to get thrown away once it is copied. <br>
In C++03, the answer is that there was no way to tell if an object was a temporary or not, you had to run the same code in the assignment operator or copy constructor, no matter where the value came from, so no pilfering was possible

<br>

## Rvalue reference
An ```rvalue reference``` is a reference to an rvalue. In particular, it is a concept that is applied when the
rvalue is a temporary object or an object that is explicitly moved using std::move(). The purpose of an rvalue reference is to make it possible for a particular function
overload to be chosen when an rvalue is involved. This allows certain operations that normally
involve copying large values to instead copy pointers to those values.<br>
A function can specify an rvalue reference parameter by using ```&&``` as part of the parameter specification,
for example, ```type&& name```. Normally, a temporary object will be seen as a const type&,
but when there is a function overload that uses an rvalue reference, a temporary object can be
resolved to that overload.<br><br>

Example 1
```cpp
void handleMessage(string& message) // lvalue reference parameter
{
    cout << format("handleMessage with lvalue reference: {}", message) << endl;
}
void handleMessage(string&& message) // rvalue reference parameter
{
    cout << format("handleMessage with rvalue reference: {}", message) << endl;
}
...
string a {"Hello"};
handleMessage(a);   //Calls handleMessage(string& value)

string b { "World" };
handleMessage(a + b); // Calls handleMessage(string&& value)

handleMessage("Hello World"); // Calls handleMessage(string&& value)
```
<br>
Example 2<br>

```cpp
// named-reference.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
    // TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
    cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
    cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block)
{
    // block is named rvalue reference => lvalue 
    g(block);
    return move(block);
}

int main()
{
    g(f(MemoryBlock()));
}
```
Output :
```cpp
In g(const MemoryBlock&).
In g(MemoryBlock&&).
```
<br>

Example 3<br>
You can cast an lvalue to an rvalue reference.
```cpp
// cast-reference.cpp
// Compile with: /EHsc
#include <iostream>
using namespace std;

// A class that contains a memory resource.
class MemoryBlock
{
   // TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
   cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
   cout << "In g(MemoryBlock&&)." << endl;
}

int main()
{
   MemoryBlock block;
   g(block);
   g(static_cast<MemoryBlock&&>(block));
}
```
output :
```cpp
In g(const MemoryBlock&).
In g(MemoryBlock&&).
```
<br><br>

## Move constructor

syntax of move constructor
```cpp
classname ( classname&& ) // Typical declaration of a move constructor
```
Example
```cpp
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
 
struct A
{
    std::string s;
    int k;
    A() : s("test"), k(-1) { }
    A(const A& o) : s(o.s), k(o.k) { std::cout << "move failed!\n"; }
    A(A&& o) noexcept :
           s(std::move(o.s)),       // explicit move of a member of class type
           k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
    { }
};
 
A f(A a)
{
    return a;
}
 
struct B : A
{
    std::string s2;
    int n;
    // implicit move constructor B::(B&&)
    // calls A's move constructor
    // calls s2's move constructor
    // and makes a bitwise copy of n
};
 
struct C : B
{
    ~C() { } // destructor prevents implicit move constructor C::(C&&)
};
 
struct D : B
{
    D() { }
    ~D() { }          // destructor would prevent implicit move constructor D::(D&&)
    D(D&&) = default; // forces a move constructor anyway
};
 
int main()
{
    std::cout << "Trying to move A\n";
    A a1 = f(A()); // return by value move-constructs the target
                   // from the function parameter
    std::cout << "Before move, a1.s = " << std::quoted(a1.s)
        << " a1.k = " << a1.k << '\n';
    A a2 = std::move(a1); // move-constructs from xvalue
    std::cout << "After move, a1.s = " << std::quoted(a1.s)
        << " a1.k = " << a1.k << '\n';
 
    std::cout << "Trying to move B\n";
    B b1;
    std::cout << "Before move, b1.s = " << std::quoted(b1.s) << "\n";
    B b2 = std::move(b1); // calls implicit move constructor
    std::cout << "After move, b1.s = " << std::quoted(b1.s) << "\n";
 
    std::cout << "Trying to move C\n";
    C c1;
    C c2 = std::move(c1); // calls copy constructor
 
    std::cout << "Trying to move D\n";
    D d1;
    D d2 = std::move(d1);
}

// output:
// Trying to move A
// Before move, a1.s = "test" a1.k = -1
// After move, a1.s = "" a1.k = 0
// Trying to move B
// Before move, b1.s = "test"
// After move, b1.s = ""
// Trying to move C
// move failed!
// Trying to move D
```
<br>

## Move assignment operator
syntax of move assignment operator
```cpp
classname& classname::operator= ( classname&& ) // Typical declaration of a move assignment operator
```
Example
```cpp
#include <string>
#include <iostream>
#include <utility>
 
struct A
{
    std::string s;
    A() : s("test") { }
    A(const A& o) : s(o.s) { std::cout << "move failed!\n"; }
    A(A&& o) : s(std::move(o.s)) { }
    A& operator=(const A& other)
    {
         s = other.s;
         std::cout << "copy assigned\n";
         return *this;
    }
    A& operator=(A&& other)
    {
         s = std::move(other.s);
         std::cout << "move assigned\n";
         return *this;
    }
};
 
A f(A a) { return a; }
 
struct B : A
{
     std::string s2; 
     int n;
     // implicit move assignment operator B& B::operator=(B&&)
     // calls A's move assignment operator
     // calls s2's move assignment operator
     // and makes a bitwise copy of n
};
 
struct C : B
{
    ~C() { } // destructor prevents implicit move assignment
};
 
struct D : B
{
    D() { }
    ~D() { } // destructor would prevent implicit move assignment
    D& operator=(D&&) = default; // force a move assignment anyway 
};
 
int main()
{
    A a1, a2;
    std::cout << "Trying to move-assign A from rvalue temporary\n";
    a1 = f(A()); // move-assignment from rvalue temporary
    std::cout << "Trying to move-assign A from xvalue\n";
    a2 = std::move(a1); // move-assignment from xvalue
 
    std::cout << "Trying to move-assign B\n";
    B b1, b2;
    std::cout << "Before move, b1.s = \"" << b1.s << "\"\n";
    b2 = std::move(b1); // calls implicit move assignment
    std::cout << "After move, b1.s = \"" << b1.s << "\"\n";
 
    std::cout << "Trying to move-assign C\n";
    C c1, c2;
    c2 = std::move(c1); // calls the copy assignment operator
 
    std::cout << "Trying to move-assign D\n";
    D d1, d2;
    d2 = std::move(d1);
}

// output:
// Trying to move-assign A from rvalue temporary
// move assigned
// Trying to move-assign A from xvalue
// move assigned
// Trying to move-assign B
// Before move, b1.s = "test"
// move assigned
// After move, b1.s = "" 
// Trying to move-assign C
// copy assigned
// Trying to move-assign D
// move assigned
```
## Rule of five
When you declare one or more of the special member functions (destructor,
copy constructor, move constructor, copy assignment operator, and move
assignment operator), then you typically need to declare all of them. This is called
the rule of five. You either provide explicit implementations for them or explicitly
default (=default) or delete (=delete) them.
## Rule of zero
The rule of zero states that you should design your classes in such a way that they do not require
any of those five special member functions. How do you do that? Basically, you should avoid having
any old-style dynamically allocated memory. Instead, use modern constructs such as Standard
Library containers. For example, use a vector instead of the
pointer data member in the class. The vector handles memory
automatically, so there is no need for any of those five special member functions.

<br>

## Refernece
1. https://iteo.medium.com/c-move-semantics-and-rvalue-references-explained-7efb7cf79a56
2. https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
3. Professional C++, 5th edition
4. https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170
5. https://en.cppreference.com/w/cpp/language/move_constructor
6. https://en.cppreference.com/w/cpp/language/move_assignment
<br><br><br><br>

# std::move

```cpp
// STRUCT TEMPLATE remove_reference
template <class _Ty>
struct remove_reference {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty;
};

template <class _Ty>
struct remove_reference<_Ty&> {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty&;
};

template <class _Ty>
struct remove_reference<_Ty&&> {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty&&;
};

template <class _Ty>
using remove_reference_t = typename remove_reference<_Ty>::type;

// FUNCTION TEMPLATE move
template <class _Ty>
_NODISCARD constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept { // forward _Arg as movable
    return static_cast<remove_reference_t<_Ty>&&>(_Arg);
}
```
### const type argument

```cpp
class string 
{
public:
    string(const string& rhs); // copy constructor
    string(string&& rhs); // move constructor
    ...
}
...
class Annotation
{
public:
    explicit Annotation(const std::string text)
    : value(std::move(text)) // copy contructor is called because of const type
    {
        ...
    }

private:
    std::string value;
}

```
<br>

# Forwarding reference (Universal reference)
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
A forwarding reference is an rvalue reference to a cv-unqualified template parameter.

```cpp
template <class T> int f(T&& heisenreference);
template <class T> int g(const T&&);
int i;
int n1 = f(i); // calls f<int&>(int&)
int n2 = f(0); // calls f<int>(int&&)
int n3 = g(i); // error : would call g<int>(const int&&), which would bind on an rvalue reference to an lvalue

// Reference : 13.10.3.2 of C++ Standard
```
```auto&&``` case
```cpp
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    auto&& r0 = x;  // int &
    auto&& r1 = rx; // int &
    auto&& r2 = cx; // const int &
    auto&& r3 = crx;// const int &
    auto&& r4 = 100;// int &&

    //const auto&& cr0 = x;   // error
    const auto&& cr0_move = std::move(x);

    //const auto&& cr1 = rx;  // error
    const auto&& cr1_move = std::move(rx);

    //const auto&& cr2 = cx;  // error
    //const auto&& cr3 = crx; // error
    const auto&& cr4 = 100;
```
<br>

# Perfect forwarding
## std::forward
std::forward casts the argument as rvalue only when it is rvalue.
```cpp
void process(const Widget& lvalArg);
void process(Widget&& rvalArg);

template <typename T>
void logAndProcess(T&& param) // T&& : forwarding reference
{
    auto now = std::chrono::system_clock::now();
    makeLogEntry("Calling 'process'", now);
    process(std::forward<T>(param));
}
...

Widget w;
logAndProcess(w);       // call as lvaule
logAndProcess(std::move(w)); // call as rvalue 
```

## Motivation of Perfect forwarding
Let's design a perfect factory method, which is a totally generic factory method. In particular, that means that the function should have the following characteristics : <br>

- Can take an arbitrary number of arguments
- Can accept lvalues and rvalues as an argument
- Forwards it arguments identical to the underlying constructor
<br>

Step1
```cpp
#include <iostream>

template <typename T,typename Arg>
T create(Arg& a) // take its argument by reference
{
  return T(a);
}

int main()
{
  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  // Rvalues
  int myFive2= create<int>(5);  // error, Arg& cannot take rvalue
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::cout << std::endl;

}
// Problem : It cannot take rvalue
```

Step2
```cpp
// perfectForwarding2.cpp

#include <iostream>

template <typename T,typename Arg>
T create(Arg& a)
{
  return T(a);
}

template <typename T,typename Arg>
T create(const Arg& a)
{
  return T(a);
}

int main()
{
  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  // Rvalues
  int myFive2= create<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::cout << std::endl;

}

// output:
// myFive: 5
// myFive2 : 5

// Problem : 
// 1. Cannot call T move constructor
// 2. To support n different arguments, I have to overload many variations of the function template
```

Step3
```cpp
// perfectForwarding3.cpp

#include <iostream>

template <typename T,typename Arg>
T create(Arg&& a)
{
  return T(std::forward<Arg>(a));
}

int main()
{
  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  // Rvalues
  int myFive2= create<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::cout << std::endl;

}

```
To achieve perfect forwarding you have to combine a universal reference with std::forward. std::forward<Arg>(a) returns the underlying type because a is a universal reference. Therefore, an rvalue remains an rvalue.

Now to the pattern
```cpp
template<class T>
void wrapper(T&& a){
    func(std::forward<T>(a)); 
}
```
## Reference
1. https://www.modernescpp.com/index.php/perfect-forwarding
2. Effective Modern C++
3. http://thbecker.net/articles/rvalue_references/section_01.html
4. PentaDevs/cpp1st/week06/taehwan/README.md