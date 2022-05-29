#include <algorithm>
#include <functional>
#include <iostream>
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
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(9);

    std::cout << "Show vector---" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "Max : " << *std::max_element(vec.begin(), vec.end()) << std::endl;
    std::cout << "Min : " << *std::min_element(vec.begin(), vec.end()) << std::endl;
}