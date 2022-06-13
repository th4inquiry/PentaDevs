#include <iostream>

//https://en.cppreference.com/w/cpp/language/override
//Specifies that a virtual function overrides

struct A
{
    virtual void foo();
    void bar();
    A();
    virtual ~A();
};

//member functions definitions of struct A:
void A::foo() 
{ 
    std::cout << "A::foo();\n"; 
}

A::A() 
{ 
    std::cout << "A::A(); constructor\n"; 
}

A::~A() 
{ 
    std::cout << "A::~A(); destructor\n"; 
}

struct B : A
{
// void foo() const override; //Error: B::foo does not override A::foo // (signature mismatch)                               

void foo() override; //OK: B::foo overrides A::foo
//void bar() override;  //Error: A::bar is not virtual
B();
~B() override;  // OK: 'override' can also be applied to virtual
                //special member functions, e.g. destructors
void override(); //OK, member function name, not a reserved keyword

};

//member function definitions of struct B:
void B::foo() 
{
    std::cout << "B::foo();\n";
}

B::B()
{
    std::cout << "B::B(); constructor\n";
}

B::~B()
{
    std::cout << "B::~B(); destructor\n";
}

void B::override()
{
    std::cout << "B::override();\n";
}

int main()
{
    B b;
    b.foo();
    b.override(); //OK, invoke the member function 'override()'
    int override{42};   //OK, defines an integer variable
    std::cout << "override: " << override << std::endl;
}