#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

// Define a structure for Item records
struct Item {
    int code;       // Item code
    string name;    // Item name
    double cost;    // Cost of the item
    int quantity;   // Quantity of the item in stock

    // Constructor to initialize the Item record
    Item(int c, string n, double co, int q) : code(c), name(n), cost(co), quantity(q) {}

    // Function to display item details
    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", Cost: $" << cost << ", Quantity: " << quantity << endl;
    }
};

// Comparison function to sort by Item code
bool compareByCode(const Item &a, const Item &b) {
    return a.code < b.code;
}

// Comparison function to sort by Cost (in ascending order)
bool compareByCost(const Item &a, const Item &b) {
    return a.cost < b.cost;
}

// Comparison function to sort by Name (lexicographically)
bool compareByName(const Item &a, const Item &b) {
    return a.name < b.name;
}

// Function to print all items in the vector
void printItems(const vector<Item>& items) {
    for (const auto& item : items) {
        item.display();
    }
}

int main() {
    // Create a vector to store Item records
    vector<Item> items;

    // Insert some sample data into the vector
    items.push_back(Item(101, "Apple", 0.99, 50));
    items.push_back(Item(102, "Banana", 0.59, 30));
    items.push_back(Item(103, "Orange", 1.29, 20));
    items.push_back(Item(104, "Milk", 2.49, 15));
    items.push_back(Item(105, "Bread", 1.99, 40));

    cout << "Original Item Records:" << endl;
    printItems(items);
    
    // Sort records by Item code
    sort(items.begin(), items.end(), compareByCode);
    cout << "\nSorted Item Records by Code:" << endl;
    printItems(items);

    // Sort records by Cost
    sort(items.begin(), items.end(), compareByCost);
    cout << "\nSorted Item Records by Cost:" << endl;
    printItems(items);

    // Sort records by Name
    sort(items.begin(), items.end(), compareByName);
    cout << "\nSorted Item Records by Name:" << endl;
    printItems(items);

    // Searching for an Item by Code using find_if
    int searchCode = 103;
    auto it = find_if(items.begin(), items.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (it != items.end()) {
        cout << "\nFound Item with Code " << searchCode << ":" << endl;
        it->display();
    } else {
        cout << "\nItem with Code " << searchCode << " not found." << endl;
    }

    // Searching for an Item by Name using find_if
    string searchName = "Milk";
    it = find_if(items.begin(), items.end(), [searchName](const Item& item) {
        return item.name == searchName;
    });

    if (it != items.end()) {
        cout << "\nFound Item with Name " << searchName << ":" << endl;
        it->display();
    } else {
        cout << "\nItem with Name " << searchName << " not found." << endl;
    }

    // Searching for an Item by Cost using binary search (need to sort by cost first)
    sort(items.begin(), items.end(), compareByCost);  // Ensure the vector is sorted by cost
    double searchCost = 1.29;
    bool foundCost = binary_search(items.begin(), items.end(), Item(0, "", searchCost, 0), 
        [](const Item& a, const Item& b) {
            return a.cost < b.cost;
        });

    if (foundCost) {
        cout << "\nFound Item with Cost $" << searchCost << "." << endl;
    } else {
        cout << "\nItem with Cost $" << searchCost << " not found." << endl;
    }

    return 0;
}