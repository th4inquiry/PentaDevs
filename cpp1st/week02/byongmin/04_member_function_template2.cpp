// member function tempalte (2)

#include <iostream>
#include <memory>

using namespace std;

class Cat
{
public:
    Cat() { cout << "Cat ctor..." << endl; }
    ~Cat() { cout << "Cat dtor..." << endl; }

    void cry() { cout << "Meow~" << endl; }
};

class Dog
{
public:
    Dog() { cout << "Dog ctor..." << endl; }
    ~Dog() { cout << "Dog dtor..." << endl; }

    void cry() { cout << "Woof!" << endl; }
};

class AnimalObjectManager
{
public:
    template<typename T>
    unique_ptr<T> createAnimalObject();
};

template<typename T>
unique_ptr<T> AnimalObjectManager::createAnimalObject()
{
    return make_unique<T>();
};

int main()
{
    AnimalObjectManager manager;
    auto kitty = manager.createAnimalObject<Cat>();
    kitty->cry();

    auto puppy = manager.createAnimalObject<Dog>();
    puppy->cry();

    return 0;
}

