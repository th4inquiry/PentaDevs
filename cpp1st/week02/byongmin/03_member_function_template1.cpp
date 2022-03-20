// member funtion template (1)

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
public:
    Stack(int size) : mySize(size)
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

    template <typename U>
    void print(U title)
    {
        cout << endl;
        cout << "++ Stack Print [" << title << "] contents" << endl;
        cout << "---------------------------" << endl;

        for(T item : myData)
        {
            cout << item << endl;
        }
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

    cout << "stackNum.top() : " << stackNum.top() << endl;

    stackNum.print<int>(stackNum.size());
    stackNum.print<string>("myData");

    return 0;
}