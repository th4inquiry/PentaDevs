#include <iostream>

using namespace std;

class Dog
{
public:
    Dog() = default;

    void speak() noexcept
    {
        try
        {
            throw runtime_error("runtime exception error ");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';  // OK.
        }
        
        throw runtime_error("runtime exception error ");  // warning: 'throw' will always call 'terminate'
        
        cout << "woof~" << endl;
    }
};

int main()
{
    try
    {
        Dog dog;
        dog.speak();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "unknown exception error" << endl;
    }

    return 0;
}