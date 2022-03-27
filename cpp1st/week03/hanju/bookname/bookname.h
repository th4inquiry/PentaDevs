#include <string>
#include <vector>

class BookName
{
public:
    BookName(std::string title, std::string authors, int year, std::string publisher);

    std::string title() const;
    std::string authors() const;
    std::vector<std::string> authorList() const;
    int year() const;
    std::string publisher() const;

private:
    const std::string getTitle(std::string title);
    const std::vector<std::string> getAuthorList(std::string authors);

private:
    std::string title_;
    std::vector<std::string> authors_;
    int year_ { 1900 };
    std::string publisher_;
};
