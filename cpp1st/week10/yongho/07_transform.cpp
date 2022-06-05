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

    std::vector<int> vec2(6, 0);

    std::cout << "Before vec & vec2---" << std::endl;
    print(vec.begin(), vec.end());
    print(vec2.begin(), vec2.end());
    //std::transform(vec.begin(), vec.end(), vec.begin(), 
    //                [](int i) {return i+1;});

    //Applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result
    std::transform(vec.begin(), vec.end(), vec2.begin(), 
                    [](int i) {return i+1;});

    std::cout << "After vec & vec2---" << std::endl;
    print(vec.begin(), vec.end());
    print(vec2.begin(), vec2.end());
}
