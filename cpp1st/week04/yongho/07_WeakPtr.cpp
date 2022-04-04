#include <iostream>
#include <memory>

int main()
{
    std::cout << std::boolalpha << std::endl;

    auto sharedPtr = std::make_shared<int>(2011);
    std::weak_ptr<int> weakPtr(sharedPtr);

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;   //1
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl; //1
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl; //false
    std::cout << std::endl;

    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock())
    {
        std::cout << "*sharedPtr= " << * sharedPtr << std::endl;
        std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;   //2
        std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl; //2
        std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl; //false
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Don't get the resource!" << std::endl;
    }

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl; //1
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl; //1
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl; //false
    std::cout << std::endl;

    weakPtr.reset();
    
    if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock())
    {
        std::cout << "*sharedPtr= " << * sharedPtr << std::endl;
        std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
        std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
        std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;
    }
    else
    {
        std::cout << "Don't get the resource!" << std::endl;
    }
}