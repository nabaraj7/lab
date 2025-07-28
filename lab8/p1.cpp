// Write a program to demonstrate the use of different ios flags and functions to format the output.
// Create a program to generate the bill invoice of a department store by using different formatting.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item
{
    string name;
    int qty;
    double price;

public:
    Item(string n, int q, double p) : name(n), qty(q), price(p) {}
    double amount() const { return qty * price; }
    void display() const
    {
        cout << left << setw(15) << name
             << right << setw(10) << qty
             << setw(15) << fixed << setprecision(2) << price
             << setw(15) << amount() << '\n';
    }
};

int main()
{
    Item items[] = {{"Notebook", 2, 120.5}, {"Pen", 5, 20.75}, {"Pencil", 10, 10}};
    double total = 0;

    cout << left << setw(15) << "Item"
         << right << setw(10) << "Qty"
         << setw(15) << "Price"
         << setw(15) << "Amount\n"
         << setfill('-') << setw(55) << "-" << '\n'
         << setfill(' ');

    for (auto &it : items)
    {
        it.display();
        total += it.amount();
    }

    cout << setfill('-') << setw(55) << "-" << '\n'
         << setfill(' ')
         << right << setw(40) << "Total: "
         << setw(15) << fixed << setprecision(2) << total;
}
