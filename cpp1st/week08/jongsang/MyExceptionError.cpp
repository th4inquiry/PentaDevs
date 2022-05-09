#include "MyExceptionError.h"

MyFileOpenError::MyFileOpenError(std::string fileName)
{
    myMessage = "Unable to open " + fileName;
}

const char* MyFileOpenError::what() const noexcept
{
    return myMessage.c_str();
}

