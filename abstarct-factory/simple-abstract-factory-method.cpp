#include<iostream>
#include<memory>
#include<string>

// Abstract Products
class Pizza {
	public:
	virtual ~Pizza() = default;
	virtual void prepare() = 0;
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual std::string getType() const = 0;
};

class Drink {
	public:
	virtual ~Drink() = default;
	virtual void server() = 0;
	virtual std::string getType() const = 0;
};

// Concreate Products - Italian Family 
class MargheritaPizza : public Pizza {
	void prepare() override { std::cout<<"Preparing Margherita \n";}
	void bake() override { std::cout<<"Baking Margherita at 250 C\n";}
	void cut() override { std::cout<<"Cutting Margherita into 8 slices\n";}
	std::string getType() const override { return "Margherita";}
};

class Cola : public Drink {
	void server() override { std::cout<<"Servering Italian Cola";}
	std::string getType() const override	{ return "Cola";}
};

// Concreate Products - Mexican Family
class MexicanPizza : public Pizza {
	void prepare() override { std::cout<<"Preparing Mexican Pizza \n";}
	void bake() override { std::cout<<"Baking Mexican Pizza at 250 C\n";}
	void cut() override { std::cout<<"Cutting Mexican Pizza into 8 slices\n";}
	std::string getType() const override { return "Mexican Pizza";}
};

class Margharita : public Drink {
	void server() override { std::cout<<"Serving Mexican Margharita\n";}
	std::string getType() const override { return "Margharita";}
};

// Abstract Factory
class MealFactory {
	public:
		virtual ~MealFactory() = default;
		
		//Factory Method
		virtual std::unique_ptr<Pizza> createPizza() = 0;
		virtual std::unique_ptr<Drink> createDrink() = 0;
};

// Concrete Factories
class ItalianMealFactory : public MealFactory {
	std::unique_ptr<Pizza> createPizza() override {
		return std::make_unique<MargheritaPizza>();
	}
	std::unique_ptr<Drink> createDrink() override {
		return std::make_unique<Cola>();
	}
};

class MexicanMealFactory : public MealFactory {
    std::unique_ptr<Pizza> createPizza() override {
        return std::make_unique<MexicanPizza>();
    }
    std::unique_ptr<Drink> createDrink() override {
        return std::make_unique<Margharita>();
    }
};

// Client Code
void OrderMeal(MealFactory& factory) {
	auto pizza = factory.createPizza();
	auto drink = factory.createDrink();
	
	std::cout<<"-- New Order --"<< std::endl;
	std::cout<<"Pizza : "<<pizza->getType() <<std::endl;
	pizza->prepare();

	std::cout<<"Drink :"<<drink->getType() <<std::endl;
	drink->server();

	std::cout<<"Meal is ready!\n";
}

// Main
int main() {
	
	std::cout<<"-- Customer goes to Italian Store --\n";
	ItalianMealFactory italianFactory;
	OrderMeal(italianFactory);

	std::cout<<"-- Customer goes to Mexican Store --\n";
	MexicanMealFactory mexicanFactory;
	OrderMeal(mexicanFactory);

	return 0;
}
