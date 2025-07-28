// Write a program to overload stream operators to read a complex number
// and display the complex number in a+ib format.

#include <iostream>
using namespace std;

class Complex
{
    double real, imag;

public:
    Complex() : real(0), imag(0) {}
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter real and imaginary parts: ";
        in >> c.real >> c.imag;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        return out << c.real << "+" << c.imag << "i";
    }
};

int main()
{
    Complex c;
    cin >> c;
    cout << "Complex number: " << c;
}
