#include <iostream>
using namespace std;

/* Calculator Done 3:43 PM 03/08/2026
we will make 4 user defined functions of add() subtract() multiply() divide() %()
and lastly main() for whole menu based system...

every function will return a number to the main function for display.

Validations to be applied aswell as a security feature
*/

int add(int a, int b) // +
{
  return a + b;
}

int subtract(int a, int b) // -
{
  return a - b;
}

int multiply(int a, int b) // *
{
 return a * b;
}

int divide(int a, int b) // /
{
 return a / b;
}

int mod(int a, int b) // % modulus as a built in function was ambigous that's why didn't use
{
 return a % b;
}

int main()
{
    int choice, n1, n2; // FOR MENU BASED SYSTEM INPUT

    cout << "WELCOME TO ALLIED BANK CALCULATOR!" << endl;

    do{ // do while is the best in this situation
      cout << "WHAT WOULD YOU LIKE TO DO? " << endl;
      cout << "0. EXIT " << endl;
      cout << "1. +" << endl;
      cout << "2. -" << endl;
      cout << "3. *" << endl;
      cout << "4. /" << endl;
      cout << "5. %" << endl;
      cout << "6. Clear Screen" << endl;
      cout << "PRESS THE CORESPONDING NUMBER : ";
      cin >> choice;

      switch (choice)
      {
        case 1: // +
         cout << "Enter 1st number : ";
         cin >> n1;
         cout << "Enter 2nd number : ";
         cin >> n2;
         cout << "RESULT : " << add(n1,n2) << endl;
        break;
      
        case 2: // -
         cout << "Enter 1st number : ";
         cin >> n1;
         cout << "Enter 2nd number : ";
         cin >> n2;
         cout<< "RESULT : " << subtract(n1,n2) << endl;
        break;

        case 3: // *
         cout << "Enter 1st number : ";
         cin >> n1;
         cout << "Enter 2nd number : ";
         cin >> n2;
         cout<< "RESULT : " << multiply(n1,n2) << endl;
        break;

        case 4: // /
         cout << "Enter 1st number : ";
         cin >> n1;
         cout << "Enter 2nd number : ";
         cin >> n2;
         cout<< "RESULT : " << divide(n1,n2) << endl;
        break;

        case 5: // %
         cout << "Enter 1st number : ";
         cin >> n1;
         cout << "Enter 2nd number : ";
         cin >> n2;
         cout<< "RESULT : " << mod(n1,n2) << endl; 
        break;
      default: // any other number other than the above will result in defualt case automatically
         // clearing screen
         system("cls");
        break;
      }
    } while (choice != 0); // loop till choice is not equal to 0.

    cout << "THANK YOU FOR CHOOSING ALLIED BANK!" << endl; // GOODBYE MESSAGE
    return 0;
}