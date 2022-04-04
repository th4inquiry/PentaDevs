#include <iostream>
#include <memory>
#include <thread>

using namespace std::literals::chrono_literals;

struct MyInt
{
    int val{2017};
    ~MyInt()
    {
        std::cout << "Good Bye" << std::endl;
    }
};

void showNumber(std::shared_ptr<MyInt> myInt)
{
    std::cout << myInt->val << std::endl;
}

void threadCreator()
{
    auto sharedPtr = std::make_shared<MyInt>();
    std::cout << sharedPtr.use_count() << std::endl; //1

    std::thread t1(showNumber, sharedPtr);
    std::cout << sharedPtr.use_count() << std::endl; //2
    std::thread t2(showNumber, sharedPtr);
    std::cout << sharedPtr.use_count() << std::endl; //3

    t1.detach();
    std::cout << sharedPtr.use_count() << std::endl; //2
    t2.detach();
    std::cout << sharedPtr.use_count() << std::endl; //1

}

int main()
{
    std::cout << std::endl;
    threadCreator();
    std::this_thread::sleep_for(1s);
    std::cout << std::endl;
}