#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <string>

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

struct is_odd 
{
    bool operator()(const int& i)
    {
        return i % 2 == 1;
    }
};

bool odd(const int& i) { return i % 2 == 1; }

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "Before---" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "After remove odd number---" << std::endl;
    //vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    vec.erase(std::remove_if(vec.begin(), vec.end(), odd), vec.end());
    
    print(vec.begin(), vec.end());
}
