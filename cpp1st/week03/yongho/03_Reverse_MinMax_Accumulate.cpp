#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
    //Initializing vector with array values
    int arr[] = { 10, 20, 5, 23, 42, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vect(arr, arr + n);

    std::cout << "Vector is: ";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";

    //Sorting the Vector in Ascending order
    std::sort(vect.begin(), vect.end());

    std::cout << "\n\nVector after sorting is: \n";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";

    //Reverse the Vector
    reverse(vect.begin(), vect.end());

    std::cout << "\n\nVector after reversing is: ";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";

    std::cout << "\n\nMaximum element of vector is : ";
    std::cout << *max_element(vect.begin(), vect.end());

    std::cout << "\n\nMimimum element of vector is : ";
    std::cout << *min_element(vect.begin(), vect.end());

    //Starting the summation from 0
    std::cout << "\n\nThe summation of vector elements is : ";
    std::cout << accumulate(vect.begin(), vect.end(), 0);

    return 0;
}

