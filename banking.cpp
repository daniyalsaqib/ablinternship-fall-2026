#include <iostream>
#include <iomanip> // for formatting purposes setw() etc
#include <string>
#include <sstream>
using namespace std;

/*
BRAINSTORMING THREAD
under sir affan waheed
methods and attributes in OOP
for clear screen use //system("cls")
getter and setters

    catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

9:32 AM 18/08/2026 Exception Handling to be learnt 110% Day 1 Completed.
*/

// we'll use Object Oriented Programming here
// as because pre defined stuff is needed

void PressEnterToContinue()
{
    cout << endl; // new line
    char balance_choice = ' ';
    while (true)
    {
        cout << "Press Enter to continue... ";

        cin.get(balance_choice);
        cin.ignore(); // garbage values should be emitted
        if (balance_choice == '\n')
        {
            break;
        }
    }
}

// Source - https://stackoverflow.com/a/447307
// Posted by Bill the Lizard, modified by community. See post 'Timeline' for change history
// Retrieved 2026-08-17, License - CC BY-SA 2.5

bool isFloat(string myString)
{
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

class BankAccount
{
private: // all attributes declared
    string name, accountnumber, PIN;
    float balance; // i'm using balance as integer for simplifying purposes

public: // account number for allied bank is 16 digits with first 3 digits is 001.
    BankAccount(string n, string acc, string p, int b = 0)
    { // default paratermized constructor
        name = n;
        accountnumber = acc;
        PIN = p;     // added pin
        balance = b; // by default is 0 but with value can be changed.
    }

    // friend functions for displaying owner name and account number
    friend string getAccountNumber(BankAccount a[], int choice);
    friend string getOwnerName(BankAccount a[], int choice);

    float getBalance()
    {
        return balance;
    }

    void Deposit(int selectedAccount) // exception handling applied
    {                                 // Deposit Money
        float value;
        try
        {
            if (selectedAccount == -1)
            {
                system("cls"); // clearing screen after every screen
                cout << "You Have Not Selected any Account for Deposit. Please select a Account First " << endl;
                PressEnterToContinue();
                return;
            }
            else
            {                  // Account is selected
                system("cls"); // clearing screen after every screen
                cout << "Enter Amount To Deposit : ";
                cin >> value;
                if (!isFloat(to_string(value)))
                {
                    cout << "Please enter a valid input... ";
                    PressEnterToContinue();
                    return;
                }
            }

            if (value <= 0)
            {
                cout << "Please Enter +ve Number! " << endl;
                PressEnterToContinue();
                return;
            }

            balance = balance + value;
            cout << value << " PKR Deposited To Allied Bank. " << endl;
            cout << "Remaining Balance : " << getBalance() << endl;
        }
        catch (...) // catches any type of error using ...
        {
            cout << "Something went wrong! " << endl;
            PressEnterToContinue();
            return;
        }
    }
    void Withdraw(int selectedAccount) // exception handling applied
    {                                  // Withdraw money
        float value;
        try
        {
            system("cls"); // clearing screen after every screen
            if (selectedAccount == -1)
            {
                cout << "You Have Not Selected any Account for Withdrawal. Please select a Account First " << endl;
                PressEnterToContinue();
                return;
            }

            // PROMPT
            cout << "Enter Amount To Withdrawal : ";
            cin >> value;

            if (value <= 0)
            {
                cout << "Withdrawal Failed: Withdrawal amount cannot be in -ve" << endl;
            }
            else if (value > getBalance())
            { // 1500 > 1000 error
                cout << "Withdrawal Failed: Amount Exceeds Available Balance" << endl;
            }
            else
            { // successful
                balance = balance - value;
                cout << value << " PKR Withdrawn from Allied Bank. " << endl;
                cout << "Remaining Balance : " << getBalance() << endl;
            }
        }
        catch (...) // catches any type of error using ...
        {
            cout << "Something went wrong! " << endl;
            PressEnterToContinue();
            return;
        }
    }
}; // BANKACCOUNT CLASS FINISHED

bool validinput(string input)
{
    for (int i = 0; i < input.size(); i++)
    { // 0 to size
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

int AccountSelection(BankAccount Account[]) // exception handling applied
{
    /*
    stoi = string to integer
    to_string(num); = integer to string
    */
    try
    {
        int selectedAccount = -1; // -1 means nothing is logged in
        do
        {                  // log out functionality added
            system("cls"); // clearing screen after every screen
            cout << " WHICH ACCOUNT YOU WANT TO SELECT? " << endl;
            cout << setw(14) << "-1. LOG OUT" << endl; // perfect
            for (int i = 0; i < 4; i++)
            {
                cout << setw(5) << i << ". " << setw(1) << getAccountNumber(Account, i) << " - " << getOwnerName(Account, i) << endl;
            }
            cin >> selectedAccount;
            // if (!validinput(selectedAccount)) {throw;} // exception handling to be learnt
        } while (selectedAccount < -1 || selectedAccount > 3); // -1 to 3 values accepted
        return selectedAccount;
    }
    catch (const std::exception &e) // catches any type of error using ...
    {
        std::cerr << e.what() << '\n';
        cout << "Something went wrong! " << endl;
        PressEnterToContinue();
        return -1; // nothing selected
    }
}

// friend functions
string getAccountNumber(BankAccount a[], int choice)
{
    if (choice == -1) // none selected
    {
        return "N/A";
    }
    return a[choice].accountnumber;
}

string getOwnerName(BankAccount a[], int choice)
{
    if (choice == -1) // none selected
    {
        return "N/A";
    }
    return a[choice].name;
}

void Login(BankAccount a[])
{
    char choice; // to continue or not
    string acc, pin; // these both will be string
    do
    {
        cout << "============================== " << endl;
        cout << setw(26) << "ALLIED BANK - LOGIN" << endl;
        cout << "============================== " << endl;

        // PROMPT
        cout << "Enter Account Number: ";
        getline(cin, acc);
        cout << "Enter PIN: ";
        getline(cin, pin);

        // exit functionality added
        cout << "Do You want To Continue? (y/n) : ";
        cin >> choice;
    } while (choice != 'y'); // tab tak yes hai tab tak chalta reh

    system("cls"); // clearing screen after all operations
    cout << "THANK YOU FOR CHOOSING ALLIED BANK!" << endl; // goodbye message
    exit(0); // exits immediately
}

int LogOut() {return -1;}

int main()
{
    BankAccount Account[] = {BankAccount("DANIYAL SAQIB", "0010000000000001", "0001", 1000), BankAccount("ANAS SHOAIB", "0010000000000002", "0002", 2000), BankAccount("AREEB KHAN", "0010000000000003", "0003", 3000), BankAccount("ALIZAY EHSAN", "0010000000000004", "0004", 4000)};
    int choice;               // for menu based system input
    int selectedAccount = -1; // what is the current selected account (-1 means no account selected)

    system("cls"); // for clearing the directory line

    do
    {
        // 25 to 30 == 26 perfect value
        system("cls"); // clearing screen after every screen
        cout << "============================== " << endl;
        cout << setw(26) << "ALLIED BANK - MAIN MENU" << endl;
        cout << "============================== " << endl;
        cout << "Currently selected account: [" << getAccountNumber(Account, selectedAccount) << " - " << getOwnerName(Account, selectedAccount) << "]" << endl;
        cout << endl; // VERTICAL SPACING AS per the requirements.

        cout << "1. Log Out" << endl;
        cout << "2. Check Balance" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cout << "============================== " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0: // LOG OUT
            selectedAccount = LogOut();
            Login(Account);
            break;
        case 1:                                          // Selecting an Account
            selectedAccount = AccountSelection(Account); // simple function dial
            break;
        case 2: // Check Account's Balance
            system("cls");
            if (selectedAccount == -1)
            {
                cout << "You Have Not Selected any Account For Checking Balance. Please select a Account First " << endl;
                PressEnterToContinue(); // function made for continuing the process
            }
            else
            { // Account is selected
                while (true)
                {
                    cout << "Balance : " << Account[selectedAccount].getBalance() << endl;
                    PressEnterToContinue(); // function made for continuing the process

                    break; // loop break
                }
            }
            break;                                             // case break
        case 3:                                                // Deposit
            Account[selectedAccount].Deposit(selectedAccount); // called Deposit Function
            break;
        case 4:                                                 // Withdrawal
            Account[selectedAccount].Withdraw(selectedAccount); // called Withdraw Function
            break;
        }
    } while (choice != 5); // 5 enter krne pr exit hai

    system("cls");                                               // clearing whole screen for goodbye
    cout << "THANK YOU FOR YOUR TRUST IN US! GOODBYE! " << endl; // goodbye message

    return 0;
}
