#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//include statements are a pain, good thing we3 schools exists to just give me all the includes

struct item {
    std::string name;
    double price;
};

struct cart_item {
    item item;
    int quantity;
};
//sort out variables for discounts for later
const double discount_threshold = 200.0;
const double discount_rate = 0.05;

//create a for loop of a function so that you can add items to your basket, then add more to the item in the basket
void display_menu(const std::vector<item>& items) {
    std::cout << "Available items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i].name << " - R" << items[i].price << '\n';
    }
}
//codecademy cheatsheet for all things vector related
int main() {
    std::vector<item> items = {
        {"Potato", 45.00}, {"Avocado", 70.00}, {"Egg", 120.00}, {"Onion", 25.00},{"Apples", 25.00},{"Oranges", 45.00}
    };

    std::vector<cart_item> cart;
    std::string customer_name;
    char add_more_items;

    //Customer inputs
    std::cout << "Enter your name: ";
    std::getline(std::cin, customer_name);
    //menu loop
    do {
        display_menu(items);

        int item_choice, quantity;
        std::cout << "Select an item number to add to cart: ";
        std::cin >> item_choice;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        if (item_choice > 0 && item_choice <= items.size() && quantity > 0) {
            cart.push_back({items[item_choice - 1], quantity});
        } else {
            std::cout << "Invalid choice or quantity. Please try again.\n";
        }

        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> add_more_items;
    } while (add_more_items == 'y' || add_more_items == 'Y');

    double total_cost = 0.0;
    for (const auto& cart_item : cart) {
        total_cost += cart_item.item.price * cart_item.quantity;
    }

    double discount = 0.0;
    if (total_cost > discount_threshold) {
        discount = total_cost * discount_rate;
        total_cost -= discount;
    }

//write to a file (Thanks to we3 schools)
    std::ofstream bill_file("bill.txt");
    bill_file << "Customer Name: " << customer_name << "\n";
    bill_file << "Items Purchased:\n";
    for (const auto& cart_item : cart) {
        bill_file << cart_item.item.name << " - Quantity: " << cart_item.quantity 
                  << " - Subtotal: R" << cart_item.item.price * cart_item.quantity << "\n";
    }
    bill_file << "Total Discount: R" << discount << "\n";
    bill_file << "Total Cost: R" << total_cost << "\n";
    bill_file.close();

    std::cout << "\nCustomer Name: " << customer_name << "\n";
    std::cout << "Items Purchased:\n";
    for (const auto& cart_item : cart) {
        std::cout << cart_item.item.name << " - Quantity: " << cart_item.quantity 
                  << " - Subtotal: R" << cart_item.item.price * cart_item.quantity << "\n";
    }
    //Final print statements
    std::cout << "Total Discount: R" << discount << "\n";
    std::cout << "Total Cost: R" << total_cost << "\n";

    return 0;
}

