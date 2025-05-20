#include "Pizzeria.h"
#include <iostream>
#include <limits>

Pizzeria::Pizzeria() : nextOrderId(1) {}

void Pizzeria::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void Pizzeria::placeOrder(const Customer& customer, const Order& order) {
    orders.push_back(order);
    for (auto& c : customers) {
        if (c.getName() == customer.getName()) {
            c.addOrder(order);
        }
    }
    nextOrderId++;
}

void Pizzeria::displayMenu() const {
    menu.displayMenu();
}

void Pizzeria::displayOrders() const {
    std::cout << "\nAll Orders:\n";
    for (const auto& order : orders) {
        order.display();
    }
}

const Menu& Pizzeria::getMenu() const {
    return menu;
}

void Pizzeria::createCustomerInteractively() {
    std::string name, contact;
    std::cout << "\nEnter customer name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Enter contact info (e.g., email or phone): ";
    std::getline(std::cin, contact);
    Customer customer(name, contact);
    addCustomer(customer);
    std::cout << "Customer '" << name << "' added.\n";
}

void Pizzeria::createOrderInteractively() {
    if (customers.empty()) {
        std::cout << "No customers available. Please add a customer first.\n";
        return;
    }

    std::cout << "\nAvailable customers:\n";
    for (size_t i = 0; i < customers.size(); ++i) {
        std::cout << i + 1 << ". " << customers[i].getName() << " (" << customers[i].getContactInfo() << ")\n";
    }
    std::cout << "Select customer by number: ";
    int customerIndex;
    std::cin >> customerIndex;
    if (customerIndex < 1 || customerIndex > static_cast<int>(customers.size())) {
        std::cout << "Invalid customer selection.\n";
        return;
    }
    Customer& selectedCustomer = customers[customerIndex - 1];

    std::cout << "\nSelect order type:\n1. Dine-in\n2. Takeout\n3. Delivery\n";
    int orderTypeChoice;
    std::cin >> orderTypeChoice;
    OrderType orderType;
    switch (orderTypeChoice) {
        case 1: orderType = OrderType::DINE_IN; break;
        case 2: orderType = OrderType::TAKEOUT; break;
        case 3: orderType = OrderType::DELIVERY; break;
        default: std::cout << "Invalid order type.\n"; return;
    }

    Order order(nextOrderId, orderType);


    while (true) {
        std::cout << "\nAdd a pizza? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;

        std::cout << "\nAvailable pizzas:\n";
        const auto& pizzas = menu.getAvailablePizzas();
        for (size_t i = 0; i < pizzas.size(); ++i) {
            std::cout << i + 1 << ". ";
            pizzas[i].display();
        }
        std::cout << "Select pizza by number: ";
        int pizzaIndex;
        std::cin >> pizzaIndex;
        if (pizzaIndex < 1 || pizzaIndex > static_cast<int>(pizzas.size())) {
            std::cout << "Invalid pizza selection.\n";
            continue;
        }


        Pizza pizza = pizzas[pizzaIndex - 1];
        std::cout << "\nSelect size:\n1. Small\n2. Medium\n3. Large\n";
        int sizeChoice;
        std::cin >> sizeChoice;
        switch (sizeChoice) {
            case 1: pizza.setSize(Size::SMALL); break;
            case 2: pizza.setSize(Size::MEDIUM); break;
            case 3: pizza.setSize(Size::LARGE); break;
            default: std::cout << "Invalid size, using Medium.\n"; break;
        }

        std::cout << "\nSelect base type:\n1. Thin\n2. Traditional\n3. Thick\n";
        int baseChoice;
        std::cin >> baseChoice;
        switch (baseChoice) {
            case 1: pizza.setBaseType(BaseType::THIN); break;
            case 2: pizza.setBaseType(BaseType::TRADITIONAL); break;
            case 3: pizza.setBaseType(BaseType::THICK); break;
            default: std::cout << "Invalid base type, using Traditional.\n"; break;
        }


        while (true) {
            std::cout << "\nAdd a topping? (y/n): ";
            std::cin >> choice;
            if (choice != 'y' && choice != 'Y') break;

            std::cout << "\nAvailable toppings:\n";
            const auto& toppings = menu.getAvailableToppings();
            for (size_t i = 0; i < toppings.size(); ++i) {
                std::cout << i + 1 << ". " << toppings[i].name << " ($" << toppings[i].price << ")\n";
            }
            std::cout << "Select topping by number: ";
            int toppingIndex;
            std::cin >> toppingIndex;
            if (toppingIndex < 1 || toppingIndex > static_cast<int>(toppings.size())) {
                std::cout << "Invalid topping selection.\n";
                continue;
            }
            pizza.addTopping(toppings[toppingIndex - 1]);
        }

        order.addPizza(pizza);
    }

    while (true) {
        std::cout << "\nAdd a drink? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;

        std::cout << "\nAvailable drinks:\n";
        const auto& drinks = menu.getAvailableDrinks();
        for (size_t i = 0; i < drinks.size(); ++i) {
            std::cout << i + 1 << ". ";
            drinks[i].display();
        }
        std::cout << "Select drink by number: ";
        int drinkIndex;
        std::cin >> drinkIndex;
        if (drinkIndex < 1 || drinkIndex > static_cast<int>(drinks.size())) {
            std::cout << "Invalid drink selection.\n";
            continue;
        }
        order.addDrink(drinks[drinkIndex - 1]);
    }


    while (true) {
        std::cout << "\nAdd a side dish? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;

        std::cout << "\nAvailable side dishes:\n";
        const auto& sideDishes = menu.getAvailableSideDishes();
        for (size_t i = 0; i < sideDishes.size(); ++i) {
            std::cout << i + 1 << ". ";
            sideDishes[i].display();
        }
        std::cout << "Select side dish by number: ";
        int sideDishIndex;
        std::cin >> sideDishIndex;
        if (sideDishIndex < 1 || sideDishIndex > static_cast<int>(sideDishes.size())) {
            std::cout << "Invalid side dish selection.\n";
            continue;
        }
        order.addSideDish(sideDishes[sideDishIndex - 1]);
    }

    placeOrder(selectedCustomer, order);
    std::cout << "\nOrder placed successfully!\n";
    order.display();
}