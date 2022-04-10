#include <iostream>
#include <thread>

using namespace std;

void doThreadWork()
{
    throw runtime_error("exception from thread");
}

void workThread(exception_ptr &ex)
{
    try
    {
        doThreadWork();
    }
    catch(const std::exception& e)
    {
        cout << "thread. check exception : " << e.what() << endl;
        ex = current_exception();
    }
}

void runThread()
{
    exception_ptr ex = nullptr;

    thread t1 {workThread, ref(ex)};
    t1.join();

    if(ex)
    {
        cout << "main. rethrow exception." << endl;
        rethrow_exception(ex);
    }
}

int main()
{
    try
    {
        runThread();
    }
    catch(const std::exception& e)
    {
        cout << "main. check exception : " << e.what() << endl;
    }

    return 0;
}