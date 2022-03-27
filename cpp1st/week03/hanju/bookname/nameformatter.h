#include <string>

class BookName;
class NameFormatter
{
public:
    static std::string fromBookName(const BookName& bookName);
};
