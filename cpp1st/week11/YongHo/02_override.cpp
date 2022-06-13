// A CPP program without override keyword, here
// programmer makes a mistake and it is not caught
#include <iostream>

class BaseClass
{
    public:
        //user wants to override this in the derived class
        virtual void func() 
        {
            std::cout << "BaseClass::func()" << std::endl;
        }
};

class DerivedClass : public BaseClass
{
    public:
        //did a silly mistake by putting an argument "int a"
        void func(int a) //override
        {
            std::cout << "DerivedClass::func(" << a << ")" << std::endl;
        }
};

int main()
{
    BaseClass b;
    b.func();
    DerivedClass d;
    d.func(5);
    std::cout << "Compiled successfully" << std::endl;
    return 0;
}