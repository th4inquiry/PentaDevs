// MoveSemantic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "MoveAssignment.h"
#include "MoveConstructor.h"
#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

void testCppRefMoveAss()
{
    using namespace MoveAss;
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

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

void testCppRefMoveCon()
{
    using namespace MoveCon;
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

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

void testRvalueReference()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    Person person0{ L"Jack", 10 };
    Person person1{ L"Tack", 20 };

    auto personMove0 = std::move(person0);
    decltype(auto) personMove1 = std::move(person1);

    std::cout << "persoMove0 type : " << type_id_with_cvr<decltype(personMove0)>().pretty_name() << "\n";
    std::cout << "persoMove1 type : " << type_id_with_cvr<decltype(personMove1)>().pretty_name() << "\n";
}

std::string getName()
{
    return "Alex";
}

void printString(std::string& str)
{
    std::cout << "printString(std::string& str) => " << str << std::endl;
}
void printString(std::string&& str)
{
    std::cout << "printString(std::string&& str) => " << str << std::endl;
}

void testRvalueReference2()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    const std::string& constName = getName();
    //std::string& name = getName();    // error, lvalue reference cannot be initialized to rvalue

    std::string name = "Jack";
    std::string& rName = name;
    printString(rName);

    const std::string&& constRrName = getName();
    std::string&& rrName = getName();
    printString(rrName);

    printString(std::move(rrName));
    printString(getName());
    printString(static_cast<std::string&&>(rrName));

}

void testVectorMove()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    std::vector<Person> personVec0{
        {L"P1", 10},
        {L"P2", 10},
        {L"P3", 10},
        {L"P4", 10},
        {L"P5", 10}
    };

    std::cout << " === vector move === " << std::endl;
    std::vector<Person> personVec1;
    // move constructor/assignment with noexcept makes it call move
    // but, without noexcept, it calls copy
    personVec1 = std::move(personVec0);
    personVec1.push_back(Person(L"P10", 0));
    std::cout << " === vector move end === " << std::endl;

    Person person0{ L"Jack", 0 };
    Person person1 = std::move(person0);
    
}

void foo(Person& person)
{
    std::cout << "foo(Person& person)" << std::endl;
}
void foo(Person&& person)
{
    std::cout << "foo(Person&& person)" << std::endl;
}

template <class T>
void wrapper(T&& arg)
{
    foo(std::forward<T>(arg));
}

void testStdForward()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;

    Person person{ L"person", 0 };
    Person& refPerson = person;

    wrapper(person);
    wrapper(refPerson);
    wrapper(Person{ L"Temp", 0 });

}

void testStdMove()
{
    //template <class _Ty>
    //_NODISCARD constexpr remove_reference_t<_Ty>&& move(_Ty && _Arg) noexcept { // forward _Arg as movable
    //    return static_cast<remove_reference_t<_Ty>&&>(_Arg);
    //}

    Person per{ L"person", 0 };
    Person& refPer = per;
    const Person constPer{ L"const", 0 };
    const Person& constRefPer = per;

    std::move(per);         // per is lavlue, _Ty's type = Person&,  _Arg's type = Person&
    std::move(refPer);      // refPer is lavlue, _Ty's type = Person&,  _Arg's type = Person&
    std::move(constPer);    // constPer is lavlue, _Ty's type = const Person&,  _Arg's type = const Person&
    std::move(constRefPer); // constRefPer is lavlue, _Ty's type = const Person&,  _Arg's type = const Person&
    std::move(Person{ L"Temporal", 0 }); // rvalue, _Ty's type = Person,  _Arg's type = Person&&

}

int main()
{
    testRvalueReference();
    testRvalueReference2();
    testVectorMove();
    testStdMove();
    testStdForward();
    testCppRefMoveCon();
    testCppRefMoveAss();
}

