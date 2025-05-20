#include "MenuItem.h"

MenuItem::MenuItem(const std::string& n, double price) : name(n), basePrice(price) {
    std::cout << "MenuItem '" << name << "' created." << std::endl;
}

std::string MenuItem::getName() const {
    return name;
}

double MenuItem::getBasePrice() const {
    return basePrice;
}