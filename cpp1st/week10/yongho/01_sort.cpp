#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end)
    {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

struct custom_compare
{
    bool operator()(const int& a, const int& b) const
    {
        return a > b;
    }
};

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "Before sort ---" << std::endl;
    print(vec.begin(), vec.end()); 

    //Support only 'RandomAccessIterator type' iterator like vector, dec not support 'BidirectionalIterator type' like list.

    //Sorted with the default operator<
    //std::sort(vec.begin(), vec.end()); 
    
    //user dedined compare condition
    //std::sort(vec.begin(), vec.end(), custom_compare()); 

    //sorted with the standard library compare function object
    //std::sort(vec.begin(), vec.end(), std::greater<int>()); 
    
    //sorted with a lamda expression
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "After sort ---" << std::endl;
    print(vec.begin(), vec.end());
}