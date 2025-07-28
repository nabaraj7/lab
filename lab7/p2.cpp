// Create a class Person and two derived classes Employee and Student, inherited from class Person.
// Now create a class Manager which is derived from two base classes Employee and Student.
// Show the use of the virtual base class.

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n = "") : name(n) {}
    void show() { cout << "Name: " << name << "\n"; }
};

class Employee : virtual public Person
{
protected:
    int empId;

public:
    Employee(string n, int id) : Person(n), empId(id) {}
};

class Student : virtual public Person
{
protected:
    int roll;

public:
    Student(string n, int r) : Person(n), roll(r) {}
};

class Manager : public Employee, public Student
{
    string dept;

public:
    Manager(string n, int id, int r, string d)
        : Person(n), Employee(n, id), Student(n, r), dept(d) {}
    void showManager()
    {
        cout << "Manager Details\n";
        show();
        cout << "EmpID: " << empId << "\nRoll: " << roll << "\nDept: " << dept << "\n";
    }
};

int main()
{
    Manager m("Alice", 101, 5, "HR");
    m.showManager();
}
