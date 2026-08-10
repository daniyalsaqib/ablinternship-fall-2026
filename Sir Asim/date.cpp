#include <iostream>
#include <string>
using namespace std;

/* code -r .
Basically here if current date: 03/08/2026
then after +1000 days date should be: 29/08/2029
(IT'S BASICALLY A TEST CASE NOW BRAINSTORM LOGIC 4:39 PM 03/08/2026)

resuming 11:01 AM 04/08/2026

The code d = stoi(dateinput[0] + dateinput[1]); contains a logic error if dateinput is a std::string or char array.

In C++, dateinput[0] and dateinput[1] are individual characters (e.g., '1' and '2'). Adding them directly ('1' + '2') sums their ASCII values (49 + 50 = 99), resulting in the string "99" being passed to stoi, not "12".

logging off 04/08/2026 5:14 PM

logging on 05/08/2026 9:37 AM
*/

void output(int day, int month, int year) {
/*
test cases for day and month is
if single digit in month or day, like 1 - 9 use formatting 01 - 09
and for year no need for any formatting
*/
if (day >= 1 && day <= 9) {cout << "0" << day << "/";}
else {cout << day << "/";}
if (month >= 1 && month <= 9) {cout << "0" << month << "/";}
else {cout << month << "/";}
cout << year << endl;
}

// THIS WILL RETURN THE WHOLE DATE IN FORMATTED ORDER (DD/MM/YYYY)
bool leapyear(int y) { // checking if it's a leap year or not
// 4, 100, 400
        if (y % 4 == 0 && y % 100 != 0) {
             // 4 se divisble hona chahiye but 100 se nahi
             return true;
        }
        else if (y % 100 == 0) {
            if (y % 400 == 0) { // fully divisble?
               return true;
            }
            else { // ye bhi lagana zaroori for leap yearing
                return false;
            }
        }
        else { // doesn't obey 4 and 400 and obeys 100 or obeys nothing
              return false;
        }
} // pretty straight forward

// just returning the days in a month 
int DaysinMonth(int month, int year) {
    int days;
 switch (month) {
    case 1: days = 31;
    break;
    case 2: // year variable for only february (leap year condition)
    if (leapyear(year)) {
        days = 29;
    }
    else {days = 28;}
    break;
    case 3: days = 31;
    break;
    case 4: days = 30;
    break;
    case 5: days = 31;
    break;
    case 6: days = 30;
    break;
    case 7: days = 31;
    break;
    case 8: days = 31;
    break;
    case 9: days = 30;
    break;
    case 10: days = 31;
    break;
    case 11: days = 30;
    break;
    case 12: days = 31;
    break;
 }
 return days;
}

// whole process in this function
void calculation(string dateinput, int days, int months, int years) {
    int d,m,y; // day, month, year
    
    // 0 to 1
    d = stoi(dateinput.substr(0,2)); // sub string extracts the data from start to finish index very easy
    // 3 to 4
    m = stoi(dateinput.substr(3,5)); // the finish index is not added to the string (excluded)
    // 6 to end
    
    y = stoi(dateinput.substr(6)); // these extraction is pretty much hard coded

    for (int i = 0;  i < days; i++) { // till the End Of Days
        d = d + 1;
        
        /*
        if month is january and and january has 31 days every year
        31 > 31 (false)
        32 > 31 (true) 
        month should be converted 
        days are already being running through d = d + 1
        now m = m + 1 logic
        */
        if (d > DaysinMonth(m,y)) {
            d = 1; 
            m = m + 1;
            // now for the year as like if m is running
            /*
            one case will come like m becomes 13
            so we have to iterate years aswell so
            iske andar itni bari condition nahi lagti as every year 
            is increased by december and december has 31 days every year
            so we will just write m > 12
            */
           if (m > 12) {
              m = 1;
              y = y + 1;
           }
        }
    }

    // now for months separately
    for (int i = 0; i < months; i++) {
        m = m + 1;

        if (m > 12) {
              m = 1;
              y = y + 1;
        }
    }

    // now for years
    for (int i = 0; i < years; i++) {
        y = y + 1; // no issue it can be infinite
    }
    
    output(d,m,y); // output directly in calculation no need for main
}

int main()
{
    string dateinput; // the date to be inputted like today 04/08/2026
    int Days, Months, Years; // The Days, Months and Years to be added
    string choice;

    // PROMPT
    do {
      //  system("cls"); // clearing screen
    cout << "Enter the Date to be input (DD/MM/YYYY) : ";
    cin >> dateinput;
    cout << "How Many Days To Be Added? : ";
    cin >> Days;
    cout << "How Many Months To Be Added? : ";
    cin >> Months;
    cout << "How Many Years To Be Added? : ";
    cin >> Years;

    // PASSING THROUGH FUNCTIONS AND ALSO DISPLAYING FROM THEM
    calculation(dateinput, Days, Months, Years);

    cout << "Would you Like to Continue? (y/n) : ";
    cin >> choice;
    } while (choice != "n");
    
    cout << "Thanks For your Time! " << endl;

    return 0;
}