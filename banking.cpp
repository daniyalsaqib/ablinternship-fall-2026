#include <iostream>
using namespace std;

/*
BRAINSTORMING THREAD
under sir affan waheed
methods and attributes in OOP
for clear screen use system("cls")
*/

// we'll use Object Oriented Programming here 
// as because pre defined stuff is needed

class BankAccount {
private: // all attributes declared
string name; 
int accountnumber, balance; // i'm using balance as integer for simplifying purposes

public:
// CUSTOMERS DETAILS
void details() {
cout << "ALLIED BANK CUSTOMER DETAILS " << endl;
cout << "Name : " << name << endl;
cout << "Account Number : " << accountnumber << endl;
cout << "Balance : " << balance << endl;
}

};

int main()
{
    int choice; // for menu based system input

    do {
    cout << "WELCOME TO ALLIED BANK! " << endl;
    cout << " WHAT WOULD YOU LIKE TO DO? " << endl;
    cout << " 0. EXIT" << endl;
    cout << " 1. Access Account 1" << endl;
    cout << " 2. Access Account 2" << endl;
    cout << " 3. Access Account 3" << endl;
    cout << " 4. Access Account 4" << endl; 
    cout << " 5. Clear Screen" << endl; // system("cls")
    cin >> choice;

    if (choice == 5) {system("cls");}
    } while (choice != 0);
    return 0;
}