#ifndef MENU_H
#define MENU_H

#include "Pizza.h"
#include "Drink.h"
#include "SideDish.h"
#include <vector>

class Menu {
private:
    std::vector<Pizza> availablePizzas;
    std::vector<Drink> availableDrinks;
    std::vector<SideDish> availableSideDishes;
    std::vector<Topping> availableToppings;

public:
    Menu();
    void addPizza(const Pizza& pizza);
    void addDrink(const Drink& drink);
    void addSideDish(const SideDish& sideDish);
    void addTopping(const Topping& topping);
    void displayMenu() const;

    const std::vector<Pizza>& getAvailablePizzas() const;
    const std::vector<Drink>& getAvailableDrinks() const;
    const std::vector<SideDish>& getAvailableSideDishes() const;
    const std::vector<Topping>& getAvailableToppings() const;
};

#endif // MENU_H