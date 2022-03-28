#include "Person.h"
#include <iostream>

// default constructor
Person::Person()
{
    std::wcout << L"Person default constructor" << std::endl;
}
// consturctor
Person::Person(std::wstring _name, int _age) : name(_name), age(_age)
{
    std::wcout << L"Person consturctor" << std::endl;
}
// copy constructor
Person::Person(const Person& person) : name(person.name), age(person.age)
{
    std::wcout << L"Person copy constructor" << std::endl;
}
// move constructor
Person::Person(Person&& person) noexcept : name(person.name), age(person.age)
{
    std::wcout << L"Person move constructor" << std::endl;

    person.name = L"Empty";
    person.age = 0;
}
// copy assignment
Person& Person::operator=(const Person& person) noexcept
{
    std::wcout << L"Person copy assigment" << std::endl;
    name = person.name;
    age = person.age;
    return *this;
}
// move assignment
Person& Person::operator=(Person&& person) noexcept
{
    std::wcout << L"Person move assigment" << std::endl;
    name = person.name;
    age = person.age;
    person.name = L"Empty";
    person.age = 0;
    return *this;
}

bool Person::operator==(const Person& person)
{
    return (name.compare(person.name) == 0 && age == person.age);
}

Person::~Person()
{
    std::wcout << __FUNCTIONW__ << std::endl;
}

void Person::printInfo() const
{
    std::wcout << L"name : " << name << " | age : " << age << std::endl;
}

