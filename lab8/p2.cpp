// Write a program to create a user-defined manipulator that will format
// the output by setting the width, precision, and fill character at the same time by passing arguments.

#include <iostream>
#include <iomanip>
using namespace std;

class Formatter
{
    int w, p;
    char f;

public:
    Formatter(int width, int prec, char fill) : w(width), p(prec), f(fill) {}
    friend ostream &operator<<(ostream &os, const Formatter &fm)
    {
        return os << setw(fm.w) << setprecision(fm.p)
                  << setfill(fm.f) << fixed;
    }
};

int main()
{
    double num = 123.45678;
    cout << Formatter(10, 3, '*') << num;
}
