// template-test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
T getMin(T a, T b)
{
    return a < b ? a : b;
}

template<>
const char* getMin<const char*>(const char *a, const char *b)
{
    return strcmp(a, b) < 0 ? a : b;
}

int main()
{
    int value = getMin<int>(5, 6);

    char p1[] = { "kitty" };
    char p2[] = { "puppy" };
    const char* str = getMin<const char*>(p1, p2);

    cout << "getMin<int>(5, 6) : " << value << endl;
    cout << "getMin<char*> : " << str << endl;

    return 0;
}


