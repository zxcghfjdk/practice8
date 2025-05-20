#ifndef PIZZA_H
#define PIZZA_H

#include "MenuItem.h"
#include "Topping.h"
#include <vector>

enum class Size { SMALL, MEDIUM, LARGE };
enum class BaseType { THIN, TRADITIONAL, THICK };

class Pizza : public MenuItem {
private:
    Size size;
    BaseType baseType;
    std::vector<Topping> toppings;

public:
    Pizza(const std::string& n, double price, Size s = Size::MEDIUM, BaseType bt = BaseType::TRADITIONAL);
    void addTopping(const Topping& t);
    double calculatePrice() const override;
    void display() const override;

    void setSize(Size s);
    void setBaseType(BaseType bt);
};

#endif // PIZZA_H