#include "bookname.h"
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;
using namespace std::string_literals;

BookName::BookName(string title, string authors, int year, string publisher)
{
    title_ = getTitle(title);
    authors_ = getAuthorList(authors);
    year_ = year;
    publisher_ = publisher;
}


string
BookName::title() const
{
    return title_;
}

string
BookName::authors() const
{
    stringstream ss;
    bool hasComma = false;
    for_each(authors_.begin(), authors_.end(), [&ss, &hasComma](auto s){ if (hasComma) ss << ", "; ss << s; hasComma = true; });
    return ss.str();
}

vector<string>
BookName::authorList() const
{
    return authors_;
}

int
BookName::year() const
{
    return year_;
}

string
BookName::publisher() const
{
    return publisher_;
}

const string
BookName::getTitle(string title)
{
    vector<string> tokens;
    stringstream s(title);
    string t;
    while (getline(s, t, ' '))
    {
        tokens.push_back(t);
    }

    stringstream ss;
    bool hasSpace = false;
    for_each(tokens.begin(), tokens.end(), [&ss, &hasSpace](auto s){ if (hasSpace) ss << " "; ss << s; hasSpace = true;});
    return ss.str();
}

const vector<string>
BookName::getAuthorList(string authors)
{
    vector<string> authorList;
    stringstream s(authors);
    string t;
    while (getline(s, t, ','))
    {
        while (!t.empty() && *(t.begin())==' ')
            t.erase(t.begin());
        while (!t.empty() && *(t.end()-1)==' ')
            t.erase(t.end()-1);
        authorList.push_back(t);
    }

    return authorList;
}
