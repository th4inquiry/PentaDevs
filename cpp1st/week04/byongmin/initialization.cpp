#include <iostream>
#include <memory>

using namespace std;

class Person
{
public:
    Person() = delete;
    explicit Person(string name) : myName(name) 
    { 
        cout << "person " << myName << " ctor() ++" << endl; 
    }

    ~Person() 
    { 
        cout << "person " << myName << " dtor() --"<< endl; 
    }

private:
    string myName;
};


int main()
{
    // ctor() ? 
    // copy ctor() ?
    // move ctro() ?
    // universal initialization(uniform initialization)
    char c = 'a';
    char c1 ('a');
    char c2 {'a'};
    
    char c3(); // it's function declaration. warning
    //c3 = 'a';  // not allowed

    char *pc1 = new char ('a');
    delete[] pc1;

    char *pc2 = new char[2] {'a', 'b'};
    delete[] pc2;

    //char *pc3 = new char[2] ('a', 'b');     // not allowed
    //delete[] pc3;


    char* myTest = new char[2] {'a', 'b'};
    delete[] myTest;


    cout << "---- pointer array ---------------" << endl;
    Person* person = new Person[2] {Person("a"), Person("b")};
    delete[] person;

    cout << "---- unique_ptr array leak --------" << endl;
    unique_ptr<Person> p1(new Person[2] {Person("a"), Person("b")});     // memory leak

    cout << "---- unique_ptr array --------" << endl;
    unique_ptr<Person[]> p2(new Person[2] {Person("a"), Person("b")});
    
    cout << "---- make_unique -----------" << endl;
    auto p3 = make_unique<Person>("a");
    //auto p4 = make_unique<Person[]>(2);     // array initialization is not allowed


    return 0;
}