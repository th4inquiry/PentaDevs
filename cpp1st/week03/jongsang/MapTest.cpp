#include "MapTest.h"
#include "Person.h"
#include <map>
#include <iostream>

void MapTest::testIndexing()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    std::map<std::wstring, Person> personMap = {
        {L"Codename5", {L"Jack", 39}},
        {L"Codename3", {L"Sam", 21}},
        {L"Codename8", {L"Bill", 32}},
        {L"Codename6", {L"JongSang", 39}}
    };

    // 1. When using operator[], default constructor must exist.
    // 2. operator[] returns the reference.
    std::wcout << L"\n---- temporal instance ---- " << std::endl;
    personMap[L"Codename3"] = Person(L"Hue", 22);
    personMap[L"Codename3"].printInfo();

    std::wcout << L"\n---- move instance ---- " << std::endl;
    personMap[L"Codename2"] = std::move(Person(L"Move", 44));
    personMap[L"Codename2"].printInfo();

    // 3. operator[] adds the element, if the key does not exist.
    // so it is better to find out the element first when accessing the element using operator[].
    std::wcout << L"\n---- find element ---- " << std::endl;
    auto iter = personMap.find(L"Codename2");
    if (iter != std::end(personMap))
    {
        iter->second.printInfo();
    }

    // from C++17
    std::wcout << L"\n---- structual binding ---- " << std::endl;
    for (const auto& [key, data] : personMap)
    {
        std::wcout << key << std::endl;
        data.printInfo();
    }
}

void MapTest::testBasic()
{
    std::wcout << L"\n====" << __FUNCTIONW__ << L"====" << std::endl;

    // map keies are ordered internally
    std::map<std::wstring, Person> personMap = {
        {L"Codename5", {L"Jack", 39}},
        {L"Codename3", {L"Sam", 21}},
        {L"Codename8", {L"Bill", 32}},
        {L"Codename6", {L"JongSang", 39}}
    };

    auto printMapInfo = [&personMap]() {
        for (auto iter = std::cbegin(personMap); iter != std::cend(personMap); ++iter)
        {
            std::wcout << iter->first << std::endl;
            iter->second.printInfo();
        }
    };
    printMapInfo();

    std::wcout << L"\n---- copy instance ---- " << std::endl;
    auto newPair0 = std::make_pair<std::wstring, Person>(L"Codename4", {L"Max", 34});
    personMap.insert(newPair0);
    printMapInfo();

    std::wcout << L"\n---- move instance ----" << std::endl;
    auto newPair1 = std::make_pair<std::wstring, Person>(L"Codename2", {L"Cann", 22});
    personMap.insert(std::move(newPair1));
    printMapInfo();

    std::wcout << L"\n---- initialier_list ----" << std::endl;
    auto ret = personMap.insert({ L"Codename2", {L"Overwrite", 0} });
    if (!ret.second)
    {
        std::wcout << L"Insert failed" << std::endl;
    }
    printMapInfo();

    // from C++17
    std::wcout << L"\n---- one statement for check insert ----" << std::endl;
    if (auto result = personMap.insert({ L"Codename10", {L"Kaila", 28} }); result.second)
    {
        std::wcout << L"Insert succeeded" << std::endl;
    }
    printMapInfo();

    std::wcout << L"\n---- insert_or_assign ----" << std::endl;
    auto re = personMap.insert_or_assign(L"Codename2", Person(L"Overwrite", 0));
    if (!re.second)
    {
        std::wcout << L"Insert failed" << std::endl;
    }
    printMapInfo();


}
