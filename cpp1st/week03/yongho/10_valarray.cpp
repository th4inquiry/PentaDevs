#include <iostream>
#include <valarray>

int main()
{
    //Initializing valarray
    std::valarray<int> varr = { 10, 2, 20, 1, 30 };

    //Declaring new valarray
    std::valarray<int> varr1;

    //Using apply() to increment all elements by 5
    varr1 = varr.apply([](int x) {return x = x + 5; });

    //Displaying new elements value
    std::cout << "The new valarray with manipulated values is : ";
    for (int& x : varr1) std::cout << x << " ";
    std::cout << std::endl;

    //Displaying sum of both old and new valarray
    std::cout << "The sum of old valarray is : ";
    std::cout << varr.sum() << std::endl;
    std::cout << "The sum of new valarray is : ";
    std::cout << varr1.sum() << std::endl;

    //Displaying largest element of valarray
    std::cout << "The largest element of valarray is : ";
    std::cout << varr.max() << std::endl;

    //Displaying smallest element of valarray
    std::cout << "The smallest element of valarray is : ";
    std::cout << varr.min() << std::endl;

    //using shitf() to shift elements to left
    //shifts valarray by 2 position
    varr1 = varr.shift(2);

    //Displaying elements of valarray after shifting
    std::cout << "The new valarray after shifting is : ";
    for (int& x : varr1) std::cout << x << " ";
    std::cout << std::endl;

    //using cshift() to circulary shift elements to right
    //rotates valarray by 3 position
    varr1 = varr.cshift(-3);

    //Displaying elements of valarray after circular shifting
    std::cout << "The new valarray after circular shifting is : ";
    for (int& x : varr1) std::cout << x << " ";
    std::cout << std::endl;

    //Initializing
    std::valarray<int> varr01 = { 1,2,3,4 };
    std::valarray<int> varr02 = { 2,4,6,8 };

    //Displaying valarrays before swapping
    std::cout << "The contents of 1st valarray before swapping are : ";
    for (int& x : varr01) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "The contents of 2nd valarray before swapping are : ";
    for (int& x : varr02) std::cout << x << " ";
    std::cout << std::endl;

    //Use of swap() to swap the valarrays
    varr01.swap(varr02);

    //Displaying valarrays after swapping
    std::cout << "The contents of 1st valarray before swapping are : ";
    for (int& x : varr01) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "The contents of 2nd valarray before swapping are : ";
    for (int& x : varr02) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}