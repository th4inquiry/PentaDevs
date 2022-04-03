#include "SmartPtrTest.h"
#include "Person.h"
#include <memory>
#include <iostream>

using namespace std;

void SmartPtrTest::testUniquePtrBasic()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    // create unique pointer
    std::wcout << L"--- create unique ptr ---" << std::endl;
    unique_ptr<IPerson> personUP0 = make_unique<Person>(L"jack", 20);
    personUP0->printInfo();
    (*personUP0).printInfo();

    // swap 
    std::wcout << L"--- swap unique ptr ---" << std::endl;
    unique_ptr<IPerson> personUP1 = make_unique<Person>(L"Peter", 10);
    personUP0.swap(personUP1);
    personUP0->printInfo();
    personUP1->printInfo();

    // move unique pointer
    std::wcout << L"--- move unique ptr ---" << std::endl;
    personUP0 = std::move(personUP1);
    if (personUP1 == nullptr)
    {
        personUP0->printInfo();
    }
}

void SmartPtrTest::testUniquePtrMethod()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    // reset unique pointer
    std::wcout << L"--- reset unique ptr ---" << std::endl;
    unique_ptr<IPerson> personUP0 = make_unique<Person>(L"jack", 20);
    personUP0->printInfo();
    personUP0.reset(new Person(L"jongsang", 40));

    // get raw pointer
    std::wcout << L"--- get raw ptr ---" << std::endl;
    auto personPtr = personUP0.get();
    std::wcout << L"Name : " << personPtr->getName() << L" | Age : " << personPtr->getAge() << std::endl;

    // release unique pointer
    std::wcout << L"--- release unique ptr ---" << std::endl;
    auto ptr = personUP0.release();
    if (personUP0 == nullptr)
    {
        std::wcout << L"Name : " << personPtr->getName() << L" | Age : " << personPtr->getAge() << std::endl;
    }
}

void SmartPtrTest::testUniquePtrCustomDeleter()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    auto deletePerson = [](Person* person) {
        std::wcout << L"Custom deleter called" << std::endl;
        delete person;
    };
    unique_ptr<Person, decltype(deletePerson)> customPerson0( new Person(L"CustomDeletTest0", 33), deletePerson);
    customPerson0->printInfo();

    auto tempDeleter = customPerson0.get_deleter();
    std::wcout << L"deletePerson addr : " << std::addressof(deletePerson) << std::endl;
    std::wcout << L"tempDeleter addr : " << std::addressof(tempDeleter) << std::endl;

}


