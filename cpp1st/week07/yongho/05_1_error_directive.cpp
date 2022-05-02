// Before using assertion, #error directive was used.
// Static assertion using #error directive
#include <iostream>
using namespace std;

//#define __geeksforgeeks 10

#if !defined(__geeksforgeeks)
    #error "Geeksforgeeks hasn't been defined yet".
#endif
int main()
{
    return 0;
}