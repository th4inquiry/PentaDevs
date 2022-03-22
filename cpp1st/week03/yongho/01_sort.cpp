// C++ program to sort an array
// https://www.geeksforgeeks.org/sort-c-stl/

#include <algorithm>
#include <iostream>
#include <functional>

void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        std::cout << a[i] << " ";
}

//And interval has a start time and end time
struct Interval {
    int start, end;
};

//Compares two intervals according to starting times.
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int main()
{
    int a[] = { 1,5,8,9,6,7,3,4,2,0 };

    //size of the array
    int asize = sizeof(a) / sizeof(a[0]);
    std::cout << "\nThe array before sorting is : \n\n";
    show(a, asize);

    //default sort the array
    std::sort(a, a + asize);
    std::cout << "\n\nThe array after default sorting is :\n\n";
    show(a, asize);

    //descending sort the array
    std::sort(a, a + asize, std::greater<int>());
    std::cout << "\n\nThe array after descending sorting is :\n\n";
    show(a, asize);

    Interval arr[] = { {6,8}, {1,9}, {2,4},{4,7} };
    int n = sizeof(arr) / sizeof(arr[0]);

    //sort the intervals in increasing order of start time
    std::sort(arr, arr + n, compareInterval);
    std::cout << "\n\nIntervals sorted by start time: \n";
    for (int i = 0; i < n; i++)
        std::cout << "[" << arr[i].start << "," << arr[i].end << "]";

    return 0;
}

