#include <iostream>
#include <memory>

using namespace std;


class Cat
{
public:
    explicit Cat() { cout << "Cat ctor() ++" << endl; }
    ~Cat() { cout << "Cat dtor() --" << endl; }
    
    void print()
    {
        cout << "called print()" << endl;
    }
};


void checkCatAlive(weak_ptr<Cat> cat)
{
    auto resource =  cat.lock();
    if (resource)
    {
        cout << "Cat is alive" << endl;
    }
    else
    {
        cout << "Cat is NOT alive" << endl;
    }

}

int main()
{
    auto cat = make_shared<Cat>();
    checkCatAlive(cat);

    cat.reset();

    checkCatAlive(cat);

    return 0;
}