#include <iostream>

using namespace std;

class UserDefinedException
{
public:
    const char* what() const
    {
        return "UserDefinedException exception error";
    }
};

class custom_exception_error : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "custom exception exception error";
    }
};

int main()
{
    try
    {
        //throw 1;
        //throw "Unexcepted error";
        //throw UserDefinedException();
        //throw custom_exception_error();
        //throw runtime_error("runtime exception error");
        throw 1.5;
    }
    catch(int e)
    {
        std::cerr << "error code : " << e << '\n';
    }
    catch(const char* e)
    {
        std::cerr << "error message : " << e << '\n';
    }
    catch(UserDefinedException& e)
    {
        std::cerr << e.what() << '\n';
    } 
    catch(const custom_exception_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "unknown error." << '\n';
    }

    return 0;
}