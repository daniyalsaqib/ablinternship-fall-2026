#include <iostream>
#include <iomanip> // for formatting purposes setw() etc
using namespace std;

/*
BRAINSTORMING THREAD
under sir affan waheed
methods and attributes in OOP
for clear screen use system("cls")
getter and setters
*/

// we'll use Object Oriented Programming here 
// as because pre defined stuff is needed

class BankAccount {
private: // all attributes declared
string name; 
int accountnumber, balance; // i'm using balance as integer for simplifying purposes

public:
// CUSTOMERS DETAILS
int getBalance() {
return balance;
}
void Deposit() {
    
}

};

int main()
{
    int choice; // for menu based system input

    system("cls"); // for clearing the directory line

    do { // 25 to 30 == 26 perfect value
    cout << "============================== " << endl;
    cout << setw(26) << "ALLIED BANK - MAIN MENU" << endl;
    cout << "============================== " << endl;
    cout << "Currently selected account: [" << 01035513201 << " - " << "owner name" << "]" << endl;
    cout << endl; // VERTICAL SPACING AS per the requirements. 
    
    cout << "0. Clear Screen " << endl; // added feature for clearing output
    cout << "1. Select Account" << endl;
    cout << "2. Check Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl; 
    cout << "5. Exit" << endl; // system("cls")
    cout << "============================== " << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 0) {system("cls");}
    } while (choice != 5); // 5 enter krne pr exit hai
    return 0;
}