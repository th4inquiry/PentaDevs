// static polymorphism

#include <iostream>

using namespace std;

template <class T>
struct Animal
{
    void cry()
    {
        (static_cast<T*>(this))->impl(); 
    }
};

struct Cat : public Animal<Cat> 
{ 
    int a = 101;
    void impl() 
    {
        cout << "Meow~ : " << a << endl;
    }
};

struct Dog : public Animal<Dog>
{ 
    void impl() 
    { 
        cout << "Woof!" << endl;
    }
};


int main()
{
    Animal<Cat> kitty;
    kitty.cry();
    
    Animal<Dog> puppy;
    puppy.cry();

    Cat cat;
    cat.cry();
    
    Dog dog; 
    dog.cry();

    return 0;
}


//Animal animal = new Cat();
//animal->cry() => meow