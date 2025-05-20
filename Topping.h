#ifndef TOPPING_H
#define TOPPING_H

#include <string>

struct Topping {
    std::string name;
    double price;

    Topping(const std::string& n, double p) : name(n), price(p) {}
};

#endif // TOPPING_H