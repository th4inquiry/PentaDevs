#pragma once

#include <string>
/// <summary>
/// Simple Person class for test
/// </summary>
class Person
{
public:
    // default consturctor
    Person();

    // constructor
    Person(std::wstring _name, int _age);

    // copy constructor
    Person(const Person& person);

    // move constructor
    Person(Person&& person) noexcept;

    // copy assignment
    Person& operator=(const Person& person) noexcept;

    // move assigment
    Person& operator=(Person&& person) noexcept;
    
    // Destructor
    virtual ~Person();

    bool operator==(const Person& person);
    void printInfo() const;

private:

    std::wstring name{ L"Empty" };
    int age{ 0 };
};

