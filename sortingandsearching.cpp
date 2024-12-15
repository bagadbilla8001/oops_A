#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <iterator>
using namespace std;

// Define a struct for PersonalRecord to store Name, DOB, and Telephone number
struct PersonalRecord {
    string name;
    string dob;      // Date of Birth in format YYYY-MM-DD
    string phone;    // Telephone number

    // ructor to initialize the PersonalRecord
    PersonalRecord(string n, string d, string p) : name(n), dob(d), phone(p) {}

    // Display function to print the record
    void display()  {
        cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone << endl;
    }
};

// Comparison function to sort by Name (lexicographically)
bool compareByName(PersonalRecord &a,PersonalRecord &b) {
    return a.name < b.name;  // Sort in ascending order by Name
}

// Comparison function to sort by Phone number (lexicographically)
bool compareByPhone( PersonalRecord &a,  PersonalRecord &b) {
    return a.phone < b.phone;  // Sort in ascending order by Phone
}

// Function to print all records in the vector
void printRecords( vector<PersonalRecord>& records) {
    for ( auto& record : records) {
        record.display();
    }
}

int main() {
    // Create a vector to store personal records
    vector<PersonalRecord> records;

    // Insert some sample data
    records.push_back(PersonalRecord("Alice", "1990-05-14", "123-456-7890"));
    records.push_back(PersonalRecord("Bob", "1985-11-21", "234-567-8901"));
    records.push_back(PersonalRecord("Charlie", "1992-03-11", "345-678-9012"));
    records.push_back(PersonalRecord("Diana", "1988-07-19", "456-789-0123"));

    cout << "Original Records:" << endl;
    printRecords(records);
    
    // Sort records by Name
    sort(records.begin(), records.end(), compareByName);
    cout << "\nSorted Records by Name:" << endl;
    printRecords(records);

    // Sort records by Phone number
    sort(records.begin(), records.end(), compareByPhone);
    cout << "\nSorted Records by Phone Number:" << endl;
    printRecords(records);

    // // Searching for a specific record by name using find_if
    // string searchName = "Charlie";
    // auto it = find_if(records.begin(), records.end(), 
    //     [&searchName]( PersonalRecord& record) {
    //         return record.name == searchName;
    //     });

    auto it=records.begin();
    while(it->name!="Charlie"){
        if(it!=records.end()){
           cout<<"mil gya"<<endl;
        }
        it++;
    }
    // if (it != records.end()) {
    //     cout << "\nFound Record with Name " << searchName << ":" << endl;
    //     it->display();
    // } else {
    //     cout << "\nRecord with Name " << searchName << " not found." << endl;
    // }

    // Searching for a specific record by phone number using binary search
    // Make sure the vector is sorted by phone number before binary search
    sort(records.begin(), records.end(), compareByPhone);
    string searchPhone = "234-567-8901";
    // bool foundPhone = binary_search(records.begin(), records.end(), PersonalRecord("", "", searchPhone), 
    //     [](const PersonalRecord& a, const PersonalRecord& b) {
    //         return a.phone < b.phone;
    //     });
    bool foundPhone = binary_search(records.begin(), records.end(), PersonalRecord("", "", searchPhone), 
        [](const PersonalRecord& a,  PersonalRecord& b) {
            return a.phone < b.phone;
        });

    if (foundPhone) {
        cout << "\nFound Record with Phone Number " << searchPhone << "." << endl;
    } else {
        cout << "\nRecord with Phone Number " << searchPhone << " not found." << endl;
    }

    return 0;
}