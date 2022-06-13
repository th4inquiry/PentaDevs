# Object Oriented Design, Overloading and Overriding in C++
## Object-oriented programming
As the name suggests uses objects in programming.
Object-oriented programming aims to implement real-world entities like inheritance, 
hiding, polymorphism, etc in programming. The main aim of OOP is to bind together 
the data and the functions that operate on them so that no other part of the code 
can access this data except that function.

### Class
The building block of C++ that leads to Object-Oriented programming is a Class.
It is a user-defined data type, which holds its own data members and member functions, 
which can be accessed and used by creating an instance of that class. 
A class is like a blueprint for an object.

* A Class is a user-defined data-type which has data members and member functions.
* Data members are the data variables and member functions are the functions used 
to manipulate these variables and together these data members and member functions 
define the properties and behaviour of the objects in a Class.

### Object
An Object is an identifiable entity with some characteristics and behaviour. 
An Object is an instance of a Class. When a class is defined, no memory is allocated 
but when it is instantiated (i.e. an object is created) memory is allocated.

### Encapsulation in C++
In normal terms Encapsulation is defined as wrapping up of data and information under 
a single unit. In Object Oriented Programming, Encapsulation is defined as binding 
together the data and the functions that manipulates them.
Encapsulation also lead to data abstraction or hiding. As using encapsulation also 
hides the data.

```c++
#include <iostream>
using namespace std;
  
class Encapsulation
{
    private:
        // data hidden from outside world
        int x;
          
    public:
        // function to set value of 
        // variable x
        void set(int a)
        {
            x = a;
        }
          
        // function to return value of
        // variable x
        int get()
        {
            return x;
        }
};

int main()
{
    Encapsulation obj;
      
    obj.set(5);
      
    cout << obj.get();
    return 0;
}
```

Access specifiers plays an important role in implementing encapsulation in C++.
The process of implementing encapsulation can be sub-divided into two steps:
* The data members should be labeled as private using the ```private``` access specifiers
* The member function which manipulates the data members should be labeled as 
public using the ```public``` access specifier

## Abstraction in C++
Data abstraction is one of the most essential and important feature of object oriented 
programming in C++. Abstraction means displaying only essential information and hiding 
the details. Data abstraction refers to providing only essential information about 
the data to the outside world, hiding the background details or implementation.

Abstraction using Classes: We can implement Abstraction in C++ using classes.
Class helps us to group data members and member functions using available access 
specifiers. A Class can decide which data member will be visible to outside world and 
which is not.

Abstraction in Header files: One more type of abstraction in C++ can be header files. 
For example, consider the pow() method present in math.h header file. 
Whenever we need to calculate power of a number, we simply call the function pow() present 
in the math.h header file and pass the numbers as arguments without knowing the underlying 
algorithm according to which the function is actually calculating power of numbers.

### Abstraction using access specifiers
Access specifiers are the main pillar of implementing abstraction in C++. 
We can use access specifiers to enforce restrictions on class members. For example:
* Members declared as ```public``` in a class, can be accessed from anywhere in the program.
* Members declared as ```private``` in a class, can be accessed only from within the class. 
They are not allowed to be accessed from any part of code outside the class.

```c++
#include <iostream>
using namespace std;
  
class ImplementAbstraction
{
    private:
        int a, b;
  
    public:
      
        // method to set values of 
        // private members
        void set(int x, int y)
        {
            a = x;
            b = y;
        }
          
        void display()
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
};
  
int main() 
{
    ImplementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}
```

Advantages of Data Abstraction:
* Helps the user to avoid writing the low level code
* Avoids code duplication and increases reusability.
* Can change internal implementation of class independently without affecting the user.
Helps to increase security of an application or program as only important details are
provided to the user.

## Inheritance in C++
The capability of a class to derive properties and characteristics from another class 
is called Inheritance. Inheritance is one of the most important features of Object-Oriented 
Programming.

Inheritance is a feature or a process in which, new classes are created from the existing 
classes. The new class created is called “derived class” or “child class” and the existing 
class is known as the “base class” or “parent class”. The derived class now is said to be 
inherited from the base class.

When we say derived class inherits the base class, it means, the derived class inherits 
all the properties of the base class, without changing the properties of base class and 
may add new features to its own. These new features in the derived class will not affect 
the base class. The derived class is the specialized class for the base class.

* Sub Class: The class that inherits properties from another class is called Subclass or 
Derived Class.
* Super Class: The class whose properties are inherited by a subclass is called Base Class 
or Superclass.

```c++
#include <bits/stdc++.h>
using namespace std;
 
// Base class
class Parent {
public:
    int id_p;
};
 
// Subclass inheriting from Base class(Parent)
class Child : public Parent {
public:
    int id_c;
};
 
// main function
int main()
{
    Child obj1;
 
    // An object of class child has all data members
    // and member functions of class parent
    obj1.id_c = 7;
    obj1.id_p = 91;
    cout << "Child id is: " << obj1.id_c << '\n';
    cout << "Parent id is: " << obj1.id_p << '\n';
 
    return 0;
}
```

Modes of Inheritance: There are 3 modes of inheritance.

* Public Mode: If we derive a subclass from a public base class.
Then the public member of the base class will become public in the derived class and 
protected members of the base class will become protected in the derived class.
* Protected Mode: If we derive a subclass from a Protected base class. Then both public 
members and protected members of the base class will become protected in the derived class.
* Private Mode: If we derive a subclass from a Private base class. 
Then both public members and protected members of the base class will become Private 
in the derived class.

## Polymorphism in C++
The word polymorphism means having many forms. In simple words, we can define 
polymorphism as the ability of a message to be displayed in more than one form.

In C++ polymorphism is mainly divided into two types: Compile time Polymorphism and Runtime Polymorphism

1. Compile time Polymorphism

* Function Overloading: When there are multiple functions with same name but different 
parameters then these functions are said to be overloaded. Functions can be overloaded 
by change in number of arguments or/and change in type of arguments.

```c++
// C++ program for function overloading
#include <bits/stdc++.h>
  
using namespace std;
class Example
{
    public:
      
    // function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }
      
    // function with same name but 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }
      
    // function with same name and 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};
  
int main() {
      
    Example obj1;
      
    // Which function is called will depend on the parameters passed
    // The first 'func' is called 
    obj1.func(7);
      
    // The second 'func' is called
    obj1.func(9.132);
      
    // The third 'func' is called
    obj1.func(85, 64);
    return 0;
} 
```

* Operator Overloading: C++ also provide option to overload operators. 
For example, we can make the operator (‘+’) for string class to concatenate two strings. 
We know that this is the addition operator whose task is to add two operands. 
So a single operator ‘+’ when placed between integer operands , adds them and when 
placed between string operands, concatenates them.

```c++
// CPP program to illustrate
// Operator Overloading
#include <iostream>
using namespace std;
   
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0)  {real = r;   imag = i;}
       
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};
   
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
}
```

2. Runtime Polymorphism
* Function overriding on the other hand occurs when a derived class has a definition 
for one of the member functions of the base class. That base function is said to be 
overridden.

```c++
// C++ program for function overriding
  
#include <bits/stdc++.h>
using namespace std;
  
class base
{
public:
    virtual void print()
    { cout << "print base class" << endl; }
   
    void show()
    { cout << "show base class" << endl; }
};
   
class derived : public base
{
public:
    void print() // print () is already virtual function in derived class, 
                 // we could also declare as virtual void print() explicitly
    { cout << "print derived class" << endl; }
   
    void show()
    { cout << "show derived class" << endl; }
};
  
// main function
int main() 
{
    base *bptr;
    derived d;
    bptr = &d;
       
    // Virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 
       
    // Non-virtual function, binded at compile time
    bptr->show(); 
  
    return 0;
} 
```

## Message Passing
Objects communicate with one another by sending and receiving information to each other.
A message for an object is a request for execution of a procedure and therefore will 
invoke a function in the receiving object that generates the desired results. 
Message passing involves specifying the name of the object, the name of the function 
and the information to be sent.

## Dynamic Binding
In dynamic binding, the code to be executed in response to function call is decided
at runtime. C++ has virtual functions to support this.

## Override Specifier (since C++11)
Specifies that a virtual function overrides another virtual function.

```c++
#include <iostream>
 
struct A
{
    virtual void foo();
    void bar();
    virtual ~A();
};
 
// member functions definitions of struct A:
void A::foo() { std::cout << "A::foo();\n"; }
A::~A() { std::cout << "A::~A();\n"; }
 
struct B : A
{
//  void foo() const override; // Error: B::foo does not override A::foo
                               // (signature mismatch)
    void foo() override; // OK: B::foo overrides A::foo
//  void bar() override; // Error: A::bar is not virtual
    ~B() override; // OK: `override` can also be applied to virtual
                   // special member functions, e.g. destructors
    void override(); // OK, member function name, not a reserved keyword
};
 
// member functions definitions of struct B:
void B::foo() { std::cout << "B::foo();\n"; }
B::~B() { std::cout << "B::~B();\n"; }
void B::override() { std::cout << "B::override();\n"; }
 
int main() {
    B b;
    b.foo();
    b.override(); // OK, invokes the member function `override()`
    int override{42}; // OK, defines an integer variable
    std::cout << "override: " << override << '\n';
}
```

## Virtual Function Specifier
The ```virtual``` specifier specifies that a non-static member function is virtual 
and supports dynamic dispatch. It may only appear in the ```decl-specifier-seq``` of the 
initial declaration of a non-static member function (i.e., when it is declared in the 
class definition).

```c++
#include <iostream>
 
struct Base
{
    virtual void f()
    {
        std::cout << "base\n";
    }
};
 
struct Derived : Base
{
    void f() override // 'override' is optional
    {
        std::cout << "derived\n";
    }
};
 
int main()
{
    Base b;
    Derived d;
 
    // virtual function call through reference
    Base& br = b; // the type of br is Base&
    Base& dr = d; // the type of dr is Base& as well
    br.f(); // prints "base"
    dr.f(); // prints "derived"
 
    // virtual function call through pointer
    Base* bp = &b; // the type of bp is Base*
    Base* dp = &d; // the type of dp is Base* as well
    bp->f(); // prints "base"
    dp->f(); // prints "derived"
 
    // non-virtual function call
    br.Base::f(); // prints "base"
    dr.Base::f(); // prints "base"
}
```

### Reference
[[1] GeeksForGeeks. 2022. Object-Oriented Programming in C++.](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/) <br>
[[2] C++ Reference. 2022. virtual function specifier.](https://en.cppreference.com/w/cpp/language/virtual) <br>
[[3] C++ Reference. 2022. override specifier (since C++11).](https://en.cppreference.com/w/cpp/language/override) <br>