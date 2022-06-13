//The Factory Design Pattern is useful in a situation that requires the creation of many different types of objects,
// all derived from a common base type.
// The Factory Method defines for creating the objects, which subclasses can then override to specify the derived type that will be created.

#include <stdexcept>
#include <iostream>
#include <memory>

class Pizza
{
    public:
        virtual int GetPrice() const = 0;
        virtual std::string GetPizzaName() const { return ""; };
        virtual ~Pizza() {}; //without this, no destructor for derived Pizza's will be called
};

class HamAndMushroomPizza : public Pizza
{
    public:
        virtual int GetPrice() const { return 850; };
        virtual std::string GetPizzaName() const { return "HamAndMushroomPizza"; };
        virtual ~HamAndMushroomPizza() {};
};

class DeluxePizza : public Pizza
{
    public:
        virtual int GetPrice() const { return 1050; };
        virtual std::string GetPizzaName() const { return "DeluxePizza"; };
        virtual ~DeluxePizza() {};
};

class HawaiianPizza : public Pizza
{
    public:
        virtual int GetPrice() const { return 1150; };
        virtual std::string GetPizzaName() const { return "HawaiianPizza"; };
        virtual ~HawaiianPizza() {};
};

class PizzaFactory
{
    public:
        enum PizzaType
        {
            HamMushroom,
            Deluxe,
            Hawaiian
        };

        static std::unique_ptr<Pizza> createPizza(PizzaType pizzaType)
        {
            switch(pizzaType)
            {
                case HamMushroom:
                    return std::make_unique<HamAndMushroomPizza>();
                case Deluxe:
                    return std::make_unique<DeluxePizza>();
                case Hawaiian:
                    return std::make_unique<HawaiianPizza>();
            }
            throw "invalid pizza type.";
        }
};

//Create all available pizzas and print their prices
void ShowPizzaInformation(PizzaFactory::PizzaType pizzaType)
{
    std::unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzaType);
    std::cout << "Price of " << pizza->GetPizzaName() << " is " << pizza->GetPrice() << std::endl;
}

int main()
{
    ShowPizzaInformation(PizzaFactory::HamMushroom);
    ShowPizzaInformation(PizzaFactory::Deluxe);
    ShowPizzaInformation(PizzaFactory::Hawaiian);
}

