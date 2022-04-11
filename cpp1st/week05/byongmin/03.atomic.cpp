#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

void increment(int& counter)
{
    for (int i=0; i<10000; ++i)
    {
        ++counter;
        this_thread::sleep_for(chrono::microseconds(1));
    }
}

void incrementAtomic(atomic<int>& counter)
{
    for (int i=0; i<10000; ++i)
    {
        ++counter;
        this_thread::sleep_for(chrono::microseconds(1));
    }
}

int main()
{
    int counter{0};
    atomic<int> counterAtomic{0};
    vector<thread> threads;
    vector<thread> threadsAtomic;

    for (int i=0; i<10; ++i)
    {
        threads.emplace_back(thread{increment, ref(counter)});
        threadsAtomic.emplace_back(thread{incrementAtomic, ref(counterAtomic)});
    }

    for (auto& t : threads)
    {
        t.join();
    }

    for (auto& t : threadsAtomic)
    {
        t.join();
    }

    cout << "conter : " << counter << endl;
    cout << "conterAtomic : " << counterAtomic << endl;

    return 0;
}