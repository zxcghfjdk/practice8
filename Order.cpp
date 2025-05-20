#include "Order.h"

Order::Order(int id, OrderType type) : orderId(id), orderType(type) {}

void Order::addPizza(const Pizza& pizza) {
    orderedPizzas.push_back(pizza);
}

void Order::addDrink(const Drink& drink) {
    orderedDrinks.push_back(drink);
}

void Order::addSideDish(const SideDish& sideDish) {
    orderedSideDishes.push_back(sideDish);
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (const auto& pizza : orderedPizzas) {
        total += pizza.calculatePrice();
    }
    for (const auto& drink : orderedDrinks) {
        total += drink.calculatePrice();
    }
    for (const auto& sideDish : orderedSideDishes) {
        total += sideDish.calculatePrice();
    }
    if (orderType == OrderType::DELIVERY) {
        total += 5.0;
    }
    return total;
}

void Order::display() const {
    std::cout << "\nOrder #" << orderId << " (" << (orderType == OrderType::DINE_IN ? "Dine-in" :
        orderType == OrderType::TAKEOUT ? "Takeout" : "Delivery") << ")\n";
    std::cout << "Pizzas:\n";
    for (const auto& pizza : orderedPizzas) {
        pizza.display();
    }
    std::cout << "Drinks:\n";
    for (const auto& drink : orderedDrinks) {
        drink.display();
    }
    std::cout << "Side Dishes:\n";
    for (const auto& sideDish : orderedSideDishes) {
        sideDish.display();
    }
    std::cout << "Total: $" << calculateTotal() << std::endl;
}
