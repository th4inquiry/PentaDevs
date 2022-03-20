// alias template

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T>
class Stack
{
public:
    void push(T value)
    {
        cout << "Stack::push : " << value << endl;
    }
};

template<typename T>
using aliasStack = Stack<T>;

template<typename T>
struct typeDefStack
{
    typedef Stack<T> typeStack;
};

template<typename T>
using aliasVector = vector<T>;

int main()
{
    // 1) using 
    aliasStack<int> stack1;
    stack1.push(1);

    // 2) typedef
    typeDefStack<int>::typeStack stack2;
    stack2.push(2);

    // 3) std::vector
    aliasVector<int> vec;
    vec.emplace_back(10);
    cout << "std::vector::push : " << vec.at(0) << endl;

    return 0;
}