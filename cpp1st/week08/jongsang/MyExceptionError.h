#pragma once

#include <stdexcept>
#include <string>

class MyFileOpenError : public std::exception
{
public:
    MyFileOpenError(std::string fileName);
    virtual const char* what() const noexcept override;

private:
    std::string myMessage;
};

