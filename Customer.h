#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Order.h"

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Order> orders;

public:
    Customer(const std::string& n, const std::string& contact);
    std::string getName() const;
    std::string getContactInfo() const;
    void addOrder(const Order& order);
    void displayOrders() const;
};

#endif // CUSTOMER_H