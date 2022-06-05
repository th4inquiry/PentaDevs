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
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "before---" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "Remove element value 3--" << std::endl;
    
    //'Remove' function use 'ForwardIterator' type.'Remove' function can be used in list, set, map. etc.
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end()); 
    print(vec.begin(), vec.end());
}
