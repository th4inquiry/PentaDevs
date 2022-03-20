// class template

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
public:
    explicit Stack(int size) : mySize(size)
    {
        cout << "Stack ctor called. Type : " << typeid(T).name() << endl;
    }

    T top()
    {
        assert(myData.size() > 0);

        auto it = myData.end() - 1;
        return *it;
    }

    void push(T value)
    {
        assert(mySize > myData.size());

        myData.emplace_back(value);
    }

    void pop()
    {
        myData.pop_back();
    }

    bool empty()
    {
        return myData.empty();
    }

    int size()
    {
        return myData.size();
    }

private:
    vector<T> myData;
    int mySize;
};

int main()
{
    Stack<int> stackNum{3};
    stackNum.push(10);
    stackNum.push(20);
    stackNum.push(30);
    //stackNum.push(40); // not pushed.

    cout << "stackNum.top() : " << stackNum.top() << endl;
    stackNum.pop();
    cout << "stackNum.top() : " << stackNum.top() << endl;

    Stack<string> stackStr{3};
    stackStr.push("first");
    stackStr.push("second");
    stackStr.push("third");

    cout << "stackStr.top() : " << stackStr.top() << endl;
    stackStr.pop();
    cout << "stackStr.top() : " << stackStr.top() << endl;

    return 0;
}