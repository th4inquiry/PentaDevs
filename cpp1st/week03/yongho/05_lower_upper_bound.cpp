#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //Initializing vector with array values
    int arr[] = { 5, 20, 10, 15, 21, 23, 42, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vect(arr, arr + n);

    //Sort the array to make sure that lower_bound() and upper_bound() work
    std::sort(vect.begin(), vect.end());

    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";

    //returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);

    //returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);

    std::cout << "\n\nThe lower bound is at position: ";
    std::cout << q - vect.begin() << std::endl;

    std::cout << "\n\nThe upper bound is at position: ";
    std::cout << p - vect.begin() << std::endl;

    return 0;
}
