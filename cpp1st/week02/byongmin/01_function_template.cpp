// function template example

#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b)
{
    return a + b;
}

template<int N>
int incrementBy(int val)
{
    return val + N;
}

int main()
{
    cout << "++ add function" << endl;

    int numIntValue = add<int>(1, 2);
    float numFloatValue = add<float>(1.2f, 1.3f);

    cout << "add<int>(1, 2.5f) : " << numIntValue << endl;
    cout << "add<float>(1.2f, 1.3f) : " << numFloatValue << endl;

    numIntValue = add(1, 2);
    numFloatValue = add(1.2f, 1.3f);

    cout << "add(1, 2) : " << numIntValue << endl;
    cout << "add(1.2f, 1.3f) : " << numFloatValue << endl;

    cout << "++ incrementBy" << endl;

    cout << "incrementBy<5>(10) : " << incrementBy<5>(10) << endl;

    return 0;
}

