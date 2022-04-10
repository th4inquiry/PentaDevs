#include <iostream>
#include <thread>
#include <string>
#include <exception>
//#include <chrono>

using namespace std;

class Cat
{
public:
    Cat () = delete;
    explicit Cat(int age) : myAge(age) 
    { 
        cout << "Cat ctor()" << endl; 
    }

    Cat(const Cat& cat)
    {
        cout << "Cat copy ctor()" << endl; 
        myAge = cat.myAge;
    }

    int getAge() { return myAge; }
    void setAge(int age) { myAge = age; }

private:
    int myAge;
};

void valueArgThread(Cat cat, string comment)
{
    cout << "thread id : " << this_thread::get_id() 
         << ", age: " << cat.getAge() 
         << ", comment : " << comment 
         << endl;
}

void referenceArgThread(Cat& cat)
{
    this_thread::sleep_for(chrono::seconds(2));

    cout << "thread id : " << this_thread::get_id() 
         << ", age: " << cat.getAge() 
         << endl;
}

void callThreadErrorCase(thread &t)
{
    Cat cat {10};
    t = thread(referenceArgThread, ref(cat));

    cat.setAge(3);
}

void throuExceptionThread()
{
    throw runtime_error("error");
}

int main()
{
    cout << "main thread id : " << this_thread::get_id() << endl;

    Cat cat {5};

    cout << "+++ pass arguament by value]" << endl;
    thread t1 {valueArgThread, cat, "send mesasge"};
    t1.join();

    cout << "+++ [pass arguament by reference]" << endl;
    thread t2 {referenceArgThread, std::ref(cat)};
    t2.join();

    cout << "+++ [lambda]" << endl;
    thread t3 {[&cat]()
    {
        cout << "thread id : " << this_thread::get_id() 
            << ", age: " << cat.getAge() 
            << endl;
    } };
    t3.join();

    cout << "+++ [pass arguament by reference : error case]" << endl;
    thread t4;
    callThreadErrorCase(t4);
    t4.join();

    cout << "+++ [detach test]" << endl;
    thread t5 {referenceArgThread, std::ref(cat)};
    t5.detach();


    cout << "+++ [exception case]" << endl;
    try
    {
        thread t6(throuExceptionThread);
        t6.join();
    }
    catch(exception& e)
    {
        cout << "exception is catched : " << e.what() << endl;
    }

    cout << "main ended" << endl;

    return 0;
}
