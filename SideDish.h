#ifndef SIDEDISH_H
#define SIDEDISH_H

#include "MenuItem.h"

class SideDish : public MenuItem {
private:
    std::string portionSize;

public:
    SideDish(const std::string& n, double price, const std::string& portion);
    double calculatePrice() const override;
    void display() const override;
};

#endif // SIDEDISH_H
