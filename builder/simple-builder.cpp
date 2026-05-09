#include <iostream>
#include <string>

class Pizza {
public:
    std::string size, crust, sauce, toppings;

    void show() {
        std::cout << size << " Pizza (" << crust << " crust, " 
                  << sauce << " sauce, Toppings: " << toppings << ")\n";
    }
};

// Builder
class PizzaBuilder {
    Pizza pizza;
public:
    PizzaBuilder& setSize(const std::string& s) { pizza.size = s; return *this; }
    PizzaBuilder& setCrust(const std::string& c) { pizza.crust = c; return *this; }
    PizzaBuilder& setSauce(const std::string& s) { pizza.sauce = s; return *this; }
    PizzaBuilder& addToppings(const std::string& t) { pizza.toppings = t; return *this; }
    
    Pizza build() { return pizza; }
};

int main() {
    Pizza p1 = PizzaBuilder()
                .setSize("Large")
                .setCrust("Thin")
                .setSauce("Tomato")
                .addToppings("Cheese, Basil")
                .build();

    p1.show();

    return 0;
}
