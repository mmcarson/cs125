#include <iostream>
#include <fstream>    // For file I/O
#include <string>
#include <iomanip>
#include "apt.h"

using namespace std;

void openInputFile( ifstream& inFile );

int main()
{
	Apt coe;
	string apt;
    ifstream inFile;              // occupant data (one integer per apartment)

	openInputFile( inFile );

	// read file of occupants and store into array
	coe.readOccupants( inFile );

	// calculate the total # of occupants in all apartments
	cout << "Total # of occupants = " << coe.totalOccupants() << endl << endl;

	// print a table of all apartments
	coe.printApts();

	// filter apartment data for just one apartment
	cout << endl << "Enter apt number: ";
    cin >> apt;
 	coe.printApt( apt );

	// get rent for one apartment
	cout << endl << "Enter apt number: ";
    cin >> apt;
 	cout << "Rent for apt " << apt << " = $" << coe.getRent( apt ) << endl;

	// calculate average occupancy for all apartments
	cout << endl << "Average occupancy = " << coe.avgOccupancy() << endl;

	// prints names of available apartments
	cout << endl << "Available apartments: " << endl;
	coe.printAvailable();

	// gets name of cheapest apartment
	cout << endl << "Apartment " << coe.getCheapestAvailable() << " is the cheapest available." << endl;

    return 0;
}

void openInputFile( ifstream& inText )
{	
	inText.open( "KoHawk Regency.dat" );
    if ( !inText )
    {
        cout << "Can't open the input file.";  
        exit(1);        // halts program                
    }
}