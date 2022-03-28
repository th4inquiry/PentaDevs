#include "Person.h"
#include <vector>
#include <iostream>
#include <memory>
#include "VectorTest.h"


void VectorTest::testUniquePtrVector()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    std::vector<std::unique_ptr<Person>> personPtrVec;
    personPtrVec.push_back(std::make_unique<Person>(L"Ptr0", 10));

    auto uPtr = std::make_unique<Person>(L"Ptr1", 20);
    personPtrVec.push_back(std::move(uPtr));
    if (uPtr != nullptr)
    {
        std::wcout << L"uPtr is not null" << std::endl;
    }

    for (const auto& p : personPtrVec)
    {
        p->printInfo();
    }

}


void VectorTest::testIterator()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    // Normally, iterator is faster than indexing except Vector

    // Iterator for int vector
    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    auto intVecIter = std::begin(intVector);
    for (; intVecIter != std::end(intVector); ++intVecIter)
    {
        std::wcout << *intVecIter << L", ";
    }
    std::wcout << std::endl;


    // Iterator for Person vector
    std::vector<Person> personVec = {
        {L"freeman0", 30},
        {L"freeman1", 31},
        {L"freeman2", 32}
    };

    std::vector<Person>::iterator iter = std::begin(personVec);
    for (; iter != std::end(personVec); ++iter)
    {
        iter->printInfo();
    }

    // const iterator
    for (auto it = std::cbegin(personVec); it != std::cend(personVec); ++it)
    {
        it->printInfo();
    }

}

void VectorTest::testVectorAssign()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    std::vector<int> intVec({ 1, 2, 3, 4, 5 });
    intVec.assign({ 6, 7, 8, 9, 10 });
    for (const auto& val : intVec)
    {
        std::wcout << val << L", ";
    }
    std::wcout << std::endl;
    std::vector<int> anotherIntVec = intVec;

    // Lambda expression to print person info from vector<Person>
    auto printPersonInfo = [](const std::vector<Person>& pVec) {
        for (const auto& person : pVec)
        {
            person.printInfo();
        }
    };

    std::vector<Person> personVec = {
        {L"freeman0", 30},
        {L"freeman1", 31},
        {L"freeman2", 32}
    };
    std::vector<Person> anotherPersonVec = personVec;
    printPersonInfo(anotherPersonVec);

    personVec.assign({
        {L"codenameP0", 40},
        {L"codenameP1", 40},
        {L"codenameP2", 40},
        });
    printPersonInfo(personVec);
    personVec.swap(anotherPersonVec);
    printPersonInfo(personVec);
    printPersonInfo(anotherPersonVec);

}

void VectorTest::testPushbackTest()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    std::vector<Person> personVec(5);
    for (const auto& person : personVec)
    {
        person.printInfo();
    }

    std::wcout << L"\n-- copy instance --" << std::endl;
    Person newPerson(L"Copy Man", 0);
    // copy instance
    personVec.push_back(newPerson);

    std::wcout << L"\n-- move instance --" << std::endl;
    Person movePerson(L"Move Man", 0);
    // move instance
    personVec.push_back(std::move(movePerson));
    movePerson.printInfo();

    std::wcout << L"\n-- move temporal instance --" << std::endl;
    // push back temporal instance
    personVec.push_back(Person(L"Test man0", 20));

    // vector size method
    std::wcout << L"\nPerson vector size = " << personVec.size() << std::endl;

    std::wcout << L"\n-- [] indexing --" << std::endl;
    auto somePerson0 = personVec[3];
    somePerson0.printInfo();

    std::wcout << L"\n-- [] and at() indexing (out of range)--" << std::endl;
}

void VectorTest::testFixedSizeVector()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;


    // Lambda expression to print person info from vector<Person>
    auto printPersonInfo = [](const std::vector<Person>& pVec) {
        for (const auto& person : pVec)
        {
            person.printInfo();
        }
    };
    std::wcout << L"-- basic of vector init --" << std::endl;
    std::vector<int> intVec(5, 55);
    std::vector<int> intVecInit = { 1, 2, 3, 4, 5 };
    std::vector<std::wstring> strVec(5, L"StringVector");

    std::vector<Person> personVec(5);
    printPersonInfo(personVec);
    // -> Call Person default contructor 5 times

    std::vector<Person> personVecInit(5, { L"somebody", 10 });
    printPersonInfo(personVecInit);
    // 1. Call Person consturctor of L"somebody" and 10
    // 2. Call copy constructor 5 times
    // 3. Call Person desctructor of #1

    std::vector<Person> personVecInitList{
        { L"Man0", 10 },
        { L"Man1", 20 },
        { L"Man2", 30 }
    };
    printPersonInfo(personVecInitList);
    // 1. Call Person constructor 3 times for each person
    // 2. Call copy constructor 3 times for each person
    // 3. Call Person destructor 3 times of #1


}

void VectorTest::testIndexingOutOfRange()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    std::vector<Person> personVec({
        { L"Man0", 10 },
        { L"Man1", 20 },
        { L"Man2", 30 }
        });

#if 0
    auto somePerson1 = personVec[10];
    // The result of this may be different according to compiler
    // Debug : Run-time error with pop-up window
    // Release : Empty person instance created
#else
    auto somePerson1 = personVec.at(5);
    // Debug : out of range excpetion thrown
    // Release : out of range excpetion thrown

#endif
    somePerson1.printInfo();
}

