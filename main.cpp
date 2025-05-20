#include "Pizzeria.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Pizzeria pizzeria;
    int choice;

    while (true) {
        std::cout << "\n=== Pizzeria Simulator ===\n";
        std::cout << "1. View Menu\n";
        std::cout << "2. Place Order\n";
        std::cout << "3. Add Customer\n";
        std::cout << "4. View Orders\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                pizzeria.displayMenu();
                break;
            case 2:
                pizzeria.createOrderInteractively();
                break;
            case 3:
                pizzeria.createCustomerInteractively();
                break;
            case 4:
                pizzeria.displayOrders();
                break;
            case 5:
                std::cout << "Thank you for using Pizzeria Simulator!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}