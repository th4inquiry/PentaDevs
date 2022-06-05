#include <algorithm>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

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
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "Original---" << std::endl;
    print(vec.begin(), vec.end());

    //find the specific element location in container
    auto result = std::find(vec.begin(), vec.end(), 3);
    std::cout << "Number 3 is " << std::distance(vec.begin(), result) +1 << " th element" << std::endl;
    
    //find the all specific element location in whole container
    auto current = vec.begin();
    while(true)
    {
        current = std::find(current, vec.end(), 3);
        if(current == vec.end()) break;
        std::cout << "Nunmber 3 is " << std::distance(vec.begin(), current) + 1 << " th element" << std::endl;
        current++;
    }

    //find 사용지 주의 점
    //container 가 기본적으로 find 함수를 지원한다면 이를 사용하는 것이 훨씬 빠르다.
    //algorithm library에서의 find 함수는 그 container가 어떤 구조를 가지고 있는 지에 대한 정보가 하나도 없기 때문이다.
    //find 함수는 container가 find함수를 지원하지 않는 경우에만 사용할 것.

    //find_if
    current = vec.begin();
    while (true)
    {
        current = std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
        if (current == vec.end()) break;
        std::cout << *current << " is the value that remainder is 2 when diveded by 3." << std::endl;
        current++;
    }
}