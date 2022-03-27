#include "bookname.h"
#include "nameformatter.h"
#include <iostream>

int main()
{
    std::string title;
    std::string authors;
    std::string year;
    std::string publisher;

    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Authors (ex. A, B, C): ";
    std::getline(std::cin, authors);
    std::cout << "Year: ";
    std::getline(std::cin, year);
    std::cout << "Publisher: ";
    std::getline(std::cin, publisher);

    std::cout << NameFormatter::fromBookName(BookName(title, authors, std::stoi(year), publisher)) << std::endl;

    return 0;
}