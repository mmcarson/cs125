//******************************************************************
// NumDays program
// This program repeatedly prompts for a month and outputs the
// no. of days in that month. Approximate input is allowed: only the
// characters needed to determine the month are examined
//******************************************************************
#include <iostream>
#include <cctype>     // For toupper()
#include <string>     // For string type

using namespace std;

void ConvertToUpper( /* inout */ string& s );
string DaysInMonth( /* in */ string month);

int main()
{
    string month;    // User's input value

    do
    {
        cout << "Enter name of the month (or q to quit) : ";
        cin >> month;
		
		// convert month to all uppercase 
		ConvertToUpper( month );

        if (month[0] != 'Q')
            cout << DaysInMonth(month) << endl;

    } while (month[0] != 'Q');

    return 0;
}

//******************************************************************

void ConvertToUpper( /* inout */ string& s ) 
// Converts to all uppercase
{
    for (string::size_type i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
}

string DaysInMonth( /* in */ string month )   // The input month
// Returns a string giving the number of days in month if month is valid; 
//   else it returns a string with an error message.
// Precondition:
//     month is assigned
// Postcondition:
//     IF month contains a string that can be interpreted as
//        a month of the year
//         Function value == string containing the no. of days
//                           in that month
//     ELSE
//         Function value == "** Invalid month **"
{
    const string BAD_DATA = "** Invalid month \a\a\a**"; // Bad data message

    // Make sure length is at least 3 for upcoming tests
    month = month + "  ";

    // Examine first character, then others if needed
    switch (month[0])
    {
        case 'J' : if (month[1] == 'A')      // January
					   return "January has 31 days";
                   else if (month[2] == 'L' )    // July
                       return "July has 31 days";
                   else if (month[2] == 'N')  // June
                       return "June has 30 days";
                   else
                       return BAD_DATA;
        case 'F' : return "February has 28 or 29 days";    // February
        case 'M' : if (month[2] == 'R')
					   return "March has 31 days";     // March
                   else if (month[2] == 'Y' )    // May
                       return "May has 31 days";
                   else
                       return BAD_DATA;
        case 'A' : if (month[1] == 'P')       // April
                       return "April has 30 days";
                   else if (month[1] == 'U')  // August
                       return "August has 31 days";
                   else
                       return BAD_DATA;
        case 'S' : return "September has 30 days";                           // September
        case 'N' : return "November has 30 days";          // November
        case 'O' : return "October has 31 days";                           // October
        case 'D' : return "December has 31 days";          // December
        default  : return BAD_DATA;
    }
}
