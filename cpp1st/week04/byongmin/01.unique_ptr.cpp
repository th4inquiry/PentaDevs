
#include <iostream>
#include <memory>

using namespace std;

class Animal
{
public:
    Animal() = delete;
    explicit Animal(string name) : myName(name) 
    { 
        cout << "Animal " << myName << " ctor() ++" << endl; 
    }

    virtual ~Animal() 
    { 
        cout << "Animal " << myName << " dtor() --"<< endl; 
    }

    virtual void print(string message) const
    { 
        cout << "  - [" << message << "] Animal " << myName << " call print()" << endl; 
    }


protected:
    string myName;
};


class Cat : public Animal
{
public:
    Cat() = delete;
    explicit Cat(string name) : Animal(name)
    { 
        cout << "Cat " << myName << " ctor() ++" << endl; 
    }

    virtual ~Cat() override
    { 
        cout << "Cat " << myName << " dtor() --"<< endl; 
    }

    virtual void print(string message) const override
    { 
        cout << "  - [" << message << "] Cat " << myName << " call print()" << endl; 
    }

};


void passPointer(const Animal* const animalObject)
{
    animalObject->print("PassPtr");
}

void passReference(unique_ptr<Animal>& animalObject)
{
    animalObject->print("PassRef");
}

void passUniquePtr(unique_ptr<Animal> animalObject)
{
    animalObject->print("PassUniquePtr");
}


int main()
{
    // creation
    unique_ptr<Animal> virtualAnimal(new Cat("Kitty"));
    auto animal = make_unique<Animal>("Tiger");
    auto cat = make_unique<Cat>("Navi");

    // pass raw pointer
    passPointer(virtualAnimal.get());

    // pass Reference. not recommended. use pointer rather than reference
    passReference(virtualAnimal);

    // pass unique_ptr
    passUniquePtr(move(virtualAnimal));

    // virtualAnimal object check
    if (nullptr == virtualAnimal)
    {
        cout << "  > virtualAnimal is nullptr" << endl;
        cout << "  > virtualAnimal itself address = " << &virtualAnimal << endl;
        cout << "  > virtualAnimal.get() = " << virtualAnimal.get() << endl;
    }

    return 0;
}