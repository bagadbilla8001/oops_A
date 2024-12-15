#include <iostream>
#include <string>
#include <stdexcept>  // For exception handling
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title(""), price(0.0f) {}

    // Parameterized constructor
    Publication(string t, float p) : title(t), price(p) {}

    // Display function for Publication
    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : pageCount(0) {}

    // Parameterized constructor
    Book(string t, float p, int pages) : Publication(t, p), pageCount(pages) {}

    // Function to display the Book information
    void display() const override {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }

    // Function to read book data
    void readData() {
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Price: ";
        cin >> price;
        if (cin.fail()) {
            throw invalid_argument("Invalid price input.");
        }
        cout << "Enter Page Count: ";
        cin >> pageCount;
        if (cin.fail()) {
            throw invalid_argument("Invalid page count input.");
        }
        cin.ignore(); // To clear the input buffer
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playTime;  // in minutes

public:
    // Default constructor
    Tape() : playTime(0.0f) {}

    // Parameterized constructor
    Tape(string t, float p, float time) : Publication(t, p), playTime(time) {}

    // Function to display the Tape information
    void display() const override {
        Publication::display();
        cout << "Play Time (in minutes): " << playTime << endl;
    }

    // Function to read tape data
    void readData() {
        cout << "Enter Tape Title: ";
        getline(cin, title);
        cout << "Enter Tape Price: ";
        cin >> price;
        if (cin.fail()) {
            throw invalid_argument("Invalid price input.");
        }
        cout << "Enter Play Time (in minutes): ";
        cin >> playTime;
        if (cin.fail()) {
            throw invalid_argument("Invalid play time input.");
        }
        cin.ignore(); // To clear the input buffer
    }
};

int main() {
    try {
        // Create objects for Book and Tape
        Book book;
        Tape tape;

        // Input data for Book
        book.readData();

        // Input data for Tape
        tape.readData();

        // Display data for Book and Tape
        cout << "\nBook Details:" << endl;
        book.display();
        cout << "\nTape Details:" << endl;
        tape.display();
    }
    catch (const exception& e) {
        // Catch any exception and reset all values to zero
        cout << "Error: " << e.what() << endl;
        cout << "Resetting all data to zero values." << endl;

        // Create empty objects with zero values
        Book book;
        Tape tape;

        // Display reset data
        cout << "\nBook Details (Reset to Zero):" << endl;
        book.display();
        cout << "\nTape Details (Reset to Zero):" << endl;
        tape.display();
    }

    return 0;
}