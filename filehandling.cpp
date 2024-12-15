#include <iostream>
#include <fstream>  // For file stream operations
#include <string>
using namespace std;

class FileHandler {
private:
    ofstream outFile;  // Output file stream
    ifstream inFile;   // Input file stream

public:
    // Constructor to open the output file
    FileHandler(const string& fileName) {
        // Open the file for writing
        outFile.open(fileName, ios::out);
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            exit(1);  // Exit if file couldn't be opened
        }
    }

    // Method to write data to the file
    void writeToFile(const string& data) {
        if (outFile) {
            outFile << data << endl;
        } else {
            cerr << "File is not open for writing!" << endl;
        }
    }

    // Method to close the output file
    void closeWrite() {
        if (outFile) {
            outFile.close();
            cout << "Output file closed successfully!" << endl;
        }
    }

    // Method to open the input file
    void openForReading(const string& fileName) {
        inFile.open(fileName, ios::in);
        if (!inFile) {
            cerr << "Error opening file for reading!" << endl;
            exit(1);  // Exit if file couldn't be opened
        }
    }

    // Method to read and display data from the file
    void readFromFile() {
        string line;
        cout << "\nReading the file content:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }

    // Method to close the input file
    void closeRead() {
        if (inFile) {
            inFile.close();
            cout << "\nInput file closed successfully!" << endl;
        }
    }

    // Destructor (to ensure proper file closure when the object goes out of scope)
    ~FileHandler() {
        if (outFile.is_open()) {
            outFile.close();
        }
        if (inFile.is_open()) {
            inFile.close();
        }
    }
};

int main() {
    // Create FileHandler object for output file operations
    FileHandler fileHandler("example.txt");

    // Write some information to the file
    fileHandler.writeToFile("Hello, this is a test file.");
    fileHandler.writeToFile("C++ file handling is fun!");
    fileHandler.writeToFile("This file contains multiple lines of text.");

    // Close the output file after writing
    fileHandler.closeWrite();
    cout << "Information written to the file successfully!" << endl;

    // Create another FileHandler object for input file operations
    FileHandler inputFileHandler("");  // Empty name for input, since we handle it differently
    inputFileHandler.openForReading("example.txt");

    // Read and display the content of the file
    inputFileHandler.readFromFile();

    // Close the input file after reading
    inputFileHandler.closeRead();
    cout << "\nFile read successfully!" << endl;

    return 0;
}