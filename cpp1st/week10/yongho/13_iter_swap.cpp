#include <algorithm>
#include <vector>
#include <iostream>

// reference link:
// https://m.cplusplus.com/reference/algorithm/iter_swap/?kw=iter_swap
// container에서 iterator의 값을 바꿀 때 주로 사용.
// swap은 변수끼리 값을 바꿀 때.

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
    std::vector<int> v = {1,2,3,4,5};
    print(v.begin(), v.end());

    std::iter_swap(v.begin()+1, v.begin()+2);
    print(v.begin(), v.end());

    //======================================
    int myInts[] = {10, 20, 30, 40, 50};
    std::vector<int> myVector (4, 99);
    print(myVector.begin(), myVector.end());

    std::iter_swap(myInts, myVector.begin());

    std::iter_swap(myInts+3, myVector.begin()+2);

    std::cout << "myVector contains: ";
    for(std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}