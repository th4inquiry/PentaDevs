//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Examples of Containers

#include <iomanip>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Containers {
public:
    Containers() {}

    void ContainerSelect();
private:
    void Example_array();
    void Example_vector();
    void Example_deque();
    void Example_forward_list();
    void Example_list();
    void Example_set();
    void Example_map();
    void Example_multiset();
    void Example_multimap();
    void Example_stack();
    void Example_queue();
    void Example_proirity_queue();

    bool isTestEnd;
    int select;
};

void Containers::ContainerSelect() {
    while (isTestEnd != true) {
        cout << "-- Select number from the list below:" << endl;
        cout.setf(ios::left);
        cout << setw(20) << "1. array" << setw(20) << "2. vector" << setw(20) << "3. deque" << setw(20) << "4. forward_list" << setw(20) << "5. list" << endl;
        cout << setw(20) << "6. set" << setw(20) << "7. map" << setw(20) << "8. multiset" << setw(20) << "9. multimap" << setw(20) << "10. stack" << endl;
        cout << setw(20) << "11. queue" << setw(20) << "12. priority_queue" << endl;
        cout << "0. Back to list" << endl;
        cout << "> ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 0:
                isTestEnd = true;
                break;
            case 1:
                Example_array();
                break;
            case 2:
                Example_vector();
                break;
            case 3:
                Example_deque();
                break;
            case 4:
                Example_forward_list();
                break;
            case 5:
                Example_list();
                break;
            case 6:
                Example_set();
                break;
            case 7:
                Example_map();
                break;
            case 8:
                Example_multiset();
                break;
            case 9:
                Example_multimap();
                break;
            case 10:
                Example_stack();
                break;
            case 11:
                Example_queue();
                break;
            case 12:
                Example_proirity_queue();
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
        cout << endl << endl;
    }

    return;
}

void Containers::Example_array() {
    array<int, 3> a1 { {1, 2, 3} };    /// double-braces required in C++11 and prior
    array<int, 3> a2 = {1, 2, 3};    /// double braces never required in C++14 and beyond
    array<string, 2> a3 = {string("a"), "b"};
    array a4 {3.0, 1.0, 4.0};    /// -> std::array<double, 3> (since C++17)

    sort(a1.begin(), a1.end());
    reverse_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));

    std::cout << '\n';

    for(const auto& s: a3) {
        std::cout << s << ' ';
    }

    return;
}

void Containers::Example_vector() {
    vector<int> v = {7, 5, 16, 8};

    v.push_back(25);
    v.push_back(13);
    cout << "v = { ";
    for (int n : v) {
        cout << n << ", ";
    }
    cout << "};" << endl;
    cout << v.size() << endl;

    v.pop_back();
    cout << "v = { ";
    for (int n : v) {
        cout << n << ", ";
    }
    cout << "};" << endl;
    cout << v.size() << endl;

    v.clear();
    cout << "v = { ";
    for (int n : v) {
        cout << n << ", ";
    }
    cout << "};" << endl;
    cout << v.size() << endl;

    return;
}

void Containers::Example_deque() {
    deque<int> d = {7, 5, 16, 8};

    d.push_front(13);
    d.push_back(25);

    for (int n : d) {
        cout << n << ' ';
    }
    cout << endl;

    deque<int>::iterator iter;
    for (iter = d.begin(); iter != d.end(); iter++) {
        if(*iter == 8) {
            d.erase(iter);
        }
        cout << *iter << ' ';
    }
    cout << endl;

    d.resize(8);

    deque<int>::reverse_iterator riter;
    for (riter = d.rbegin(); riter != d.rend(); riter++) {
        cout << *riter << ' ';
    }
    cout << endl;


    return;
}

void Containers::Example_forward_list() {
    forward_list<int> flist1;
    forward_list<int> flist2;

    flist1.assign({4, 5, 6});
    flist2.assign(5, 10);

    cout << "The elements of first forward list are : ";
    for (int &a: flist1) {
        cout << a << " ";
    }
    cout << endl;

    cout << "The elements of second forward list are : ";
    for (int &b: flist2) {
        cout << b << " ";
    }
    cout << endl;

    flist1.push_front(3);
    flist1.emplace_front(2);
    cout << "The elements of changed first forward list are : ";
    for (int &a: flist1) {
        cout << a << " ";
    }
    cout << endl;

    flist1.pop_front();
    cout << "The elements of changed first forward list are : ";
    for (int &a: flist1) {
        cout << a << " ";
    }
    cout << endl;

    forward_list<int>::iterator iter;
    iter = flist1.insert_after(flist1.begin(), {6, 5, 4});
    cout << "The elements of changed first forward list are : ";
    for (int &a: flist1) {
        cout << a << " ";
    }
    cout << endl;

    flist1.remove(6);
    cout << "The elements of changed first forward list are : ";
    for (int &a: flist1) {
        cout << a << " ";
    }
    cout << endl;

    return;
}

void Containers::Example_list() {
    list<int> l = { 7, 5, 16, 8 };

    l.push_front(25);
    l.push_back(13);

    auto iter = find(l.begin(), l.end(), 16);
    if (iter != l.end()) {
        l.insert(iter, 42);
    }

    std::cout << "l = { ";
    for (int &n : l) {
        std::cout << n << ", ";
    }
    cout << "};" << endl;

    return;
}

void Containers::Example_set() {
    set<int, greater<int>> s1;
    //set<int, less<int>>s1;

    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    s1.insert(50);    /// only one 50 will be added to the set
    s1.insert(10);

    cout << "The set s1 is : ";
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    set<int> s2(s1.begin(), s1.end());  /// assigning the elements from s1 to s2
    s2.erase(s2.begin(), s2.find(30));  /// remove all elements up to 30 in s2

    cout << "The set s2 is : ";
    for (auto iter = s2.begin(); iter != s2.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    int num = s2.erase(50);
    cout << "Removed " << num << " element in s2 by running erase(50);" << endl;
    cout << "The changed set s2 is : ";
    for (auto iter = s2.begin(); iter != s2.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    cout << *s1.lower_bound(40) << "\t" << *s1.upper_bound(40) << endl;
    cout << *s2.lower_bound(40) << "\t" << *s2.upper_bound(40) << endl;

    return;
}

void Containers::Example_map() {
    map<int, int> map1;

    map1.insert(pair<int, int>(1, 40));
    map1.insert(pair<int, int>(2, 30));
    map1.insert(pair<int, int>(3, 60));
    map1.insert(pair<int, int>(4, 20));
    map1.insert(pair<int, int>(5, 50));
    map1.insert(pair<int, int>(6, 50));
    map1.insert(pair<int, int>(7, 10));

    cout << "The map1 is : " << endl;
    cout << "\tKey\tElement" << endl;
    for(auto iter = map1.begin(); iter != map1.end(); ++iter) {
        cout << "\t" << iter->first << "\t" << iter->second << endl;
    }
    cout << endl;

    map<int, int> map2(map1.begin(), map1.end());
    map2.erase(map2.begin(), map2.find(3));     /// remove all elements up to element with key=3 in map2
    map2.erase(4);      /// remove element with key=4 in map2

    cout << "The map2 is : " << endl;
    cout << "\tKey\tElement" << endl;
    for(auto iter = map2.begin(); iter != map2.end(); ++iter) {
        cout << "\t" << iter->first << "\t" << iter->second << endl;
    }
    cout << endl;

    return;
}

void Containers::Example_multiset() {
    multiset<int, greater<int>> ms1;

    ms1.insert(40);
    ms1.insert(30);
    ms1.insert(60);
    ms1.insert(20);
    ms1.insert(50);

    ms1.insert(50);     /// 50 will be added again to the multiset unlike set
    ms1.insert(10);

    cout << "The multiset ms1 is: ";
    for (auto iter = ms1.begin(); iter != ms1.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    multiset<int> ms2(ms1.begin(), ms1.end());
    ms2.erase(ms2.begin(), ms2.find(30));   /// remove all elements up to element with value 30 in ms2
    auto num = ms2.erase(50);
    cout << "ms2.erase(50) : " << num << " element(s) removed" << endl;
    cout << "The multiset ms2 is: ";
    for (auto iter = ms2.begin(); iter != ms2.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return;
}

void Containers::Example_multimap() {
    multimap<int, int> mm1;

    mm1.insert(pair<int, int>(1, 40));
    mm1.insert(pair<int, int>(2, 30));
    mm1.insert(pair<int, int>(3, 60));
    mm1.insert(pair<int, int>(4, 50));
    mm1.insert(pair<int, int>(5, 10));
    mm1.insert(pair<int, int>(5, 30));

    cout << "The multimap mm1 is : " << endl;
    cout << "\tKey\tElement" << endl;
    for (auto iter = mm1.begin(); iter != mm1.end(); ++iter) {
        cout << "\t" << iter->first << "\t" << iter->second << endl;
    }
    cout << endl;

    mm1.insert(pair<int, int>(4, 50));
    mm1.insert(pair<int, int>(6,10));

    multimap<int, int> mm2(mm1.begin(), mm1.end());
    mm2.erase(mm2.begin(), mm2.find(3));
    mm2.erase(4);
    cout << "The multimap mm2 is : " << endl;
    cout << "\tKey\tElement" << endl;
    for (auto iter = mm2.begin(); iter != mm2.end(); ++iter) {
        cout << "\t" << iter->first << "\t" << iter->second << endl;
    }
    cout << endl;


    return;
}

void Containers::Example_stack() {
    stack<int> stack1;
    stack1.push(21);
    stack1.push(22);
    stack1.push(24);
    stack1.push(25);

    while (!stack1.empty()) {
        cout << " " << stack1.top();
        stack1.pop();
    }

    return;
}

void Containers::Example_queue() {
    queue<int> queue1;
    queue1.push(0);
    queue1.push(1);
    queue1.push(2);

    while(!queue1.empty()) {
        cout << " " << queue1.front();
        queue1.pop();
    }

    return;
}

void Containers::Example_proirity_queue() {
    priority_queue<int> pq1;
    pq1.push(10);
    pq1.push(30);
    pq1.push(20);
    pq1.push(1);
    pq1.push(5);

    priority_queue<int> pq2 = pq1;

    cout << "The priority queue pq1 is : ";
    while(!pq1.empty()) {
        cout << "\t" << pq1.top();
        pq1.pop();
    }
    cout << endl;

    cout << "size of pq2 : " << pq2.size() << endl;
    cout << "top of pq2 : " << pq2.top() << endl;
    pq2.pop();

    cout << "The priority queue pq2 is : ";
    while(!pq2.empty()) {
        cout << "\t" << pq2.top();
        pq2.pop();
    }
    cout << endl;

    return;
}