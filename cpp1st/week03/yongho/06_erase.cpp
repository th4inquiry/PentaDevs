#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //Initializing vector with array values
    int arr[] = { 5,10,15,20,20, 23,42,45, 40, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vect(arr, arr + n);

    std::cout << "Vector is : \n";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";

    //Delete second element of vector
    vect.erase(vect.begin() + 1);

    std::cout << "\n\nVector after erasing element : \n";
    for (int i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";

    //sorting to enable use of unique()
    std::sort(vect.begin(), vect.end());

    std::cout << "\n\nVector before removing duplicate : \n";
    for (int i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";

    //Delete the duplicate occurrences
    vect.erase(unique(vect.begin(), vect.end()), vect.end());

    std::cout << "\n\nVector after deleting duplicates : \n";
    for (int i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";

    return 0;
}