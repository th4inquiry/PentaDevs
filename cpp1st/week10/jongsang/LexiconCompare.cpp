#include "LexiconCompare.h"
#include <iostream>
#include <algorithm>

bool LexiconCompare::myComp(char c1, char c2)
{
    // a case-insensitive comparison function:
    auto ret = std::tolower(c1) < std::tolower(c2);
    std::cout << "c1 : " << c1 << " c2 : " << c2 << " => " << ret << std::endl;
    return ret;
}

void LexiconCompare::testLexiconCompare()
{
    std::cout << "\n\n###### " << __FUNCTION__ << " #####\n" << std::endl;
    char foo[] = "Apple";
    char bar[] = "apartment";

    std::string fooStr = "Apple";
    std::string barStr = "apratment";

    std::cout << std::boolalpha;

    std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    std::cout << "Using default comparison (operator<) char type: ";
    std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9);
    std::cout << '\n';

    std::cout << "Using default comparison (operator<) string type: ";
    std::cout << std::lexicographical_compare(fooStr.begin(), fooStr.end(), barStr.begin(), barStr.end());
    std::cout << '\n';

    std::cout << "Using mycomp as comparison object: ";
    std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9, myComp);
    std::cout << '\n';

    auto lambdaComp = [](char c1, char c2) {
        return std::tolower(c1) < std::tolower(c2);
    };

    std::cout << "Using lambda expression as comparison object: ";
    std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9, lambdaComp);
    std::cout << '\n';
}
