#include <iostream>
using namespace std;

/* Calculator Done 5:16 PM 06/08/2026
we will make 4 user defined functions of add() subtract() multiply() divide()
and lastly main() for whole menu based system...

every function will return a number to the main function for display.

Validations to be applied aswell as a security feature
*/

int add(int a, int b)
{
    while (b != 0) // till carry doesn't finish run it.
    {
        int carry = a & b; // single & gives carry while && gives boolean values
        a = a ^ b; // this just adds (no carries here)
        b = carry << 1; // carry adding
    }
    return a;
}

int subtract(int a, int b) // -
{
  // difference = XOR 
   while (b != 0) // till borrow doesn't finish run it.
    {
        // borrow to be under condition
        int borrow = (~a) & b;
        a = a ^ b; // this just borrows
        b = borrow << 1;
    }
    return a;
}

int multiply(int a, int b) 
{
    int result = 0;

    while (b > 0)
    {
        if (b & 1) // Is b odd?
        {
            result = result + a;
        }

        a = a << 1; // multiplication by 2
        b = b >> 1; // division by 2
    }

    return result;
}

int divide(int dividend, int divisor) // very very easy
{
    int quotient = 0; // no division applied till now

    // if divisor gets big, division already finished, it will convert to points then
    while (dividend >= divisor) // 8 >= 4
    {
        dividend = dividend - divisor;
        quotient = quotient + 1;
    }

    return quotient;
}

int mod(int dividend, int divisor) // very very easy
{
    int remainder = 0; // no division applied till now

    // if divisor gets big, division already finished, it will convert to points then
    while (dividend >= divisor) // 8 >= 4
    {
        dividend = dividend - divisor;
        remainder = dividend;
    }

    return remainder; // you can also return dividended directly if you like
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

        case 5: // /
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