//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Class ExampleExecutor

#include <iostream>
#include <iomanip>

#include "Containers.cpp"
#include "Algorithms.cpp"
#include "Utilities.cpp"

using namespace std;

class ExampleExecutor {
public:
    ExampleExecutor();

private:
    void ComponentSelect();

    Containers containers;
    Algorithms algorithms;
    Utilities utilities;
    int select;
    bool isTestEnd;
};

ExampleExecutor::ExampleExecutor() {
    isTestEnd = false;
    ComponentSelect();
}

void ExampleExecutor::ComponentSelect() {
    while (isTestEnd != true) {
        cout << "-- Select number from the list below:" << endl;
        cout.setf(ios::left);
        cout << setw(20) << "1. Containers";
        cout << setw(20) << "2. Iterators";
        cout << setw(20) << "3. Functions";
        cout << setw(20) << "4. Algorithms";
        cout << setw(20) << "5. Utilities" << endl;
        cout << "0. Test end" << endl;
        cout << "> ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 1:
                containers.ContainerSelect();
                break;
            case 2:
                cout << "TBU" << endl;
                break;
            case 3:
                cout << "TBU" << endl;
                break;
            case 4:
                algorithms.AlgorithmSelect();
                break;
            case 5:
                utilities.UtilitySelect();
                break;
            case 0:
                isTestEnd = true;
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
    }

    return;
}