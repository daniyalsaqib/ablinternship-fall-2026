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
*/

string output() {

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
        }
        else { // doesn't obey 4 and 400 and obeys 100 or obeys nothing
              return false;
        }
} // pretty straight forward

// whole process in this function
void calculation(string dateinput, int days) {
    int d,m,y; // day, month, year
    
    // 0 to 1
    d = stoi(dateinput.substr(0,2)); // sub string extracts the data from start to finish index very easy
    // 3 to 4
    m = stoi(dateinput.substr(3,5)); // the finish index is not added to the string (excluded)
    // 6 to end
    y = stoi(dateinput.substr(6)); // these extraction is pretty much hard coded

    for (int i = 0;  i < days; i++) { // till the End Of Days
        d = d + 1;

        // 2 is feb
        if (m == 2 && leapyear(y) && d == 28) { // checking for leap year
            
        }

    }

}

int main()
{
    string dateinput; // the date to be inputted like today 04/08/2026
    int Days; // The Days to be added

    // PROMPT
    cout << "Enter the Date to be input (DD/MM/YYYY) : ";
    cin >> dateinput;
    cout << "How Many Days To Be Added? : ";
    cin >> Days;

    // PASSING THROUGH FUNCTIONS AND ALSO DISPLAYING FROM THEM
    calculation(dateinput, Days);
    
    return 0;
}