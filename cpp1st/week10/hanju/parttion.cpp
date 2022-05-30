//geeksforgeeks.org
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>

template <class Arg>
struct is_even
{
    bool operator()(const Arg& arg1) const
    {
        return (arg1 % 2) == 0;
    }
};
int main()
{
    typedef std::deque<int, std::allocator<int> > Deque;
    typedef std::ostream_iterator<int, char,
                                  std::char_traits<char> >
        Iter;

    const Deque::value_type a[] = { 1, 2, 3, 4, 5,
                                    6, 7, 8, 9, 10 };

    Deque d1(a + 0, a + sizeof a / sizeof *a);
    Deque d2(d1);
  
    std::cout << "Unpartitioned values: \t\t";
    std::copy(d1.begin(), d1.end(), Iter(std::cout, " "));

    auto pp2 = std::partition(d2.begin(), d2.end(), is_even<int>());
    std::cout << "\nPartitioned values: (" << std::distance(d2.begin(), pp2) << ")\t\t";
    std::copy(d2.begin(), d2.end(), Iter(std::cout, " "));

    auto pp1 = std::stable_partition(d1.begin(), d1.end(), is_even<int>());
    std::cout << "\nStable partitioned values: (" << std::distance(d1.begin(), pp1) << ")\t";
    std::copy(d1.begin(), d1.end(), Iter(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
