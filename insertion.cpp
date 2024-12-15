#include <iostream>
using namespace std;

// Template class for sorting an array
template <typename T>
class SortableArray {
private:
    T* arr;  // Pointer to dynamically allocated array
    int size;  // Size of the array

public:
    // Constructor to initialize the array
    SortableArray(T arr[], int size) {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; ++i) {
            this->arr[i] = arr[i];  // Copy the elements into the new array
        }
    }

    // Destructor to deallocate memory
    ~SortableArray() {
        delete[] arr;
    }

    // Method to perform insertion sort
    void insertionSort() {
        for (int i = 1; i < size; ++i) {
            T key = arr[i];
            int j = i - 1;

            // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }

            // Insert the key at the correct position
            arr[j + 1] = key;
        }
    }

    // Method to print the array
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int intSize, floatSize;

    // Ask user for the size and elements of the integer array
    cout << "Enter the number of elements in the integer array: ";
    cin >> intSize;
    int* intArr = new int[intSize];
    cout << "Enter " << intSize << " integer values:\n";
    for (int i = 0; i < intSize; ++i) {
        cin >> intArr[i];
    }

    // Create SortableArray object for integers
    SortableArray<int> intArray(intArr, intSize);
    cout << "Original Integer Array: ";
    intArray.printArray();

    // Sort and display the integer array
    intArray.insertionSort();
    cout << "Sorted Integer Array: ";
    intArray.printArray();

    delete[] intArr;  // Clean up dynamically allocated array

    // Ask user for the size and elements of the float array
    cout << "Enter the number of elements in the float array: ";
    cin >> floatSize;
    float* floatArr = new float[floatSize];
    cout << "Enter " << floatSize << " float values:\n";
    for (int i = 0; i < floatSize; ++i) {
        cin >> floatArr[i];
    }

    // Create SortableArray object for floats
    SortableArray<float> floatArray(floatArr, floatSize);
    cout << "Original Float Array: ";
    floatArray.printArray();

    // Sort and display the float array
    floatArray.insertionSort();
    cout << "Sorted Float Array: ";
    floatArray.printArray();

    delete[] floatArr;  // Clean up dynamically allocated array

    return 0;
}
