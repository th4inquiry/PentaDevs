#include <iostream>
#include <memory>
#include <utility>

struct MyInt
{
    int i_;
    MyInt(int i ): i_(i) 
    { 
        std::cout << "[Ctor] Hello " << i_ << std::endl;
    }
    ~MyInt()
    {
        std::cout << "[Dtor] Good bye from " << i_ << std::endl;
    }
};


int main()
{
    std::cout << std::endl;

    //std::shared_ptr<MyInt> sharPtr(new MyInt(1998));
    std::shared_ptr<MyInt> sharPtr = std::make_shared<MyInt>(1998);

    std::cout << "sharePtr.use_count()= " << sharPtr.use_count() << std::endl; //1
    {
        std::shared_ptr<MyInt> locSharPtr(sharPtr);
        std::cout << "locSharPtr.use_count()= " << locSharPtr.use_count() << std::endl; //2
    }
    std::cout << "sharePtr.use_count()= " << sharPtr.use_count() << std::endl; //1

    std::shared_ptr<MyInt> globSharPtr = sharPtr;
    std::cout << "sharePtr.use_count()= " << sharPtr.use_count() << std::endl; //2

    globSharPtr.reset();
    std::cout << "sharePtr.use_count()= " << sharPtr.use_count() << std::endl; //1

    sharPtr = std::shared_ptr<MyInt>(new MyInt(2011));
    //sharPtr = std::make_shared<MyInt>(2011);
    std::cout << "sharePtr.use_count()= " << sharPtr.use_count() << std::endl; //1

    std::cout << std::endl;

    return 0;
}