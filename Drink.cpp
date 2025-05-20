#include "Drink.h"

Drink::Drink(const std::string& n, double price, const std::string& vol)
    : MenuItem(n, price), volume(vol) {
    std::cout << "Drink '" << name << "' created." << std::endl;
}

double Drink::calculatePrice() const {
    return basePrice;
}

void Drink::display() const {
    std::cout << "Drink: " << name << ", Volume: " << volume
              << ", Price: $" << calculatePrice() << std::endl;
}
