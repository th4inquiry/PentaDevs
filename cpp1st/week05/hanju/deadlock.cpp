#include <exception>
#include <iostream>
#include <mutex>
#include <thread>

class DeadlockTester
{
public:
    void testAll()
    {
        testDeadlock();
    }

    struct Object
    {
        std::mutex m;
    };

    Object data[2];
    void lockFunc(int i)
    {
        std::lock_guard lock(data[i].m);
        std::cout << "lockFunc" << i << std::endl;
        std::lock_guard<std::mutex> lock2(data[!i].m);
        std::cout << "lockFunc" << i << std::endl;
    }
    void testDeadlock()
    {
        std::thread t1(&DeadlockTester::lockFunc, this, 0);
        std::thread t2(&DeadlockTester::lockFunc, this, 1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        // not detached
        if (t1.joinable() && t2.joinable())
        {
            std::cout << "deadlock" << std::endl;
            t1.detach();
            t2.detach();
        }
        else
            std::cout << "not deadlock" << std::endl;
    }
};

class NotDeadlockTester
{
public:
    void testAll()
    {
        testNotDeadlock();
    }

    struct Object
    {
        std::mutex m;
    };

    Object data[2];
    void lockFunc(int i)
    {
        std::lock(data[i].m, data[!i].m);
        std::lock_guard<std::mutex> lock(data[i].m, std::adopt_lock);
        std::cout << "lockFunc" << i << std::endl;
        std::lock_guard<std::mutex> lock2(data[!i].m, std::adopt_lock);
        std::cout << "lockFunc" << i << std::endl;
    }
    void testNotDeadlock()
    {
        std::thread t1(&NotDeadlockTester::lockFunc, this, 0);
        std::thread t2(&NotDeadlockTester::lockFunc, this, 1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        t1.join();
        t2.join();
        if (t1.joinable() && t2.joinable())
            std::cout << "deadlock" << std::endl;
        else
            std::cout << "not deadlock" << std::endl;
    }
};

class NotDeadlockTester2
{
public:
    void testAll()
    {
        testNotDeadlock();
    }

    struct Object
    {
        std::mutex m;
    };

    Object data[2];
    void lockFunc(int i)
    {
        std::scoped_lock lock(data[i].m, data[!i].m);
        std::cout << "lockFunc" << i << std::endl;
        std::cout << "lockFunc" << i << std::endl;
    }
    void testNotDeadlock()
    {
        std::thread t1(&NotDeadlockTester2::lockFunc, this, 0);
        std::thread t2(&NotDeadlockTester2::lockFunc, this, 1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        t1.join();
        t2.join();
        if (t1.joinable() && t2.joinable())
            std::cout << "deadlock" << std::endl;
        else
            std::cout << "not deadlock" << std::endl;
    }
};

int main()
{
    DeadlockTester tester;
    NotDeadlockTester tester2;
    NotDeadlockTester2 tester3;
    tester.testAll();
    tester2.testAll();
    tester3.testAll();
    return 0;
}
