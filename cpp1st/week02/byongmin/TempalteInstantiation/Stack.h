
#include <vector>

template <typename T, int N>
class Stack
{
public:
    explicit Stack();

    T top();
    void push(T value);
    void pop();
    bool empty();
    int size();

private:
    std::vector<T> myData;
    int mySize;
};
