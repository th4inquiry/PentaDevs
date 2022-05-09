#include <string>
#include <iostream>
using namespace std;

class MyException{};
class Dummy
{
public:
    Dummy(string name) : myName(name)
    { 
        print("Created Dummy:"); 
    }

    Dummy(const Dummy& other) : myName(other.myName)
    { 
        print("Copy created Dummy:"); 
    }

    ~Dummy()
    { 
        print("Destroyed Dummy:"); 
    }

    void set(string name)
    {
        myName = name;
    }

private:
    void print(string message) 
    { 
        cout << message << " " << myName <<  endl; 
    }

    string myName;
};

void C(Dummy dummy)
{
    cout << "Entering FunctionC" << endl;

    dummy.set("C");

    cout << "++ throw exception" << endl;
    throw MyException();

    cout << "Exiting FunctionC" << endl;
}

void B(Dummy dummy)
{
    cout << "Entering FunctionB" << endl;

    dummy.set("B");
    C(dummy);

    cout << "Exiting FunctionB" << endl;
}

void A(Dummy dummy)
{
    cout << "Entering FunctionA" << endl;

    dummy.set("A");
    B(dummy);

    cout << "Exiting FunctionA" << endl;
}

int main()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy dummy("M");
        A(dummy);
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }

    cout << "Exiting main." << endl;
}

/* Output:
    Entering main
    Created Dummy: M
    Copy created Dummy: M
    Entering FunctionA
    Copy created Dummy: A
    Entering FunctionB
    Copy created Dummy: B
    Entering FunctionC
    ++ throw exception
    Destroyed Dummy: C
    Destroyed Dummy: B
    Destroyed Dummy: A
    Destroyed Dummy: M
    Caught an exception of type: 11MyException
    Exiting main.
*/