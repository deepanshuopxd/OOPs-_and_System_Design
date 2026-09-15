#include <iostream>
using namespace std;

/*
OPERATOR OVERLOADING
--------------------
Definition:
Giving special meaning to operators for user-defined types.

Syntax:
return_type operator symbol (parameters)

Example:
a + b → a.operator+(b)

Important:
- Cannot create new operators
- Cannot change precedence
*/

class Complex {
private:
    int real, imag;

public:

    // constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // display
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    // ================= ARITHMETIC =================

    // + operator
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // - operator
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // * operator
    Complex operator*(Complex c) {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // ================= RELATIONAL =================

    bool operator==(Complex c) {
        return (real == c.real && imag == c.imag);
    }

    bool operator!=(Complex c) {
        return !(*this == c);
    }

    // ================= ASSIGNMENT =================

    Complex& operator+=(Complex c) {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    // ================= INCREMENT =================

    // prefix ++
    Complex operator++() {
        real++;
        imag++;
        return *this;
    }

    // postfix ++
    Complex operator++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    // ================= STREAM OPERATORS =================

    // << operator (output)
    friend ostream& operator<<(ostream &out, Complex c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    // >> operator (input)
    friend istream& operator>>(istream &in, Complex &c) {
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {

    Complex c1(2, 3), c2(1, 4);

    // arithmetic
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;

    cout << "Addition: " << c3 << endl;
    cout << "Subtraction: " << c4 << endl;
    cout << "Multiplication: " << c5 << endl;

    // relational
    if (c1 == c2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    // assignment
    c1 += c2;
    cout << "After += : " << c1 << endl;

    // increment
    ++c1;
    cout << "After prefix ++ : " << c1 << endl;

    c1++;
    cout << "After postfix ++ : " << c1 << endl;

    // input
    Complex c6;
    cout << "Enter real and imaginary: ";
    cin >> c6;
    cout << "You entered: " << c6 << endl;

    return 0;
}