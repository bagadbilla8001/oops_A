#include <iostream>
using namespace std;

class Complex {
private:
    // these are variables
    double real;
    double imag;

public:
    // Default constructor (initializes to 0 + 0i)
    // Complex() : real(0), imag(0) {}

    // Parameterized constructor (to create a complex number a + bi)
    Complex(double r=0, double i=0){
        real=r;
        imag=i;
        }

    // Getter functions for real and imaginary parts
    double getReal() const { 
        return real;
        }
    double getImag() const { 
        return imag;
        }

    // Operator overloading for +
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Operator overloading for *
    Complex operator*(const Complex& obj) {
        double r = real * obj.real - imag * obj.imag;  // Real part
        double i = real * obj.imag + imag * obj.real;  // Imaginary part
        return Complex(r, i);
    }

    // Operator overloading for <<
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }

    // Operator overloading for >>
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

// Main function to test the Complex class
int main() {
    Complex c1(3, 4), c2(1, 2), result;
    
    // Test addition
    result = c1 + c2;
    cout << "c1 + c2 = " << result << endl;
    
    // Test multiplication
    result = c1 * c2;
    cout << "c1 * c2 = " << result << endl;
    
    // Test input and output
    Complex c3;
    cout << "Enter a complex number (real imag): ";
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}