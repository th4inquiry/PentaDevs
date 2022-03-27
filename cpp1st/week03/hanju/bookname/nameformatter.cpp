#include "nameformatter.h"
#include "bookname.h"
#include <algorithm>
#include <format>
#include <string>

using namespace std;

string
NameFormatter::fromBookName(const BookName& bookName)
{
    string name = format("{} ({}) by {} - {}", bookName.title(), bookName.year(), bookName.authors(), bookName.publisher());

    // ':' is not allowed for filename
    replace(name.begin(), name.end(), ':', '-');

    return name;
}
