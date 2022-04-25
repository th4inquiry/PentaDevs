#include "AutoDeduction.h"
#include <iostream>

void AutoDeduction::testTypeDeduction0()
{
    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    auto& r0 = x;   // int &
    auto& r1 = rx;  // int &
    auto& r2 = cx;  // const int &
    auto& r3 = crx; // const int &

    int* px = &x;
    int* &rpx = px;
    //int*& rpx2 = &x; // error
    int* const& crpx = &x;
    const int* const& ccrpx = &x;

    auto& r4 = px;   // int*&
    auto& r5 = rpx;  // int*&
    auto& r6 = crpx; // int* const&
    auto& r7 = ccrpx;// const int* const&
}

void AutoDeduction::testTypeDeduction1()
{
    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    auto&& r0 = x;  // int &
    auto&& r1 = rx; // int &
    auto&& r2 = cx; // const int &
    auto&& r3 = crx;// const int &
    auto&& r4 = 100;// int &&
}

void AutoDeduction::testTypeDeduction2()
{
    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;
    int x = 10;
    int& rx = x;
    const int cx = x;
    const int& crx = x;

    auto r0 = x;   // int
    auto r1 = rx;  // int
    auto r2 = cx;  // int
    auto r3 = crx; // int

    int* px = &x;
    int*& rpx = px;
    //int*& rpx2 = &x; // error
    int* const& crpx = &x;
    const int* const& ccrpx = &x;

    auto r4 = px;   // int*
    auto r5 = rpx;  // int*
    auto r6 = crpx; // int*
    auto r7 = ccrpx;// const int*
}

std::vector<Person>& AutoDeduction::addElem(std::vector<Person>& perVector, std::wstring name)
{
    perVector.emplace_back(name, 30);
    return perVector;
}
void AutoDeduction::testTypeDeduction3()
{
    std::cout << "###### " << __FUNCTION__ << " #####\n" << std::endl;
    std::vector<Person> personVec = { {L"Jack", 29}, {L"James", 10} };
    const auto p0 = addElem(personVec, L"Jongsang"); // const std::vector<Person>
    const auto& p1 = addElem(personVec, L"Kate");    // const std::vector<Person>&
    const auto p2 = &addElem(personVec, L"cali");    // const std::vector<Person>*
    const auto& p3 = &addElem(personVec, L"max");    // const std::vector<Person>* const &

}
