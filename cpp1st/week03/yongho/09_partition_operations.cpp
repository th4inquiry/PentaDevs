#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //Initializing vector
    std::vector<int> vect = { 2,1,5,6,8,7 };

    std::cout << "The initial vector is : ";
    for (int& x : vect)
        std::cout << x << " ";

    //Checking if vector is partitioned
    //using is_partitioned()
    std::is_partitioned(vect.begin(), vect.end(), [](int x) {return x % 2 == 0; }) ?
        std::cout << "\n\nVector is partitioned" :
        std::cout << "\n\nVector is not partitioned";
    std::cout << std::endl;

    //Partitioning vector using partition()
    std::partition(vect.begin(), vect.end(), [](int x) {return x % 2 == 0; });

    //Checking if vector is partitioned
    //using is_partitioned()
    std::is_partitioned(vect.begin(), vect.end(), [](int x) {return x % 2 == 0; }) ?
        std::cout << "\n\nNow, vector is partitioned after partition operation" :
        std::cout << "\n\nVector is still not partitioned after partition operation";
    std::cout << std::endl;

    //Displaying partitioned Vector
    std::cout << "\n\nThe partition vector is : ";
    for (int& x : vect)
        std::cout << x << " ";

    std::cout << "\n\n";
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Initializing vector
    std::vector<int> vect1 = { 2, 1,5,6,8,7, 9, 10 };

    //partitioning vector using stable_partition()
    //in sorted order
    std::stable_partition(vect1.begin(), vect1.end(), [](int x) {return x % 2 == 0; });

    //Displaying partitioned Vector
    std::cout << "The partitioned vector is : ";
    for (int& x : vect1)
        std::cout << x << " ";

    //Declaring iterator
    std::vector<int>::iterator it1;

    //using partition_point() to get ending position of partition
    auto it = std::partition_point(vect1.begin(), vect1.end(), [](int x) {return x % 2 == 0; });

    //Displaying partitioned Vector
    std::cout << "\n\nThe vector elements returning true for condition are : ";
    for (it1 = vect1.begin(); it1 != it; it1++)
    {
        std::cout << *it1 << " ";
    }

    std::cout << std::endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Initializing vector
    std::vector<int> vect00 = { 2,1,5,6,8,7 };

    //Declaring vector1
    std::vector<int> vect01;

    //Declaring vector2
    std::vector<int> vect02;

    //Resizing vectors to suitable size using count_if() and resize()
    int n = std::count_if(vect00.begin(), vect00.end(), [](int x) {return x % 2 == 0; });

    vect01.resize(n);
    vect02.resize(vect00.size() - n);

    //Using partition_copy() to copy partitions
    std::partition_copy(vect00.begin(), vect00.end(), vect01.begin(), vect02.begin(), [](int x) { return x % 2 == 0; });

    //Displaying partitoned Vector
    std::cout << "The elements that return true for condition are : ";
    for (int& x : vect01)
        std::cout << x << " ";
    std::cout << std::endl;

    //Displaying partitoned Vector
    std::cout << "The elements that return false for condition are : ";
    for (int& x : vect02)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}

