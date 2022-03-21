
#include "Stack.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Stack<int, 3> stackNum;
    stackNum.push(10);
    stackNum.push(20);
    stackNum.push(30);
    // // stackNum.push(40); // not pushed.

    cout << "stackNum.top() : " << stackNum.top() << endl;
    stackNum.pop();
    cout << "stackNum.top() : " << stackNum.top() << endl;

    Stack<string, 3> stackStr;
    stackStr.push("first");
    stackStr.push("second");
    stackStr.push("third");

    cout << "stackStr.top() : " << stackStr.top() << endl;
    stackStr.pop();
    cout << "stackStr.top() : " << stackStr.top() << endl;

    return 0;
}

// g++ .\main.cpp .\Stack.cpp