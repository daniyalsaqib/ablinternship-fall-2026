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
string name, accountnumber; 
int balance; // i'm using balance as integer for simplifying purposes

public: // account number for allied bank is 16 digits with first 3 digits is 001.
BankAccount(string n, string acc, int b = 0) { // default paratermized constructor
    name = n;
    accountnumber = acc;
    balance = b; // by default is 0 but with value can be changed.
}

int getBalance() { // current balance check
return balance;
}

// friend functions for displaying owner name and account number
friend string getAccountNumber(int choice);
friend string getOwnerName(int choice);

void Deposit(int value) { // Deposit Money
    try
    {
        if (value <= 0) {
         throw value;
        }
        else {
        balance = balance + value;
        cout << value << " PKR Deposited To Allied Bank. " << endl;
        cout << "Remaining Balance : " << getBalance() << endl;
        }
    }
    catch(...) // catches any type of error using ...
    {
        cout << "ERROR! Please Enter A Valid Amount To Deposit! " << endl;
    }
    
   
}
void Withdraw(int value) { // Withdraw money
    try {
        if (value <= 0) {
        throw value; 
       }
    else if (value > getBalance()) { // 1500 > 1000 error
        throw value;
        }
    else { // successful
    balance = balance - value;
    cout << value << " PKR Withdrawn from Allied Bank. " << endl;
    cout << "Remaining Balance : " << getBalance() << endl;
    }
    }
    catch(...) { // handles all type of exceptions
         cout << "ERROR! Please Enter A Valid Amount To Withdraw! " << endl;
    }
}
}; // BANKACCOUNT CLASS FINISHED

string getAccountNumber(int choice) {
    switch (choice) {
        case 1:
        return "0010000000000001";
        case 2:
        return "0010000000000002";
        case 3:
        return "0010000000000003";
        case 4:
        return "0010000000000004";
    }
}

int main()
{
    BankAccount Account[] = { BankAccount("DANIYAL SAQIB", "0010000000000001", 1000), BankAccount("ANAS SHOAIB", "0010000000000002", 2000), BankAccount("AREEB KHAN", "0010000000000003", 3000), BankAccount("ALIZAY EHSAN", "0010000000000004", 4000) }; 
    
    int choice; // for menu based system input
    int selectedAccount = -1; // what is the current selected account (-1 means no account selected)

    system("cls"); // for clearing the directory line

    do { // 25 to 30 == 26 perfect value
    cout << "============================== " << endl;
    cout << setw(26) << "ALLIED BANK - MAIN MENU" << endl;
    cout << "============================== " << endl;
    cout << "Currently selected account: [" << getAccountNumber(selectedAccount) << " - " << "owner name" << "]" << endl;
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

    switch (choice) {
        case 0:
        system("cls"); 
        break;
        case 1:
        cout << "WHICH ACCOUNT YOU WANT TO SELECT? " << endl;
        cout << " 1. 0010000000000001" << endl;
        cout << " 2. 0010000000000002" << endl;
        cout << " 3. 0010000000000003" << endl;
        cout << " 4. 0010000000000004" << endl;
        cin >> selectedAccount;
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
    }

    } while (choice != 5); // 5 enter krne pr exit hai
    return 0;
}