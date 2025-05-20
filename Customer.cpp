#include "Customer.h"

Customer::Customer(const std::string& n, const std::string& contact)
    : name(n), contactInfo(contact) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getContactInfo() const {
    return contactInfo;
}

void Customer::addOrder(const Order& order) {
    orders.push_back(order);
}

void Customer::displayOrders() const {
    std::cout << "\nCustomer: " << name << ", Contact: " << contactInfo << "\nOrders:\n";
    for (const auto& order : orders) {
        order.display();
    }
}