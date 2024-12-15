#include <iostream>
#include <string>
#include <stdexcept>  // For exception handling
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;  // Date of birth as string (can be refined further)
    string bloodGroup;
    string address;
    string telephone;
    string drivingLicenseNo;
    string otherInfo;

public:
    // Default constructor
    Student() : name(""), rollNumber(0), studentClass(""), division(' '), dob(""), bloodGroup(""),
               address(""), telephone(""), drivingLicenseNo(""), otherInfo("") {}

    // Parameterized constructor
    Student(string n, int r, string c, char d, string b, string bg, string addr, string tel, string dl, string other)
        : name(n), rollNumber(r), studentClass(c), division(d), dob(b), bloodGroup(bg), address(addr), telephone(tel),
          drivingLicenseNo(dl), otherInfo(other) {}

    // Copy constructor
    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        studentClass = s.studentClass;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        telephone = s.telephone;
        drivingLicenseNo = s.drivingLicenseNo;
        otherInfo = s.otherInfo;
    }

    // Destructor
    ~Student() {
        cout << "Destroying student: " << name << endl;
    }

    // Static member variable to keep track of number of students
    static int studentCount;

    // Static member function to get the number of students
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function to display student details
    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
        cout << "Other Info: " << otherInfo << endl;
    }

    // Friend class to allow another class to access private members
    friend class StudentDatabase;
};

// Initialize static member variable
int Student::studentCount = 0;

// StudentDatabase class
class StudentDatabase {
private:
    vector<Student*> students; // Dynamic array of Student pointers

public:
    // Add a student to the database
    void addStudent(const Student& s) {
        Student* newStudent = new Student(s);
        students.push_back(newStudent);
        Student::studentCount++; // Increment static member
    }

    // Display all students in the database
    void displayAllStudents() {
        for (auto& student : students) {
            student->display();
            cout << endl;
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~StudentDatabase() {
        for (auto& student : students) {
            delete student; // Free dynamically allocated memory
        }
        students.clear();
    }

    // Function to search and display a student by roll number
    void searchByRollNumber(int rollNumber) {
        bool found = false;
        for (auto& student : students) {
            if (student->rollNumber == rollNumber) {
                student->display();
                found = true;
                break;
            }
        }
        if (!found) {
            throw runtime_error("Student with the given roll number not found!");
        }
    }
};

// Main function
int main() {
    StudentDatabase db;
    
    // Try-catch block for exception handling
    try {
        // Create some students and add them to the database
        db.addStudent(Student("John Doe", 1, "12A", 'A', "01/01/2000", "O+", "123 Street, City", "1234567890", "DL123456", "N/A"));
        db.addStudent(Student("Jane Smith", 2, "12B", 'B', "02/02/2001", "A-", "456 Avenue, City", "0987654321", "DL987654", "N/A"));

        // Display all students
        cout << "All Students in the Database: " << endl;
        db.displayAllStudents();

        // Search for a student by roll number
        cout << "Searching for student with roll number 1:" << endl;
        db.searchByRollNumber(1);

        // Display student count using static member function
        cout << "Total Students in Database: " << Student::getStudentCount() << endl;
        
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}