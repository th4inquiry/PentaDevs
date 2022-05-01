
// assert is evaluated in run-time
// static_assert is evaluated in compile-time

#include <iostream>
#include <cassert>

using namespace std;

template <int N>
void func()
{
    static_assert(N >= 5, "N is less than 5");
}

int main()
{
    assert(true);
    static_assert(sizeof(int) == 4, "integer size is not 4 bytes");

    func<5>();

    return 0;
}