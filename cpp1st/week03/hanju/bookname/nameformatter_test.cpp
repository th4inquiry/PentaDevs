#include "nameformatter.h"
#include "bookname.h"
#include <iostream>

bool test_NameFormatter()
{
    BookName bn("Title is title", "John Doe, Jane Doe, Phd. Violet Evergarden", 2022, "New publisher");
    auto name = NameFormatter::fromBookName(bn);
    auto expected = "Title is title (2022) by John Doe, Jane Doe, Phd. Violet Evergarden - New publisher";
    return name == expected;
}


int main()
{
    std::cout << "run test_NameFormatter" << std::endl;
    std::cout << (test_NameFormatter() ? "PASS" : "FAIL") << std::endl;
    return 0;
}
