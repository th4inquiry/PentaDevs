// tempalte instantiation

#include "Stack.h"
#include <cassert>
#include <string>

template <typename T, int N>
Stack<T, N>::Stack()
{
}

template <typename T, int N>
T Stack<T, N>::top()
{
    assert(myData.size() > 0);

    auto it = myData.end() - 1;
    return *it;
}

template <typename T, int N>
void Stack<T, N>::push(T value)
{
    assert(mySize > myData.size());

    myData.emplace_back(value);
}

template <typename T, int N>
void Stack<T, N>::pop()
{
    myData.pop_back();
}

template <typename T, int N>
bool Stack<T, N>::empty()
{
    return myData.empty();
}

template <typename T, int N>
int Stack<T, N>::size()
{
    return myData.size();
}

template class Stack<int, 3>; 
template class Stack<std::string, 3>; 