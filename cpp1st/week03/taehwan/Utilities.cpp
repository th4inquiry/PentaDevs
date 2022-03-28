//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Examples of Utilities

#include <tuple>

using namespace std;

class Utilities {
public:
    Utilities() {}

    void UtilitySelect();
private:
    void ExampleTuple();

    bool isTestEnd;
    int select;
};

void Utilities::UtilitySelect() {
    isTestEnd = false;

    while (isTestEnd != true) {
        cout << "-- Select number from the list below:" << endl;
        cout.setf(ios::left);
        cout << setw(20) << "1. tuple / tuple_element / tuple_size" << endl;
        cout << "0. Back to list" << endl;
        cout << "> ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 0:
                isTestEnd = true;
                break;
            case 1:
                ExampleTuple();
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
        cout << endl << endl;
    }

    return;
}

void Utilities::ExampleTuple() {
    auto get_student = [](int id) {
        if (id == 0) { return make_tuple(0, 3.8, 'A', "Hanju"); }
        if (id == 1) { return make_tuple(1, 2.9, 'C', "Byongmin"); }
        if (id == 2) { return make_tuple(2, 1.7, 'D', "Yongho"); }
        if (id == 3) { return make_tuple(3, 3.1, 'B', "Jongsang"); }
        if (id == 4) { return make_tuple(4, 0.0, 'F', "Taehwan"); }
    };

    auto student = get_student(0);
    cout << "ID: " << get<0>(student) << ", "
         << "GPA: " << get<1>(student) << ", "
         << "grade: " << get<2>(student) << ", "
         << "name: " << get<3>(student) << endl;

    typedef struct studentInformation {
        int id;
        double gpa;
        char grade;
        string name;
    } Info;

    array<Info, 5> info;

    tie(info.begin()->id, info.begin()->gpa, info.begin()->grade, info.begin()->name) = get_student(1);
    cout << "ID: " << info.begin()->id << ", "
         << "GPA: " << info.begin()->gpa << ", "
         << "grade: " << info.begin()->grade << ", "
         << "name: " << info.begin()->name << endl;

    tie((info.begin() + 1)->id, (info.begin() + 1)->gpa, (info.begin() + 1)->grade, (info.begin() + 1)->name) = get_student(2);
    cout << "ID: " << (info.begin() + 1)->id << ", "
         << "GPA: " << (info.begin() + 1)->gpa << ", "
         << "grade: " << (info.begin() + 1)->grade << ", "
         << "name: " << (info.begin() + 1)->name << endl;

    auto [ id, gpa, grade, name ] = get_student(3);
    cout << "ID: " << id << ", "
         << "GPA: " << gpa << ", "
         << "grade: " << grade << ", "
         << "name: " << name << endl;

    auto [ id2, gpa2, grade2, name2 ] = get_student(4);
    cout << "ID: " << id2 << ", "
         << "GPA: " << gpa2 << ", "
         << "grade: " << grade2 << ", "
         << "name: " << name2 << endl;

    cout << endl;

    cout << "tuple size: " << tuple_size<decltype(info)>::value << endl;

    using type = tuple_element<0, decltype(info)>::type;
    cout << is_same<type, Info>::value << endl;

    return;
}