//Get subrange of equal elements
//Returns the bounds of the subrange that includes all the elements of the range [first, last) with values equivalent to val.
//특정 원소와 일치하는 원소들의 범위를 찾습니다.

#include <iostream>
#include <algorithm>
#include <vector>

bool myGreater (int i, int j) { return (i > j); }

template <typename Iter>
void print(Iter begin, Iter end)
{
    while(begin != end)
    {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main()
{
    // std::vector<int> vec = {5, 10, 15, 20, 5, 25, 20};
    // std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p;
    // p = std::equal_range(vec.begin(), vec.end(), 5);
    // std::cout << *p.first << std::endl;
    // std::cout << *p.second << std::endl;

    int myInts[] = {10, 20, 30, 30, 20, 10, 10, 20};
    std::vector<int> v(myInts, myInts + 8);
    print(v.begin(), v.end());
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;

    //using default comparison
    std::sort(v.begin(), v.end());  //10 10 10 20 20 20 30 30
    print(v.begin(), v.end());
    bounds = std::equal_range(v.begin(), v.end(), 20);

    std::cout << "bounds.first : " << *bounds.first << std::endl;
    std::cout << "bounds.second : " << *bounds.second << std::endl;

    std::cout << "bounds at positions " << (bounds.first - v.begin());
    std::cout << " and " << (bounds.second - v.begin()) << std::endl;

    //using "myGreater" as comparison
    std::sort(v.begin(), v.end(), myGreater);
    print(v.begin(), v.end());
    bounds = std::equal_range(v.begin(), v.end(), 20, myGreater);

    std::cout << "bounds.first : " << *bounds.first << std::endl;
    std::cout << "bounds.second : " << *bounds.second << std::endl;

    std::cout << "bounds at positions " << (bounds.first - v.begin());
    std::cout << " and " << (bounds.second - v.begin()) << std::endl;

    return 0;
}