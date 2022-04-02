#include <iostream>
#include <memory>
#include <utility>

struct MyInt
{
    int i_;

    MyInt(int i ): i_(i) 
    { 
        std::cout << "Ctor MyInt(i)" << std::endl;
    }
    ~MyInt()
    {
        std::cout << "Good bye from " << i_ << std::endl;
    }

};

int main()
{
    std::cout << std::endl;

    //anti patterns
    //MyInt* myInt15 = new MyInt(15);
    //std::unique_ptr<MyInt> uniquePtr11(myInt15);
    //std::unique_ptr<MyInt> uniquePtr15(myInt15);

    //std::unique_ptr<MyInt> uniquePtr1{new MyInt(1998)};
    std::unique_ptr<MyInt> uniquePtr1 = std::make_unique<MyInt>(1998);
    std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;
    std::unique_ptr<MyInt> uniquePtr2{std::move(uniquePtr1)};
    std::cout << "uniquePtr1.get(): " << uniquePtr1.get() << std::endl;
    std::cout << "uniquePtr2.get(): " << uniquePtr2.get() << std::endl;

    std::cout << std::endl;

    {
        //std::unique_ptr<MyInt> localPtr{new MyInt(2003)};
        std::unique_ptr<MyInt> localPtr = std::make_unique<MyInt>(2003);
    }

    std::cout << std::endl;

    uniquePtr2.reset(new MyInt(2011));
    MyInt* myInt = uniquePtr2.release();
    delete myInt;

    std::cout << std::endl;

    return 0;
}