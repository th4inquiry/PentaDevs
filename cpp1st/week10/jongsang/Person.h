#pragma once

#include <string>
/// <summary>
/// Simple Person class for test
/// </summary>
class Person
{
public:
    enum class DebugSwitch {Off, On};

    // default consturctor
    Person();

    // constructor
    Person(std::wstring _name, int _age, DebugSwitch debugSwitch = DebugSwitch::Off);

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

    const std::wstring getName() const;
    const int getAge() const;

    void setAge(int age);

private:
    void debugPrint(std::wstring msg);

    std::wstring name{ L"Empty" };
    int age{ 0 };
    DebugSwitch debugSwitch{ DebugSwitch::Off };
};

