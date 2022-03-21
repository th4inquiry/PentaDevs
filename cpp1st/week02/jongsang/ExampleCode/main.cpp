// main.cpp : Template test code
//

#include <iostream>
#include "MyArray.h"
#include "MyArrayLimited.h"
#include <vector>

/// <summary>
/// Simple Person class for test
/// </summary>
class Person
{
public:
    // default consturctor
    Person() = default;

    // constructor
    Person(std::wstring _name, int _age) : name(_name), age(_age)
    {
        std::wcout << L"Person consturctor" << std::endl;
    }
    // copy constructor
    Person(const Person& person) : name(person.name), age(person.age)
    {
        std::wcout << L"Person copy constructor" << std::endl;
    }
    // move constructor
    Person(Person&& person) noexcept : name(person.name), age(person.age)
    {
        std::wcout << L"Person move constructor" << std::endl;

        person.name = L"";
        person.age = 0;
    }
    // copy assignment
    Person& operator=(const Person& person) noexcept
    {
        std::wcout << L"Person copy assigment" << std::endl;
        name = person.name;
        age = person.age;
        return *this;
    }
    // move assigment
    Person& operator=(Person&& person) noexcept
    {
        std::wcout << L"Person move assigment" << std::endl;
        name = person.name;
        age = person.age;
        person.name = L"";
        person.age = 0;
        return *this;
    }

    bool operator==(const Person& person)
    {
        return (name.compare(person.name) == 0 && age == person.age);
    }

    ~Person()
    {
        std::wcout << __FUNCTIONW__ << std::endl;
    }

    void printInfo() const
    {
        std::wcout << L"name : " << name << " | age : " << age << std::endl;
    }

private:

    std::wstring name{ L"" };
    int age{ 0 };
};


void testClassTemplate()
{
    std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;

    MyArray<int, 3> myArray = { 1, 2, 3 };
    myArray = { 3, 4, 5 };

    myArray[0] = 100;
    std::wcout << "index 0 : " << myArray[0] << std::endl;

    MyArray<Person, 3> myPersonArray = { {L"JongSang0", 20}, {L"JongSang1", 30}, {L"JongSang2", 40} };
    myPersonArray[0] = Person{ L"Jackson", 10 };

    for (int i = 0; i < 3; ++i)
    {
        myPersonArray[i].printInfo();
    }

    //MyArrayLimited<int, 10> test;

}


/// <summary>
/// Function template test
/// </summary>
static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, T* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

void testFunctionTemplate()
{
    std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;

    // int type deduction
    int myInt = 3, intArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const size_t sizeIntArray = std::size(intArray);
    std::size_t res;
    res = Find(myInt, intArray, sizeIntArray);
    std::wcout << L"(Decution) find result : " << res << std::endl;
    res = Find<int>(myInt, intArray, sizeIntArray);
    std::wcout << L"(Explicit) find result : " << res << std::endl;

    // Person type deduction
    Person person{ L"JongSang", 20 };
    Person personArray[] = { {L"Jacson", 10}, {L"JongSang", 20}, {L"James", 40} };
    const size_t sizeArray = std::size(personArray);
    res = Find(person, personArray, sizeArray);
    std::wcout << L"(Decution) find result : " << res << std::endl;
    res = Find<Person>(person, personArray, sizeArray);
    std::wcout << L"(Explicit) find result : " << res << std::endl;
}

/// <summary>
/// User-defined type deduction
/// </summary>

template <typename T>
class MyContent
{
public:
    MyContent(const T& t) : mContent(t) {}
    const T& getContent() const { return mContent; }
private:
    T mContent;
};

// User-defined deduction
//MyContent(const wchar_t*)->MyContent<MyString>;

void testTemplateTypeDecution()
{
    std::wcout << L"====" << __FUNCTIONW__ << L"====" << std::endl;

    const wchar_t* str = L"User-defined type deduction";
    std::wstring wstr = L"User-defined type deduction";
    MyContent mySpreadsheet(str);
}

int main()
{
    testClassTemplate();
    testFunctionTemplate();
    testTemplateTypeDecution();
}

