// ******************************************************************
// This program takes a list of songs and their play times and sees 
// how well they will fit onto an 80 minute CD.
//
// This is Homework Assignment 1 in CS 125 taught by Terry Hostetler. 
// Program by Marissa Carson. 
// ******************************************************************

#include <iostream>  // Input-output stream
#include <fstream>  // File stream
#include <iomanip> // Manipulate appearance of input-output

using namespace std;

int main()
{
	// List of variables and their data types
    ifstream inFile;    // Data file
	int songNumber;    // Song number on CD
	int inSeconds;    // Each song length in seconds, recorded from the input file
	int minutes;     // The number of minutes of a specific song
	int extraSeconds;    // The number of leftover seconds of a specific song
	int tSeconds;       // The running total number of seconds
	int tMinutes;      // The running total length of the group of songs, in minutes
	int tExtraSeconds;// The number of leftover seconds of the running total
	int lminutes;    // The number of minutes left on the CD
	int lseconds;   // The number of leftover seconds remaining on the CD


    inFile.open("songs.dat");                          // Attempt to open input file
    if ( !inFile )                                    // Did the file open? If the input file doesn't exist...
    {
        cout << "Input file " << '"' << "songs.dat" << '"' << " does not exist.";   // ...run an error message...
		cout << endl << "Cannot open input file or run program." << endl;
        return 1;                                                                 // ...and quit the program.
    }

	// Set variables equal to zero
	songNumber = 0;
	tSeconds = 0;

	// Table headings
	cout << "Song          Song Time             Total Time    " << endl;
	cout << "Number     Minutes  Seconds     Minutes   Seconds" << endl;
	cout << "------     -------  -------     -------   -------" << endl;

	while (inFile)     //Continues reading song lengths until the end of the file
		{
			                                                       // For each song:
			inFile >> inSeconds;                                  // Read values from file "songs.dat"
			songNumber ++;                                       // Add one to the song number
			minutes = inSeconds / 60;                               // Convert song time to minutes
			extraSeconds = inSeconds % 60;                         // Calculate number of extra seconds of song time
			tSeconds = tSeconds + inSeconds;                      // Update total time
			tMinutes = tSeconds / 60;                            // Convert total time to minutes
			tExtraSeconds = tSeconds % 60;                           // Calculate the number of extra seconds on the total time
			cout << songNumber << setw(11) << minutes               // Display the song number,
				 << setw(10) << extraSeconds << setw(12)           // song time,
				 << tMinutes << setw(11) << tExtraSeconds         // and total time.
				 << endl;
	} 

	// If the CD cannot be made...
	if ((tMinutes > 80) || ((tMinutes == 80) && (tExtraSeconds == 0)))
		{cout << "Your list of songs will not fit on an" << endl
			  << "80 minute CD! Try eliminating a few  " << endl
			  << "songs, or making multiple CDs.       " << endl;
	return 1;
	}
	// ...display an error message and terminate the program. 


	// Calculate the number of minutes and seconds left on the CD
	if (tExtraSeconds != 60) 
	{
		lminutes = 79 - tMinutes;
		lseconds = 60 - tExtraSeconds;
	}

	else 
	{
		lminutes = 80 - tMinutes;
		lseconds = 0;
	}

	cout << "Of the 80-minute CD capacity, " << lminutes << " minutes and " << lseconds << " seconds of free space remain." << endl;
	
if (lminutes > 30)
	{
		cout << "You've got a lot of extra space on" << endl
			 << "your CD! You could add several more" << endl
			 << "songs." << endl;
	}
	else
		if (lminutes > 15)
		{
			cout << "You could add a few" << endl
				 << "more songs if you"   << endl
				 << "wanted to do so."    << endl;
		}
		else
			if (lminutes < 5)
			{
				cout << "Your CD is the perfect length!" << endl
					 << "Don't change a thing." << endl;
			}

	
	inFile.close(); // Close the input file
	return 0; // Return an integer to end the program
}


