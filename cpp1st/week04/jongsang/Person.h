#pragma once

#include "IPerson.h"
#include <string>
/// <summary>
/// Simple Person class for test
/// </summary>
class Person : public IPerson
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
    virtual ~Person() override;

    bool operator==(const Person& person);

    virtual std::wstring getName() const override;
    virtual int getAge() const override;

    virtual void printInfo() const override;

private:

    std::wstring name{ L"Empty" };
    int age{ 0 };
};

