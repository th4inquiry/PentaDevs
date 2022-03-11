// C++ lambda expression test

#include <iostream>
#include <string>
#include <vector>

// several tests
class LambdaTest
{
public:
    void testCall();
    void testCapture();
    template <class ...T>
    void testCapturePack(T... args);
    void testAll();

private:
    void printName()
    {
        std::cout << "LambdaTest" << std::endl;
    }
};

void LambdaTest::testCall()
{
    std::cout << __FUNCTION__ "begins" << std::endl;

    auto f = [this](){
        this->printName();
    }; // doesn't print anything

    f(); // call printName()

    std::cout << __FUNCTION__ "ends" << std::endl;
}

void LambdaTest::testCapture()
{
    std::cout << __FUNCTION__ "begins" << std::endl;

    std::string name = "not updated";
    [&](){
        name = "captured everything by reference";
    }();
    std::cout << name << std::endl;

    name = "not updated";
    [=](){
        //compile error
        //name = "captured everything by copy";
    }();
    std::cout << name << std::endl;

    name = "not updated";
    [&name](){
        name = "captured name by reference";
    }();
    std::cout << name << std::endl;

    [](){
        //compile error
        //std::cout << name << std::endl;
    }();

    std::cout << __FUNCTION__ "ends" << std::endl;
}

template <class ...T>
void LambdaTest::testCapturePack(T... args)
{
    std::cout << __FUNCTION__ "begins" << std::endl;

    [args...](){
        int ar[] = {args...};
        for (auto a:ar)
        {
            std::cout << a << std::endl;
        }
    }();

    std::cout << __FUNCTION__ "ends" << std::endl;
}

void LambdaTest::testAll()
{
    testCall();
    testCapture();
    testCapturePack(1024, 2048, 3072);
}

int main()
{
    LambdaTest tester;
    tester.testAll();
    return 0;
}
