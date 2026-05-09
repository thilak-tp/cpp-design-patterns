#include<iostream>
#include<memory>
#include<string>

// Product Interface
class Pizza {
	public:
	virtual ~Pizza() = default;
	virtual void prepare() = 0;
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual std::string getType() const = 0;
};

// Concreate Products
class MargheritaPizza : public Pizza {
	void prepare() override { std::cout<<"Preparing Margherita \n";}
	void bake() override { std::cout<<"Baking Margherita at 250 C\n";}
	void cut() override { std::cout<<"Cutting Margherita into 8 slices\n";}
	std::string getType() const override { return "Margherita";}
};


class MexicanPizza : public Pizza {
	void prepare() override { std::cout<<"Preparing Mexican Pizza \n";}
	void bake() override { std::cout<<"Baking Mexican Pizza at 250 C\n";}
	void cut() override { std::cout<<"Cutting Mexican Pizza into 8 slices\n";}
	std::string getType() const override { return "Mexican Pizza";}
};

// Creater (Factory Method)
class PizzaStore {
	public:
		virtual ~PizzaStore() = default;
		
		//Factory Method
		virtual std::unique_ptr<Pizza> createPizza() = 0;

		//Method that uses factory method
		void orderPizza() {
			auto pizza = createPizza();
			std::cout<<"-- Order a "<< pizza->getType() <<" Pizza --\n";
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			std::cout<<"Pizza is ready\n\n";
		}
};

// Concrete Creators 
class ItalianPizzaStore : public PizzaStore {
	std::unique_ptr<Pizza> createPizza() override {
		return std::make_unique<MargheritaPizza>();
	}
};

class MexicanPizzaStore : public PizzaStore {
	std::unique_ptr<Pizza> createPizza() override {
		return std::make_unique<MexicanPizza>();
	}
};

// Main
int main() {
	
	std::cout<<"-- Customer goes to Italian Store --\n";
	ItalianPizzaStore italianStore;
	italianStore.orderPizza();

	std::cout<<"-- Customer goes to Mexican Store --\n";
	MexicanPizzaStore mexicanStore;
	mexicanStore.orderPizza();
	return 0;
}
