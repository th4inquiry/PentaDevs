#include <algorithm>
#include <vector>
#include <iostream>

//next_permutation : Transform range to next permutation
//prev_permutation : Transform rage to previous permutation

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
    std::vector<int> v(4);

    for(int i=0; i<4; i++)
    {
        v[i] = i+1;
    }

    std::cout << "---original---" << std::endl;

    print(v.begin(), v.end());

    std::cout << std::endl;
    std::cout << "---next_permutation---" << std::endl;
    do
    {
        for(int i=0 ; i<4 ; i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << "---After next_permutation---" << std::endl;
    print(v.begin(), v.end());

    std::sort (v.begin(), v.end());
    std::reverse (v.begin(), v.end());

    std::cout << std::endl;
    std::cout << "---prev_permutation---" << std::endl;
    do
    {
        for(int i=0; i <4 ; i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(v.begin(), v.end()));
    
    std::cout << "---After prev_permutation---" << std::endl;
    print(v.begin(), v.end());

    return 0;
}
