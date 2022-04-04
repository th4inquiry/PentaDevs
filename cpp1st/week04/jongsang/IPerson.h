#pragma once

#include <string>

class IPerson
{
public:
    virtual ~IPerson() = default;

    virtual std::wstring getName() const = 0;
    virtual int getAge() const = 0;

    virtual void printInfo() const = 0;
};

