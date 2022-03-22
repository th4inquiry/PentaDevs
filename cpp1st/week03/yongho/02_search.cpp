#include <iostream>
#include <algorithm>

void show(int a[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
    {
        if (i == arraysize - 1)
        {
            std::cout << a[i];
        }
        else
        {
            std::cout << a[i] << ",";
        }
    }
}

int main()
{
    int a[] = { 1,5,8,9,6,7,3,4,2,0 };
    int asize = sizeof(a) / sizeof(a[0]);
    std::cout << "\nThe current array is : \n";
    show(a, asize);

    std::cout << "\n\nLet's say we want to search for number ";
    std::cout << "\n2 in the array So, we first sort the array";

    std::sort(a, a + asize);

    std::cout << "\n\nThe array after sorting is : \n";
    show(a, asize);

    std::cout << "\n\nNow, we do the binary search 2";
    if (std::binary_search(a, a + 10, 2))
        std::cout << "\nElement found in the array";
    else
        std::cout << "\nElement not found in the array";

    std::cout << "\n\nNow, say we want to search for 10";
    if (std::binary_search(a, a + 10, 10))
        std::cout << "\nElement found in the array";
    else
        std::cout << "\nElement not found in the array";

    return 0;
}
