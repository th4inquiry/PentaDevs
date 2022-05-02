#include <iostream>
//uncomment to disable assert()
//#define NDEBUG
#include <cassert>

//Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

int main()
{
    assert(2+2==4);
    std::cout << "Execution continues past the first assert\n";

    assertm(2+2==4, "There are five lights");
    std::cout << "Execution continues past the second assert\n";

    assert((2*2==5) && "Yet another way to add assert message");
}