//******************************************************************
// This program reads and echoes the characters from one line
// of an input file
//******************************************************************
#include <iostream>
#include <fstream>    // For file I/O

using namespace std;

int main()
{
    char     inChar;    // An input character
    ifstream inFile;    // Data file
	int count; // Number of A's
	int lineNumber; // Line Number
	int aTotal;

    inFile.open("text.dat");           // Attempt to open input file
    if ( !inFile )                     // Was it opened?
    {
        cout << "Can't open the input file.";  // No--print message
        return 1;                              // Terminate program
    }

	
	lineNumber = 1;
	aTotal = 0;

                    // Get first character - priming read
	for (lineNumber; lineNumber<7; lineNumber++)
	{
		inFile.get(inChar);
		count = 0;
		while (inChar != '\n')
		{
			if ((inChar == 'a') || (inChar == 'A'))
				count ++;
			inFile.get(inChar);            // Get next character
		}
		cout << "There are " << count << " number of a's in line " << lineNumber << '.' << endl;
		aTotal = aTotal + count;
	}
		
	cout << "There are " << aTotal << " number of a's in the file." << endl;
    return 0;
}
