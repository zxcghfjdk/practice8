#include "Pizza.h"

Pizza::Pizza(const std::string& n, double price, Size s, BaseType bt)
    : MenuItem(n, price), size(s), baseType(bt) {
    std::cout << "Pizza '" << name << "' created." << std::endl;
}

void Pizza::addTopping(const Topping& t) {
    toppings.push_back(t);
}

void Pizza::setSize(Size s) {
    size = s;
}

void Pizza::setBaseType(BaseType bt) {
    baseType = bt;
}

double Pizza::calculatePrice() const {
    double finalPrice = basePrice;
    for (const auto& t : toppings) {
        finalPrice += t.price;
    }
    switch (size) {
        case Size::SMALL: finalPrice *= 0.8; break;
        case Size::LARGE: finalPrice *= 1.2; break;
        default: break;
    }
    return finalPrice;
}

void Pizza::display() const {
    std::cout << "Pizza: " << name << ", Base Price: $" << basePrice;
    std::cout << ", Size: ";
    switch (size) {
        case Size::SMALL: std::cout << "Small"; break;
        case Size::MEDIUM: std::cout << "Medium"; break;
        case Size::LARGE: std::cout << "Large"; break;
    }
    std::cout << ", Base: ";
    switch (baseType) {
        case BaseType::THIN: std::cout << "Thin"; break;
        case BaseType::TRADITIONAL: std::cout << "Traditional"; break;
        case BaseType::THICK: std::cout << "Thick"; break;
    }
    std::cout << ", Toppings: ";
    if (toppings.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < toppings.size(); ++i) {
            std::cout << toppings[i].name << (i == toppings.size() - 1 ? "" : ", ");
        }
    }
    std::cout << ", Total Price: $" << calculatePrice() << std::endl;
}