#include <iostream>
#include <algorithm>
#include <vector>

//reference link
// https://www.cplusplus.com/reference/algorithm/lower_bound/
// lower_bound : 특정 값보다 (비교값 포함하여) 작지 않은 첫 번째 원소를 찾습니다. 비교값과 동일한 값이 있을 경우 비교값을 return함.
// 찾으려는 key 값보다 같거나 큰 숫자가 배열의 몇 번째에 처음 등장하는지 찾아준다.
// upper_bound : 특정 값보다 큰 첫 번째 원소를 찾습니다.

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
    int myints[] = { 10, 20, 30, 80, 60, 90, 70, 40};
    std::vector<int> v(myints, myints + 8);
    print(v.begin(), v.end());

    std::sort(v.begin(), v.end()); 
    print(v.begin(), v.end());
    
    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 50);
    up = std::upper_bound(v.begin(), v.end(), 50);

    std::cout << "lower_bound at position " << (low - v.begin()) << std::endl;
    std::cout << "lower_bound value : " << *low << std::endl;
    std::cout << "upper_bound at position " << (up - v.begin()) << std::endl;
    std::cout << "upper_bound value : " << *up << std::endl;
    
}