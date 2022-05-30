#include <algorithm>
#include <iostream>
#include <vector>

class SortTester
{
public:
    struct Data
    {
        int a;
        int b;
    };
    void testStableSort()
    {
        std::vector<Data> v = {{2,9},{1,4},{1,2},{2,1},{2,4}};
        std::vector<Data> v1 = v;
        std::stable_sort(v.begin(), v.end(), [](Data a, Data b) {return a.a<b.a;});
        std::sort(v1.begin(), v1.end(), [](Data a, Data b) {return a.a<b.a;});

        std::for_each(v.begin(), v.end(), [](Data n){std::cout << " " << n.a << "," << n.b;});
        std::cout << std::endl;
        std::for_each(v1.begin(), v1.end(), [](Data n){std::cout << " " << n.a << "," << n.b;});

    }
};

int main()
{
    SortTester tester;
    tester.testStableSort();
    return 0;
}
