#include <iostream>
#include <string>

// Base Component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const { return "Simple Coffee"; }
    virtual double getCost() const { return 2.0; }
};

// Concrete Component
class BasicCoffee : public Coffee {};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    std::string getDescription() const override { return coffee->getDescription(); }
    double getCost() const override { return coffee->getCost(); }
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    std::string getDescription() const override { return coffee->getDescription() + " + Milk"; }
    double getCost() const override { return coffee->getCost() + 0.5; }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}
    std::string getDescription() const override { return coffee->getDescription() + " + Sugar"; }
    double getCost() const override { return coffee->getCost() + 0.3; }
};

int main() {
    Coffee* coffee = new BasicCoffee();
    coffee = new Milk(coffee);
    coffee = new Sugar(coffee);

    std::cout << coffee->getDescription() << std::endl;
    std::cout << "Cost: $" << coffee->getCost() << std::endl;

    delete coffee;
    return 0;
}
