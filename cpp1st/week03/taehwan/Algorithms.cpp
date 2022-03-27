//
// Copyright 2022 PentaDevs
// Author: Taehwan Kim
// Contents: Examples of Algorithms

#include <algorithm>
#include <numeric>

using namespace std;

class Algorithms {
public:
    Algorithms() {}

    void AlgorithmSelect();
private:
    void ExampleAllofAnyofNoneof();
    void ExampleForEach();
    void ExampleCount();
    void ExampleMismatch();
    void ExampleFind();
    void ExampleFindEnd();
    void ExampleSearch();
    void ExampleCopy();
    void ExampleMove();
    void ExamplePartition();
    void ExampleSort();

    bool isTestEnd;
    int select;
};

void Algorithms::AlgorithmSelect() {
    isTestEnd = false;

    while (isTestEnd != true) {
        cout << "-- Select number from the list below:" << endl;
        cout.setf(ios::left);
        cout << setw(35) << "1. all_of / any_of / none_of" << setw(35) << "2. for_each" << setw(35) << "3. count / count_if" << endl;
        cout << setw(35) << "4. mismatch" << setw(35) << "5. find / find_if / find_if_not" << setw(35) << "6. find_end" << endl;
        cout << setw(35) << "7. search" << setw(35) << "8. copy / copy_if / copy_n / copy_backward" << endl;
        cout << setw(35) << "9. move / move_backward" << setw(35) << "10. partition / partition_copy / partition_point" << endl;
        cout << setw(35) << "11. sort / is_sorted / is_sorted_until / partial_sort_copy" << endl;
        cout << "0. Back to list" << endl;
        cout << "> ";
        cin >> select;
        cout << endl;

        switch (select) {
            case 0:
                isTestEnd = true;
                break;
            case 1:
                ExampleAllofAnyofNoneof();
                break;
            case 2:
                ExampleForEach();
                break;
            case 3:
                ExampleCount();
                break;
            case 4:
                ExampleMismatch();
                break;
            case 5:
                ExampleFind();
                break;
            case 6:
                ExampleFindEnd();
                break;
            case 7:
                ExampleSearch();
                break;
            case 8:
                ExampleCopy();
                break;
            case 9:
                ExampleMove();
                break;
            case 10:
                ExamplePartition();
                break;
            case 11:
                ExampleSort();
                break;
            default:
                cout << "Error: Choose a correct number!" << endl;
                break;
        }
        cout << endl << endl;
    }

    return;
}

void Algorithms::ExampleAllofAnyofNoneof() {
    vector<int> v(10, 2);
    partial_sum(v.cbegin(), v.cend(), v.begin());
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    if(all_of(v.cbegin(), v.cend(), [](int i){ return i % 2 == 0; })) {
        cout << "All numbers are even." << endl;
    }

    if(none_of(v.cbegin(), v.cend(), bind(modulus<>(), placeholders::_1, 2))) {
        cout << "None of them are odd." << endl;
    }

    struct DivisibleBy {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    if (any_of(v.cbegin(), v.cend(), DivisibleBy(7))) {
        cout << "At least one number is divisible by 7." << endl;
    }

    return;
}

void Algorithms::ExampleForEach() {
    std::vector<int> nums { 3, 4, 2, 8, 15, 267 };
    auto print = [](const int& n) { cout << setw(5) << n; };

    cout << "before: ";
    for_each(nums.cbegin(), nums.cend(), print);
    cout << endl;

    for_each(nums.begin(), nums.end(), [](int &n) { n += 10; });

    cout << "after: ";
    for_each(nums.cbegin(), nums.cend(), print);
    cout << endl;

    struct Sum {
        void operator()(int n) { sum += n; }
        int sum = 0;
    };

    auto s = for_each(nums.begin(), nums.end(), Sum());
    cout << s.sum << endl;

    return;
}

void Algorithms::ExampleCount() {
    constexpr array v = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    cout << "v: ";
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (const int target: { 3, 4, 5 }) {
        const auto num_items = count(v.cbegin(), v.cend(), target);
        cout << "number: " << target << ", match count in v: " << num_items << endl;
    }

    auto count_div4 = count_if(v.begin(), v.end(), [](int i){ return i % 4 == 0; });
    cout << "numbers divisible by 4: " << count_div4 << endl;

    return;
}

void Algorithms::ExampleMismatch() {
    auto mirror_ends = [](const string& in) { return string(in.begin(), mismatch(in.begin(), in.end(), in.rbegin()).first); };

    cout << mirror_ends("abXYZba") << endl;
    cout << mirror_ends("abca") << endl;
    cout << mirror_ends("aba") << endl;

    return;
}

void Algorithms::ExampleFind() {
    vector<int> v { 1, 2, 3, 4 };
    auto n1 = 3;
    auto n2 = 5;
    auto is_even = [](int i) { return i % 2 == 0; };

    auto result1 = find(begin(v), end(v), n1);
    auto result2 = find(begin(v), end(v), n2);
    auto result3 = find_if(begin(v), end(v), is_even);

    (result1 != end(v))
    ? cout << "v contains " << n1 << endl
    : cout << "v does not contain " << n1 << endl;

    (result2 != end(v))
    ? cout << "v contains " << n2 << endl
    : cout << "v does not contain " << n2 << endl;

    (result3 != end(v))
    ? cout << "v contains an even number: " << *result3 << endl
    : cout << "v does not contain even numbers" << endl;

    return;
}

void Algorithms::ExampleFindEnd() {
    vector<int> v { 1, 2, 3, 4, 1, 2, 3 ,4 ,1, 2, 3, 4 };
    vector<int>::iterator result;

    auto check = [&] {
        result == v.end()
        ? cout << "sequence not found." << endl
        : cout << "last occurrence is at: " << distance(v.begin(), result) << endl;
    };

    vector<int> t1 {1, 2, 3};
    result = find_end(v.begin(), v.end(), t1.begin(), t1.end());
    check();

    vector<int> t2 {4, 5, 6};
    result = find_end(v.begin(), v.end(), t2.begin(), t2.end());
    check();

    return;
}

void Algorithms::ExampleSearch() {
    vector<int> v1 {1, 2, 3, 4, 5, 6, 7};
    vector<int> v2 {3, 4, 5};

    auto iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());
    if (iter != v1.end()) {
        cout << "v2 is present at index " << (iter - v1.begin()) << endl;
    }
    else {
        cout << "v2 is not present in v1" << endl;
    }

    auto pred = [](int i, int j) {
        if (i > j) { return 1; }
        else { return 0; }
    };

    iter = search(v1.begin(), v1.end(), v2.begin(), v2.end(), pred);
    if (iter != v1.end()) {
        cout << "v1 elements are greater than v2 starting from position " << (iter - v1.begin()) << endl;
    }
    else {
        cout << "v1 elements are not greater than v2 elements consecutively" << endl;
    }

    return;
}

void Algorithms::ExampleCopy() {
    vector<int> v1 {1, 5, 7, 3, 8, 3};
    vector<int> v2(6);
    vector<int> v3(6);
    vector<int> v4(6);
    vector<int> v5(6);

    copy(v1.begin(), v1.begin() + 3, v2.begin());
    copy_n(v1.begin(), 4, v3.begin());
    copy_if(v1.begin(), v1.end(), v4.begin(), [](int i){ return i % 2 != 0; });
    copy_backward(v1. begin(), v1.begin() + 4, v5.begin() + 5);

    cout << "using copy() for v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "using copy_n() for v3: ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "using copy_if() for v4: ";
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "using copy_backward() for v5: ";
    copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return;
}

void Algorithms::ExampleMove() {
    vector<int> v1 {1, 2, 3, 4, 5};
    vector<int> v2 {7, 7, 7, 7, 7};
    vector<int> v3(5);

    cout << "v1: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "v3: ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    move(v1.begin(), v1.begin() + 4, v2.begin() + 1);
    move_backward(v1.begin(), v1.begin() + 4, v3.begin() + 5);

    cout << "changed v2 using move(): ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "changed v3 using move_backward(): ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return;
}

void Algorithms::ExamplePartition() {
    vector<int> v {2, 1, 5, 6, 8, 7};
    vector<int> v1 = v;
    vector<int> v2 = v;
    vector<int> v3;
    vector<int> v4;

    auto pred = [](int x) { return x%2 == 0; };

    is_partitioned(v1.begin(), v1.end(), pred)
    ? cout << "v1 is partitioned"
    : cout << "v1 is not partitioned";
    cout << endl;

    partition(v1.begin(), v1.end(), pred);

    is_partitioned(v1.begin(), v1.end(), pred)
    ? cout << "v1 is partitioned"
    : cout << "v1 is not partitioned";
    cout << endl;

    auto pt = partition_point(v1.begin(), v1.end(), pred);
    cout << "partition point of v: " << *pt << endl;
    cout << "the partitioned v: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    is_partitioned(v2.begin(), v2.end(), pred)
    ? cout << "v2 is partitioned"
    : cout << "v2 is not partitioned";
    cout << endl;

    stable_partition(v2.begin(), v2.end(), pred);

    is_partitioned(v2.begin(), v2.end(), pred)
    ? cout << "v2 is partitioned"
    : cout << "v2 is not partitioned";
    cout << endl;

    pt = partition_point(v2.begin(), v2.end(), pred);
    cout << "partition point of v2: " << *pt << endl;
    cout << "the partitioned v2: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;

    auto n = count_if(v.begin(), v.end(), pred);
    v3.resize(n);
    v4.resize(v.size() - n);

    partition_copy(v.begin(), v.end(), v3.begin(), v4.begin(), pred);

    cout << "The elements that return true for condition are: ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "The elements that return false for condition are: ";
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return;
}

void Algorithms::ExampleSort() {
    array<int, 10> array1 {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    array<int, 10> array2 = array1;
    array<int, 3> array3;

    auto n = sizeof(array1) / sizeof(array1[0]);

    sort(array1.begin(), array1.begin() + n, less<int>());

    cout << "array1 as sorted array: ";
    copy(array1.begin(), array1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "array2 as unsorted array: ";
    copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto range1 = 6;
    auto range2 = 5;

    if (is_sorted(array1.begin(), array1.begin() + range1)) {
        cout << "array1 sorted in the range: " << range1 << endl;
    }
    else {
        cout << "array1 not sorted in the range: " << range1 << endl;
    }

    if (is_sorted(array2.begin(), array2.begin() + range2)) {
        cout << "array2 sorted in the range: " << range2 << endl;
    }
    else {
        cout << "array2 not sorted in the range: " << range2 << endl;
    }

    auto iter = is_sorted_until(array2.begin(), array2.begin() + 8);

    cout << "There are " << (iter - array2.begin()) << " sorted elements in the list and the first unsorted element is " << *iter << endl;

    partial_sort_copy(array1.begin(), array1.end(), array3.begin(), array3.end());

    cout << "array3 as partial sort copied from array1: ";
    copy(array3.begin(), array3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return;
}