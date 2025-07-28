// Write a program for transaction processing that write and read object
// randomly to and from a random access file so that user can add, update,
// delete and display the account information (account-number, last-name, first-name, total-balance).

#include <iostream>
#include <fstream>
using namespace std;

struct Account
{
    int accNo;
    char first[20], last[20];
    double balance;
};

class Bank
{
    fstream file;
    const char *fname = "accounts.dat";

public:
    Bank()
    {
        file.open(fname, ios::in | ios::out | ios::binary);
        if (!file)
        {
            ofstream fout(fname, ios::binary);
            Account blank = {0, "", "", 0};
            for (int i = 0; i < 100; i++)
                fout.write((char *)&blank, sizeof(blank));
            fout.close();
            file.open(fname, ios::in | ios::out | ios::binary);
        }
    }
    void add()
    {
        Account acc;
        cout << "AccNo First Last Balance: ";
        cin >> acc.accNo >> acc.first >> acc.last >> acc.balance;
        file.seekp((acc.accNo - 1) * sizeof(Account));
        file.write((char *)&acc, sizeof(acc));
    }
    void display()
    {
        file.seekg(0);
        Account acc;
        while (file.read((char *)&acc, sizeof(acc)))
            if (acc.accNo != 0)
                cout << acc.accNo << " " << acc.first << " " << acc.last << " " << acc.balance << "\n";
    }
};

int main()
{
    Bank b;
    int ch;
    do
    {
        cout << "\n1.Add 2.Display 3.Exit: ";
        cin >> ch;
        if (ch == 1)
            b.add();
        else if (ch == 2)
            b.display();
    } while (ch != 3);
}
