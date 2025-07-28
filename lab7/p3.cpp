// Write a program with an abstract class Student and create derive classes Engineering,
// Medicine and Science from base class Student. Create the objects of the derived classes
// and process them and access them using an array of pointers of type base class Student.

#include <iostream>
using namespace std;

class Student
{
public:
    virtual void display() const = 0;
    virtual ~Student() {}
};

class Engineering : public Student
{
public:
    void display() const override { cout << "Engineering Student\n"; }
};

class Medicine : public Student
{
public:
    void display() const override { cout << "Medicine Student\n"; }
};

class Science : public Student
{
public:
    void display() const override { cout << "Science Student\n"; }
};

int main()
{
    Student *s[3];
    s[0] = new Engineering();
    s[1] = new Medicine();
    s[2] = new Science();
    for (int i = 0; i < 3; i++)
    {
        s[i]->display();
        delete s[i];
    }
}
