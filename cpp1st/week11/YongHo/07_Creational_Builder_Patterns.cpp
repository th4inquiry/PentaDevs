//Creational design patterns are design patterns that deal with object creation mechanisms, 
//trying to create objects in a manner suitable to the situation.

#include <iostream>
#include <memory>

class Pizza {
    private:
        std::string doughName;
        std::string sauceName;
        std::string toppingName;

    public:
        void SetDough(const std::string& dough)
        {
            doughName = dough;
        }

        void SetSauce(const std::string& sauce)
        {
            sauceName = sauce;
        }

        void SetTopping(const std::string& topping)
        {
            toppingName = topping;
        }

        void Open() const
        {
            std::cout << "The Pizza have " <<
            doughName << " dough, " <<
            sauceName << " sauce, " <<
            toppingName << " topping, " << std::endl;
        }
};

class PizzaBuilder
{
    public:
        virtual ~PizzaBuilder() = default;
        void CreateNewPizza()
        {
            pizzaName = std::make_unique<Pizza>();
        }

        Pizza* GetPizza()
        {
            return pizzaName.release();
        }
        virtual void BuildDough() = 0;
        virtual void BuildSauce() = 0;
        virtual void BuildTopping() = 0;
    protected:
        std::unique_ptr<Pizza> pizzaName; 
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
    public:
        ~HawaiianPizzaBuilder() override = default;
        void BuildDough() override
        {
            pizzaName->SetDough("Hawaiian dough");
        }

        void BuildSauce() override
        {
            pizzaName->SetSauce("Hawaiian sauce");
        }

        void BuildTopping() override
        {
            pizzaName->SetTopping("Hawaiian topping");
        }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
    public:
        ~SpicyPizzaBuilder() override = default;
        void BuildDough() override
        {
            pizzaName->SetDough("Spicy dough");
        }

        void BuildSauce() override
        {
            pizzaName->SetSauce("Spicy sauce");
        }

        void BuildTopping() override
        {
            pizzaName->SetTopping("Spicy topping");
        }
};

class Cook
{
    public:
        void OpenPizza() const
        {
            pizzaBuilderName->GetPizza()->Open();
        }
        void CreatePizza(PizzaBuilder* pizzaBuilder)
        {
            pizzaBuilderName = pizzaBuilder;
            pizzaBuilderName->CreateNewPizza();
            pizzaBuilderName->BuildDough();
            pizzaBuilderName->BuildSauce();
            pizzaBuilderName->BuildTopping();
        }
    private:
        PizzaBuilder* pizzaBuilderName;
};

int main()
{
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.CreatePizza(&hawaiianPizzaBuilder);
    cook.OpenPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.CreatePizza(&spicyPizzaBuilder);
    cook.OpenPizza();
}