# Algorithm


# [Sorting] std::sort

Sorts the elements in the range [first, last) in non-descending order. The order of equal elements is not guaranteed to be preserved.

A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence and any non-negative integer n such that it + n is a valid iterator pointing to an element of the sequence, comp(*(it + n), *it) (or *(it + n) < *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload resolution unless *std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.*

## Parameters
```first, last```	-	the range of elements to sort    
```policy```	-	the execution policy to use. See execution policy for details.    
```comp```	-	comparison function object (i.e. an object that satisfies the requirements of Compare) which returns ​true if the first argument is less than (i.e. is ordered before) the second.    
The signature of the comparison function should be equivalent to the following:

```cpp
 bool cmp(const Type1 &a, const Type2 &b);
```

While the signature does not need to have ```const &```, the function must not modify the objects passed to it and must be able to accept all values of type (possibly const) ```Type1``` and ```Type2``` regardless of value category (thus, Type1 & is not allowed, nor is Type1 unless for Type1 a move is equivalent to a copy (since C++11)).
The types Type1 and Type2 must be such that an object of type RandomIt can be dereferenced and then implicitly converted to both of them.​

Type requirements
-RandomIt must meet the requirements of ValueSwappable and LegacyRandomAccessIterator.
-The type of dereferenced RandomIt must meet the requirements of MoveAssignable and MoveConstructible.
-Compare must meet the requirements of Compare.

## Example
```cpp
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>
 
int main()
{
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    auto print = [&s](std::string_view const rem) {
        for (auto a : s) {
            std::cout << a << ' ';
        }
        std::cout << ": " << rem << '\n';
    };
 
    std::sort(s.begin(), s.end());
    print("sorted with the default operator<");
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object");
 
    struct {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object");
 
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;
    });
    print("sorted with a lambda expression");
}
```
## Reference
1. https://en.cppreference.com/w/cpp/algorithm/sort
<br>
<br>
<br>
   
# [Sorting] std::partial_sort
Rearranges elements such that the range [first, middle) contains the sorted middle − first smallest elements in the range [first, last).

The order of equal elements is not guaranteed to be preserved. The order of the remaining elements in the range [middle, last) is unspecified.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.
<br>

##### middle 이 의미하는 것은 포지션이다. 해당 인덱스가 가리키는 값을 의미하는 것이 아니다. 가령 middle 값을 6이라고 지정하면 해당 container 에서 아주 작은 숫자부터 오름차순으로 6개의 값을 정렬하고, 나머지는 unspecified order로 오른편으로 빼낸다. 즉, 인덱스 0 ~ 5까지를 전체 container 에서 아주 작은 값부터 5번째 큰 값까지 하나씩 채워 넣는다.

## Example
```cpp
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
 
auto print = [](auto const& s, int middle) {
    for (int a : s) { std::cout << a << ' '; }
    std::cout << '\n';
    if (middle > 0) {
        while (middle-->0) { std::cout << "──"; }
        std::cout << '^';
    } else if (middle < 0) {
        for (auto i = s.size() + middle; --i; std::cout << "  ");
        for (std::cout << '^'; middle++ < 0; std::cout << "──");
    }
    std::cout << '\n';  
};
 
int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    print(s, 0);
    std::partial_sort(s.begin(), s.begin() + 3, s.end());
    print(s, 3);
    std::partial_sort(s.rbegin(), s.rbegin() + 4, s.rend());
    print(s, -4);
    std::partial_sort(s.rbegin(), s.rbegin() + 5, s.rend(), std::greater{});
    print(s, -5);
}

// output :
// 5 7 4 2 8 6 1 9 0 3 
//  
// 0 1 2 7 8 6 5 9 4 3 
// ──────^
// 4 5 6 7 8 9 3 2 1 0 
//           ^────────
// 4 3 2 1 0 5 6 7 8 9 
//         ^──────────
```
## Reference
1. https://en.cppreference.com/w/cpp/algorithm/partial_sort
<br>
<br>
<br>

# [Sorting] std::nth_elemnet

![alt text](.\nthelement.png "std::nth_element")

## Example
```cpp
void SortingTest::testNthElement()
{
    auto printVec = [](auto& vec) {
        std::cout << "{ ";
        for (const auto& elem : vec)
        {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
    };

    std::vector<int> v{ 5, 10, 6, 4, 3, 2, 6, 7, 9, 3 };
    printVec(v);

    auto m = v.begin() + v.size() / 2;
    std::nth_element(v.begin(), m, v.end());
    std::cout << "\nThe median is " << v[v.size() / 2] << '\n';
    // The consequence of the inequality of elements before/after the Nth one:
    assert(std::accumulate(v.begin(), m, 0) < std::accumulate(m, v.end(), 0));
    printVec(v);

    // Note: comp function changed
    std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>{});
    std::cout << "\nThe second largest element is " << v[1] << '\n';
    std::cout << "The largest element is " << v[0] << '\n';
    printVec(v);
}
```

## Reference
1. https://en.cppreference.com/w/cpp/algorithm/nth_element
<br>
<br>
<br>

# Terms
## Lexicographical less-than comparison
A ```lexicographical comparison``` is the kind of comparison generally used to **sort words alphabetically in dictionaries**; It involves comparing sequentially the elements that have the same position in both ranges against each other until one element is not equivalent to the other. The result of comparing these first non-matching elements is the result of the lexicographical comparison.

If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one.<br>

###### lexicongraphical comparison 이라는 것은 사전의 알파벳 순으로 단어들을 정렬하는데 사용되는 비교 방식 중 하나. 같은 포지션에 있는 원소들을 순서대로 하나씩 비교하며, 하나의 원소라도 다르면 리턴한다. 이 때, 해당 원소의 값이 더 크면 ```lexicographical greater-than``` 이라 하고, 작으면 ```lexicographical less-than``` 이라고 한다. 또한, 더 작은 원소의 갯수를 갖는 경우도 마찬가지로 ```lexicographical less-than```이라 한다.
<br>

# Permutation
## std::next_permutation

Rearranges the elements in the range [first,last) into the next lexicographically greater permutation.

A permutation is each one of ```the N! possible arrangements``` the elements can take (where N is the number of elements in the range). Different permutations can be ordered according to how they compare lexicographicaly to each other; The first such-sorted possible permutation (the one that would compare lexicographically smaller to all other permutations) is the one which has all its elements sorted in ascending order, and the largest has all its elements sorted in descending order.

The comparisons of individual elements are performed using either operator< for the first version, or comp for the second.

__If the function can determine the next higher permutation, it rearranges the elements as such and returns ```true```. If that was not possible (because it is already at the largest possible permutation), it rearranges the elements according to the first permutation (sorted in ascending order) and returns ```false```.__

![alt text](.\permutation.png "permutation")

## Example
```cpp
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
```


## Reference
1. https://www.cplusplus.com/reference/algorithm/next_permutation/?kw=next_permutation
