#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Drink.h"
#include "SideDish.h"
#include <vector>
#include <string>

enum class OrderType { DINE_IN, TAKEOUT, DELIVERY };

class Order {
private:
    int orderId;
    OrderType orderType;
    std::vector<Pizza> orderedPizzas;
    std::vector<Drink> orderedDrinks;
    std::vector<SideDish> orderedSideDishes;

public:
    Order(int id, OrderType type);
    void addPizza(const Pizza& pizza);
    void addDrink(const Drink& drink);
    void addSideDish(const SideDish& sideDish);
    double calculateTotal() const;
    void display() const;
};

#endif // ORDER_H