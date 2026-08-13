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
friend string getAccountNumber(BankAccount a[], int choice);
friend string getOwnerName(BankAccount a[], int choice);

void Deposit(int value) { // Deposit Money
    try
    {
        if (value <= 0) {
         throw value;
        }
        balance = balance + value;
        cout << value << " PKR Deposited To Allied Bank. " << endl;
        cout << "Remaining Balance : " << getBalance() << endl;
    }
    catch(...) // catches any type of error using ...
    {
        cout << "ERROR! Something went wrong! " << endl;
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
          if (value <= 0) {
            cout << "Withdrawal Failed: Withdrawal amount cannot be in -ve" << endl; 
          }
          else { // 1500 > 1000 error
            cout << "Withdrawal Failed: Amount Exceeds Available Balance" << endl;
          }
    }
}
}; // BANKACCOUNT CLASS FINISHED

// friend functions
string getAccountNumber(BankAccount a[], int choice) {
    if (choice == -1) // none selected
    {
        return "N/A";
    }
    return a[choice].accountnumber;
}

string getOwnerName(BankAccount a[], int choice) {
    if (choice == -1) // none selected
    {
        return "N/A";
    }
    return a[choice].name;
}


// Source - https://stackoverflow.com/a/4654718
// Posted by Charles Salvia, modified by community. See post 'Timeline' for change history
// Retrieved 2026-08-13, License - CC BY-SA 4.0

bool is_number(const std::string& s)
{
    if (s.empty()){
        return false;
    }
    for(int i=0;i<s.length();i++)
    {
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}


int main()
{   
    BankAccount Account[] = { BankAccount("DANIYAL SAQIB", "0010000000000001", 1000), BankAccount("ANAS SHOAIB", "0010000000000002", 2000), BankAccount("AREEB KHAN", "0010000000000003", 3000), BankAccount("ALIZAY EHSAN", "0010000000000004", 4000) }; 
    int choice; // for menu based system input
    int selectedAccount = -1; // what is the current selected account (-1 means no account selected)

    system("cls"); // for clearing the directory line

    do { // 25 to 30 == 26 perfect value
    system("cls"); // clearing screen after every screen
    cout << "============================== " << endl;
    cout << setw(26) << "ALLIED BANK - MAIN MENU" << endl;
    cout << "============================== " << endl;
    cout << "Currently selected account: [" << getAccountNumber(Account,selectedAccount) << " - " << getOwnerName(Account, selectedAccount) << "]" << endl;
    cout << endl; // VERTICAL SPACING AS per the requirements. 
    
    cout << "0. Clear Screen " << endl; // added feature for clearing output
    cout << "1. Select Account" << endl;
    cout << "2. Check Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl; 
    cout << "5. Exit" << endl; 
    cout << "============================== " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 0: // clearing screen
        system("cls"); 
        break;
        case 1: // Selecting an Account
        system("cls"); // clearing screen after every screen
        cout << " WHICH ACCOUNT YOU WANT TO SELECT? " << endl;
        
        do { // log out functionality added
         for (int i = 0; i < 4; i++) {
             cout << setw(5) << i << ". " << setw(1) << getAccountNumber(Account, i) << " - " << getOwnerName(Account, i) << endl;
         }
          cin >> selectedAccount;
        } while (selectedAccount < -1 || selectedAccount > 3); // -1 to 3 values accepted 
        
        break;
        case 2: // Check Account's Balance
        if (selectedAccount == -1) {
            cout << "You Have Not Selected any Account For Checking Balance. Please select a Account First " << endl;
        }
        else { // Account is selected
            char balance_choice = ' ';
            while(true)
            {
             cout << "Balance : " << Account[selectedAccount].getBalance() << endl;
             cout << "Press Enter to continue: ";
             
             cin.get(balance_choice);
             cin.ignore();
             if (balance_choice == '\n'){
                break;
             }
            }

            break;
        }
        case 3: // Deposit
        system("cls"); // clearing screen after every screen
        if (selectedAccount == -1) {
            cout << "You Have Not Selected any Account for Deposit. Please select a Account First " << endl;
        }
        else { // Account is selected
             int b;
             cout << "Enter Amount To Deposit : ";
             cin >> b;
             if (!is_number(to_string(b))){
                 cout << "Please enter a valid input";
             }
             Account[selectedAccount].Deposit(b); // called Deposit Function
        }
        break;
        case 4: // Withdrawal
        system("cls"); // clearing screen after every screen
        if (selectedAccount == -1) {
            cout << "You Have Not Selected any Account for Withdrawal. Please select a Account First " << endl;
        }
        else { // Account is selected
             int b;
             cout << "Enter Amount To Withdrawal : ";
             cin >> b;
             Account[selectedAccount].Withdraw(b); // called Withdraw Function
        }
        break;
    }
    } while (choice != 5); // 5 enter krne pr exit hai
    
    cout << "THANK YOU FOR YOUR TRUST IN US! GOODBYE! " << endl; // goodbye message

    return 0;
}