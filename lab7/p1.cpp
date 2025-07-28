// Write a program to create a class shape with functions to find
// the area of the shapes and display the names of the shapes and other essential components of the class.
// Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display().
// Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() { cout << "Shape destroyed\n"; }
};

class Circle : public Shape
{
    double r;

public:
    Circle(double rad) : r(rad) {}
    void display() const override { cout << "Circle\n"; }
    double area() const override { return 3.14159 * r * r; }
    ~Circle() { cout << "Circle destroyed\n"; }
};

class Rectangle : public Shape
{
    double l, w;

public:
    Rectangle(double a, double b) : l(a), w(b) {}
    void display() const override { cout << "Rectangle\n"; }
    double area() const override { return l * w; }
    ~Rectangle() { cout << "Rectangle destroyed\n"; }
};

class Trapezoid : public Shape
{
    double a, b, h;

public:
    Trapezoid(double x, double y, double z) : a(x), b(y), h(z) {}
    void display() const override { cout << "Trapezoid\n"; }
    double area() const override { return (a + b) * h / 2; }
    ~Trapezoid() { cout << "Trapezoid destroyed\n"; }
};

int main()
{
    Shape *s[] = {new Circle(5), new Rectangle(4, 6), new Trapezoid(3, 5, 4)};
    for (auto p : s)
    {
        p->display();
        cout << "Area: " << p->area() << "\n";
        delete p;
    }
}
