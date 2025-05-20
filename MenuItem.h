#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <iostream>

class MenuItem {
protected:
    std::string name;
    double basePrice;

public:
    MenuItem(const std::string& n = "Unknown Item", double price = 0.0);
    virtual ~MenuItem() = default;

    std::string getName() const;
    double getBasePrice() const;

    virtual double calculatePrice() const = 0;
    virtual void display() const = 0;
};

#endif // MENUITEM_H