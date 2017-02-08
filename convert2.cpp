// Program Convert converts a temperature in Fahrenheit to 
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C..

#include <iostream>
using namespace std;

int  ConvertedTemp(int, char);
void Menu();
bool Error(char);

int main ()
{
    char  letter;		// Place to store input letter
    int  tempIn;		// Temperature to be converted
	bool error;         // Error if letter is not valid

	Menu();

    do
	{
		cin  >> letter;
		letter = toupper(letter);
		error = Error(letter);
		if (error)
		{
			cout << "Invalid input. Type F, C, or Q." << endl;
		}
	} while (error);

    while (letter != 'Q')
    {
	cout  << " Type an integer number, and press return."
	      << endl;
	cin  >> tempIn;

	if (letter == 'F')
	    cout << "Fahrenheit to Celsius"  << endl;
	else
	    cout << "Celsius to Fahrenheit"  << endl;
	cout  << "Temperature to convert: "  << tempIn
	      << endl;
	cout  << "Converted temperature:  "
	      << ConvertedTemp(tempIn, letter)
	      << endl  << endl;
	cout  << "Type a C, F,  or Q; then press return."
	      << endl;

    do
	{
		cin  >> letter;
		letter = toupper(letter);
		error = Error(letter);
		if (error)
		{
			cout << "Invalid input. Type F, C, or Q." << endl;
		}
	} while (error);
    }
    return 0;
}

// *******************************************

int  ConvertedTemp(int tempIn, char letter)
{
    if (letter == 'C')
        return (9 * tempIn / 5) + 32;
    else
        return 5 * (tempIn - 32) / 9;
}
//*******************************************

void Menu()
{
    cout  << "Input Menu"  << endl  << endl;
    cout  << "F:  Convert from Fahrenheit to Celsius"  << endl;
    cout  << "C:  Convert from Celsius to Fahrenheit"  << endl;
    cout  << "Q:  Quit"  << endl;
    cout  << "Type a C, F,  or Q; then press return."  << endl;
}

bool Error(char inLetter)
{
	if ((inLetter != 'F') && (inLetter != 'C') && (inLetter != 'Q'))
		return true;
	else
		return false;
}