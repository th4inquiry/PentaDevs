#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void func(int c)
{
    if (c > numeric_limits<char>::max())
    {
        throw invalid_argument("func argument too large.");
    }
}

int main()
{
    try
    {
        func(256); // cause an exception to throw
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}