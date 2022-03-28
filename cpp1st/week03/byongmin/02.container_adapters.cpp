// container adapters

#include <iostream>
#include <stack>
#include <queue>
#include <queue>

using namespace std;

int main()
{
    // first priority_queue
    priority_queue<int> p1;
    p1.emplace(15);
    p1.emplace(20);
    p1.emplace(30);
    p1.emplace(10);
    p1.emplace(0);

    while(!p1.empty())
    {
        cout <<"  "<< p1.top() << " ";
        p1.pop();
    }

    cout << endl;

    // second priority_queue
    auto comp = [](int a, int b) { return a < b; };

    priority_queue <int, vector<int>, decltype(comp)> p2(comp);
    p2.emplace(15);
    p2.emplace(20);
    p2.emplace(30);
    p2.emplace(10);
    p2.emplace(0);

    while(!p2.empty())
    {
        cout <<"  "<< p2.top() << " ";
        p2.pop();
    }

    return 0;
}
