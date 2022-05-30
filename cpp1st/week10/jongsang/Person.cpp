#include "Person.h"
#include <iostream>

// defautl constructor
Person::Person()
{
    debugPrint( L"Person default constructor");
}
// consturctor
Person::Person(std::wstring _name, int _age, DebugSwitch _debugSwitch) 
    : name(_name),
    age(_age),
    debugSwitch(_debugSwitch)
{
    debugPrint( L"Person consturctor");
}
// copy constructor
Person::Person(const Person& person) 
    : name(person.name),
    age(person.age)
{
    debugPrint( L"Person copy constructor");
}
// move constructor
Person::Person(Person&& person) noexcept 
    : name(std::move(person.name)),
     age(person.age)
{
    debugPrint( L"Person move constructor");
}
// copy assignment
Person& Person::operator=(const Person& person) noexcept
{
    debugPrint( L"Person copy assigment");
    name = person.name;
    age = person.age;
    return *this;
}
// move assigment
Person& Person::operator=(Person&& person) noexcept
{
    debugPrint( L"Person move assigment");
    name = std::move(person.name);
    age = person.age;
    person.age = 0;
    return *this;
}

bool Person::operator==(const Person& person)
{
    return (name.compare(person.name) == 0 && age == person.age);
}

Person::~Person()
{
    debugPrint( __FUNCTIONW__);
}

void Person::printInfo() const
{
    std::wcout << L"name : " << name << " | age : " << age << std::endl;
}

const std::wstring Person::getName() const
{
    return this->name;
}

const int Person::getAge() const
{
    return this->age;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::debugPrint(std::wstring msg)
{
    if (debugSwitch == DebugSwitch::On)
    {
        std::wcout << msg << std::endl;
    }
}

