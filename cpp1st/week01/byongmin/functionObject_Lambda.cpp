// function object(Functor) vs. lamda

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Functor
class Multiples
{
public:
    explicit Multiples(int multipleNumber) 
    : myMultiple(multipleNumber)
    {
    }

    void operator()(int num) const
    {
        cout << "input: " <<  num << '\t' << "result = " << num * myMultiple << endl;
    }

private:
    int myMultiple;
};

int main()
{
    vector<int> data {1, 2, 3, 4, 5};
    int multipleValue = 3;

    cout << "Multiples of " << multipleValue << endl;

    // 1. using functor
    for_each(data.begin(), data.end(), Multiples(multipleValue));

    cout << endl;

    // 2. using lambda
    for_each(data.begin(), data.end(), 
    [multipleValue](int num) 
    {
        cout << "input: " <<  num << '\t' << "result = " << num * multipleValue << endl;
    }
    );

    return 0;
}
