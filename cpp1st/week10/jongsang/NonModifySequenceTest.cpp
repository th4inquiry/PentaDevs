#include "NonModifySequenceTest.h"
#include "Person.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>

void NonModifySequenceTest::testAllAnyNoneOf()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    std::vector<Person> vecPerson = {
         {L"Jack", 10},
         {L"Levin", 50},
         {L"Ben", 40},
         {L"Rocky", 22},
         {L"Zenis", 80}
    };


    if (std::all_of(vecPerson.cbegin(), vecPerson.cend(), [](Person p) { return p.getAge() < 90; }))
    {
        std::cout << "All ages are less than 90\n";
    }

    if (std::none_of(vecPerson.cbegin(), vecPerson.cend(), [](Person p) { return p.getAge() == 0; }))
    {
        std::cout << "None of their age are 0\n";
    }

    if (std::any_of(vecPerson.cbegin(), vecPerson.cend(), [](Person p) { return p.getName().compare(L"Ben") == 0; }))
    {
        std::cout << "Ben is there!\n";
    }
}

void NonModifySequenceTest::testForEach()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto printVec = [](auto& vec) {
        for (const auto& elem : vec)
        {
            elem.printInfo();
        }
    };

    std::vector<Person> vecPerson = {
         {L"Jack", 10},
         {L"Levin", 50},
         {L"Ben", 40},
         {L"Rocky", 22},
         {L"Zenis", 80}
    };

    std::cout << "Original : " << std::endl;
    printVec(vecPerson);

    std::for_each(vecPerson.begin(), vecPerson.end(), [](Person& p) {p.setAge(p.getAge() + 2); });

    std::cout << "After : " << std::endl;
    printVec(vecPerson);
}

void NonModifySequenceTest::testFindFirstOf()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    auto printVec = [](auto& vec) {
        for (const auto& elem : vec)
        {
            elem.printInfo();
        }
    };

    std::vector<Person> vecPerson0 = {
         {L"Jack", 10},
         {L"Levin", 50},
         {L"Ben", 40},
         {L"Rocky", 22},
         {L"Zenis", 80}
    };
    std::vector<Person> vecPerson1 = {
         {L"Kail", 10},
         {L"Hue", 50},
         {L"Jeki", 22},
         {L"Ben", 40},
         {L"Kren", 80}
    };

    auto predicate = [](Person& p0, Person& p1) {
        return p0.getName().compare(p1.getName()) == 0;
    };

    std::cout << "Original : " << std::endl;
    printVec(vecPerson0);

    const auto ret = std::find_first_of(vecPerson0.begin(), vecPerson0.end(), vecPerson1.begin(), vecPerson1.end());

    const auto pos = std::distance(vecPerson0.begin(), ret);
    std::cout << "\nResult : postion " << pos << std::endl;
    ret->printInfo();
}
