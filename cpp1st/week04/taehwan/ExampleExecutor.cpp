///
/// Copyright 2022 PentaDevs
/// Author: Taehwan Kim
/// Contents: Class ExampleExecutor

#include <iostream>
#include <iomanip>

#include "SmartPointer.cpp"

using namespace std;

class ExampleExecutor {
public:
    ExampleExecutor();

private:
    void selectComponent();

    SmartPointers smartPointers;

    int select;
    bool isTestEnd;
};

ExampleExecutor::ExampleExecutor() : isTestEnd(false) {
    selectComponent();
}

void ExampleExecutor::selectComponent() {
    while (isTestEnd != true) {
        cout.setf(ios::left);
        cout << setw(20) << "1. Smart Pointer";
        cout << setw(20) << "2. Helper class";
        cout << endl << "0. Test end" << endl;
        cout << "Select number: ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 1:
                smartPointers.selectSmartPointer();
                break;
            case 2:
                cout << "TBU" << endl;
                break;
            case 0:
                isTestEnd = true;
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
    }
}