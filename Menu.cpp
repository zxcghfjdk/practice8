#include "Menu.h"

Menu::Menu() {
    availablePizzas.emplace_back("Margherita", 10.0, Size::MEDIUM, BaseType::TRADITIONAL);
    availablePizzas.emplace_back("Pepperoni", 12.0, Size::LARGE, BaseType::THIN);
    availableDrinks.emplace_back("Cola", 2.0, "0.5L");
    availableDrinks.emplace_back("Juice", 2.5, "1L");
    availableSideDishes.emplace_back("Fries", 3.0, "Small");
    availableSideDishes.emplace_back("Salad", 4.0, "Large");
    availableToppings.emplace_back("Cheese", 1.0);
    availableToppings.emplace_back("Mushrooms", 1.5);
}

void Menu::addPizza(const Pizza& pizza) {
    availablePizzas.push_back(pizza);
}

void Menu::addDrink(const Drink& drink) {
    availableDrinks.push_back(drink);
}

void Menu::addSideDish(const SideDish& sideDish) {
    availableSideDishes.push_back(sideDish);
}

void Menu::addTopping(const Topping& topping) {
    availableToppings.push_back(topping);
}

void Menu::displayMenu() const {
    std::cout << "\n--- Menu ---\n";
    std::cout << "Pizzas:\n";
    for (const auto& pizza : availablePizzas) {
        pizza.display();
    }
    std::cout << "\nDrinks:\n";
    for (const auto& drink : availableDrinks) {
        drink.display();
    }
    std::cout << "\nSide Dishes:\n";
    for (const auto& sideDish : availableSideDishes) {
        sideDish.display();
    }
    std::cout << "\nToppings:\n";
    for (const auto& topping : availableToppings) {
        std::cout << topping.name << ": $" << topping.price << std::endl;
    }
}

const std::vector<Pizza>& Menu::getAvailablePizzas() const {
    return availablePizzas;
}

const std::vector<Drink>& Menu::getAvailableDrinks() const {
    return availableDrinks;
}

const std::vector<SideDish>& Menu::getAvailableSideDishes() const {
    return availableSideDishes;
}

const std::vector<Topping>& Menu::getAvailableToppings() const {
    return availableToppings;
}