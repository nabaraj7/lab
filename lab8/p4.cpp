// Write a program that stores the information about students
// (name, student id, department, and address) in a structure and
// then transfers the information to a file in your directory.
// Finally, retrieve the information from your file and print it in the proper format on your output screen.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    char name[30], department[20], address[50];
    int id;
};

class StudentFile
{
    string filename;

public:
    StudentFile(const string &f) : filename(f) {}
    void writeRecords()
    {
        ofstream fout(filename, ios::binary);
        int n;
        cout << "How many students? ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            Student s;
            cout << "Name: ";
            cin.getline(s.name, 30);
            cout << "ID: ";
            cin >> s.id;
            cin.ignore();
            cout << "Department: ";
            cin.getline(s.department, 20);
            cout << "Address: ";
            cin.getline(s.address, 50);
            fout.write((char *)&s, sizeof(s));
        }
    }
    void readRecords()
    {
        ifstream fin(filename, ios::binary);
        Student s;
        cout << "\nRecords:\n";
        while (fin.read((char *)&s, sizeof(s)))
        {
            cout << s.name << " " << s.id << " " << s.department << " " << s.address << "\n";
        }
    }
};

int main()
{
    StudentFile sf("students.dat");
    sf.writeRecords();
    sf.readRecords();
}
