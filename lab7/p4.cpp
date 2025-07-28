// Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle.
// Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
public:
    virtual void info() const { cout << "Generic Vehicle\n"; }
    virtual ~Vehicle() {}
};

class Bus : public Vehicle
{
public:
    void info() const override { cout << "Bus\n"; }
};

class Car : public Vehicle
{
public:
    void info() const override { cout << "Car\n"; }
};

class Bike : public Vehicle
{
public:
    void info() const override { cout << "Bike\n"; }
};

int main()
{
    Vehicle *v[] = {new Bus(), new Car(), new Bike()};

    for (auto p : v)
    {
        cout << "Type: " << typeid(*p).name() << "\n";
        p->info();

        if (Bus *b = dynamic_cast<Bus *>(p))
            cout << "Dynamic cast says this is a Bus\n";
        else if (Car *c = dynamic_cast<Car *>(p))
            cout << "Dynamic cast says this is a Car\n";
        else if (Bike *bk = dynamic_cast<Bike *>(p))
            cout << "Dynamic cast says this is a Bike\n";
        cout << "---\n";
    }

    for (auto p : v)
        delete p;
}
