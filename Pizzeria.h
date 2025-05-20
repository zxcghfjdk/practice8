#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "Menu.h"
#include "Customer.h"
#include <vector>

class Pizzeria {
private:
    Menu menu;
    std::vector<Customer> customers;
    std::vector<Order> orders;
    int nextOrderId;

public:
    Pizzeria();
    void addCustomer(const Customer& customer);
    void placeOrder(const Customer& customer, const Order& order);
    void displayMenu() const;
    void displayOrders() const;

    const Menu& getMenu() const;
    void createOrderInteractively();
    void createCustomerInteractively();
};

#endif // PIZZERIA_H