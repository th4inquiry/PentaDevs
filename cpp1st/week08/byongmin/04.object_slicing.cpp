
// exception object to reference (object slicing problem)

#include <iostream>

class Animal
{
public:
    Animal() = default;
    virtual ~Animal() = default;

    virtual void speak()
    {
        std::cout << "Animal " << animalData <<std::endl;
    }

private:
    int animalData = 0;
};

class Dog : public Animal
{
public:
    Dog(int data) : dogData{ data } {};
    
    void speak() override
    {
        std::cout << "woof~ " << dogData << std::endl;
    }

private:
    int dogData = 0;
};

int main()
{
    Dog dog{ 9 };
    Animal animal = dog;

    // Use reference to prevent object slicing as following
    // Animal& animal = dog;

    dog.speak();
    animal.speak();

    return 0;
}