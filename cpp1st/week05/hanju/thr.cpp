#include <cassert>
#include <iostream>
#include <thread>

class ThreadTester
{
public:
    void testAll()
    {
        std::cout << "********" << std::endl;
        testJoin();
        std::cout << "********" << std::endl;
        testPassingArgs();
    }



    class Func
    {
    public:
        Func(int i):no_(i){}
        void operator()()
        {
            std::cout << std::this_thread::get_id() << ") func" << no_ << std::endl;
        }
    private:
        int no_;
    };

    static void threadFunc(int i)
    {
        std::cout << std::this_thread::get_id() << ") threadFunc, arg=" << i << std::endl;
    }
    static void threadFuncR(int& i)
    {
        std::cout << std::this_thread::get_id() << ") threadFuncR, arg=" << i << std::endl;
        ++i;
    }
    void threadFuncM(int i)
    {
        std::cout << std::this_thread::get_id() << ") threadFuncM, arg=" << i << std::endl;
    }
    void testPassingArgs()
    {
        std::thread f(threadFunc, 200);
        f.join();
        int r = 201;
        std::thread fr(threadFuncR, std::ref(r));
        fr.join();
        std::cout << "r=" << r << std::endl;
        ThreadTester tester;
        std::thread fm(&ThreadTester::threadFuncM, &tester, r);
        fm.join();
        std::cout << "r=" << r << std::endl;
    }

    void testJoin()
    {
        auto f = [](){std::cout << std::this_thread::get_id() << ") run" << std::endl;};
        std::thread t1(f);

        Func func(1);
        std::thread t2(func);

        std::thread t3(Func(2));
        std::thread t4((Func(3)));
        std::thread t5{Func(4)};

        assert(t1.joinable());
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    }
};


int main()
{
    ThreadTester tester;
    tester.testAll();

    return 0;
}
