#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Class representing an item on the menu
class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(const string& itemName, double itemPrice) : name(itemName), price(itemPrice) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

// Class representing a bill
class Bill {
private:
    vector<MenuItem> items;
    double total;

public:
    Bill() : total(0.0) {}

    void addItem(const MenuItem& item) {
        items.push_back(item);
        total += item.getPrice();
    }

    void printBill() const {
        cout << "------ Bill ------" << endl;
        for (const MenuItem& item : items) {
            cout << setw(20) << left << item.getName();
            cout << setw(10) << right << fixed << setprecision(2) << item.getPrice() << endl;
        }
        cout << "------------------" << endl;
        cout << "Total: " << total << endl;
    }
};

// Function to display the menu options
void displayMenu() {
    cout << "1. Add item to bill" << endl;
    cout << "2. Print bill" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<MenuItem> menu;
    menu.push_back(MenuItem("Burger", 5.99));
    menu.push_back(MenuItem("Pizza", 9.99));
    menu.push_back(MenuItem("Salad", 4.99));
    // Add more menu items here...

    Bill bill;

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                int itemIndex;
                cout << "Enter the index of the item: ";
                cin >> itemIndex;

                if (itemIndex >= 0 && itemIndex < menu.size()) {
                    bill.addItem(menu[itemIndex]);
                    cout << "Item added to the bill." << endl;
                } else {
                    cout << "Invalid item index." << endl;
                }
                break;

            case 2:
                bill.printBill();
                break;

            case 3:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}
