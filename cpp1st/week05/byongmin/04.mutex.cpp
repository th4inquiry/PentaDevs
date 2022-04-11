#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

once_flag gOnceFlag;

void initialize()
{
    cout << ">> initialized" << endl;
}

void increment(int& counter, mutex& m)
{
    for (int i=0; i<100000; ++i)
    {
        lock_guard<mutex> lock {m};

        call_once(gOnceFlag, initialize);
        ++counter;

        this_thread::sleep_for(chrono::microseconds(1));
    }
}


int main()
{
    int counter {0};
    mutex m;
    vector<thread> threads;

    for (int i=0; i<10; ++i)
    {
        threads.emplace_back(thread {increment, ref(counter), ref(m)});
    }

    for (auto& t : threads)
    {
        t.join();
    }

    cout << "conter : " << counter << endl;

    return 0;
}