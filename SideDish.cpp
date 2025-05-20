#include "SideDish.h"

SideDish::SideDish(const std::string& n, double price, const std::string& portion)
    : MenuItem(n, price), portionSize(portion) {
    std::cout << "SideDish '" << name << "' created." << std::endl;
}

double SideDish::calculatePrice() const {
    double price = basePrice;
    if (portionSize == "Large") {
        price *= 1.5;
    }
    return price;
}

void SideDish::display() const {
    std::cout << "SideDish: " << name << ", Portion: " << portionSize
              << ", Price: $" << calculatePrice() << std::endl;
}