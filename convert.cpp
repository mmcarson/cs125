// Program Convert converts a temperatures between Fahrenheit and Celsius
// depending on whether the user enters an F or a C.

#include <iostream>
using namespace std;

int main ()
{
    char letter;		// Place to store input letter
    int  tempIn;		// Temperature to be converted
	int tempOut;		// Converted temperature
    cout  << "Input Menu"  << endl  << endl;
    cout  << "F:  Convert from Fahrenheit to Celsius"<< endl;
    cout  << "C:  Convert from Celsius to Fahrenheit"  << endl;
    cout  << "Q:  Quit"  << endl;
    cout  << "Type a C, F, or Q; then press return."  
          << endl;
   
	cin  >> letter;

    while ((letter != 'Q') && (letter != 'q'))
    {
	    cout  << "Type an integer number and press return."<< endl;
	    cin  >> tempIn;
		switch (letter)
		{
			case 'f' :
			case 'F' : 	tempOut = 5 * (tempIn - 32) / 9;
						cout  << tempIn << " in Fahrenheit is " << tempOut
							  <<" in Celsius. " << endl;
						break;
			case 'c' :
			case 'C' :	tempOut = (9 * tempIn / 5) + 32;
						cout  << tempIn << " in Celsius is " << tempOut
						      <<" in Fahrenheit. " << endl;
						break;
			case 'q' :
			case 'Q' : break;
			default  : cout << "Invalid input." << endl;
					   break;
		}
		cout  << "Type a C, F, or Q; then press return."<< endl;
		cin  >> letter;
    }
    return 0;
}