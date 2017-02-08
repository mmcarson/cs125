#include <iostream>
#include <fstream>    // For file I/O
#include <string>
#include <iomanip>

using namespace std;

struct AptType 
{
	string aptNum;   // apartment number
	int numOcc;      // number of current occupants
	int legalOcc;    // legal maximum occupancy
	int numBed;      // number of bedrooms
	int numBath;     // number of bathrooms
	float rent;      // monthly rent
};

void openInputFile( ifstream& inFile );
void readOccupants( ifstream& inFile, AptType apts[], int& size );
int totalOccupants( const AptType apts[], int size );
void printApts(const AptType apts[], int size );
void printApt( /* IN */ const AptType apts[], /* IN */ int size, /* IN */ string aptNum );
float getRent( /* IN */ const AptType apts[], /* IN */ int size, /* IN */ string aptNum );
float avgOccupancy( /* IN */ const AptType apts[], /* IN */  int size );
void printAvailable( /* IN */ const AptType apts[], /* IN */ int size );
string getCheapestAvailable( /* IN */ const AptType apts[], /* IN */ int size );

const int BUILDING_SIZE = 10;    // Number of apartments

int main()
{
    AptType apts[BUILDING_SIZE]; 
	int size;
	string apt;
    ifstream inFile;              // occupant data (one integer per apartment)

	openInputFile( inFile );

	// read file of occupants and store into array
	readOccupants( inFile, apts, size );

	// calculate the total # of occupants in all apartments
	cout << "Total # of occupants = " << totalOccupants( apts, size ) << endl << endl;

	// print a table of all apartments
	printApts( apts, size );

	// filter apartment data for just one apartment
	cout << endl << "Enter apt number: ";
    cin >> apt;
 	printApt( apts, size, apt );

	// get rent for one apartment
	cout << endl << "Enter apt number: ";
    cin >> apt;
 	cout << "Rent for apt " << apt << " = $" << getRent( apts, size, apt ) << endl;

	// calculate average occupancy for all apartments
	cout << endl << "Average occupancy = " << avgOccupancy(apts, size) << endl;

	// prints names of available apartments
	cout << endl << "Available apartments: " << endl;
	printAvailable(apts, size);

	// gets name of cheapest apartment
	cout << endl << "Apartment " << getCheapestAvailable(apts, size) << " is the cheapest available." << endl;

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

void readOccupants( ifstream& inFile, AptType apts[], int& size )
{
    cout << "Reading apartment data ..." << endl;
	inFile >> size;
    for (int i = 0; i < size; i++)
    {
        inFile >> apts[i].aptNum >> apts[i].numOcc >> 
			      apts[i].legalOcc >> apts[i].numBed >>
				  apts[i].numBath >> apts[i].rent;
		//cout << " aptNum = " << apts[i].aptNum << endl;
    }
}

int totalOccupants( const AptType apts[], int size )
{
	int total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + apts[i].numOcc;
    }
	return total;
}

void printApts(const AptType apts[], int size )
{
	cout << "Apt #   Occ  Legal  # Bed  # Bath  Rent" << endl;
	cout << "---------------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << apts[i].aptNum << setw(6) << apts[i].numOcc << setw(6) << 
			      apts[i].legalOcc << setw(8) << apts[i].numBed << setw(7) <<
				  apts[i].numBath << setw(5) << "$ " << apts[i].rent << endl;
    }
}

void printApt( /* IN */ const AptType apts[], /* IN */ int size, /* IN */ string aptNum )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  prints apartment data for aptNum with labels
{
	cout << "Apt #   Occ  Legal  # Bed  # Bath  Rent" << endl;
	cout << "---------------------------------------" << endl;

	for (int i = 0; i < size; i++)
		if (apts[i].aptNum == aptNum)
		{
        cout << setw(4) << apts[i].aptNum << setw(6) << apts[i].numOcc << setw(6) << 
			      apts[i].legalOcc << setw(8) << apts[i].numBed << setw(7) <<
				  apts[i].numBath << setw(5) << "$ " << apts[i].rent << endl;
		}
}

float getRent( /* IN */ const AptType apts[], /* IN */ int size, /* IN */ string aptNum )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  returns rent for aptNum
{
	for (int i = 0; i < size; i++)
		if (apts[i].aptNum == aptNum)
			return apts[i].rent;
}

float avgOccupancy( /* IN */ const AptType apts[], /* IN */  int size )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  returns average number of occupants across all apartments
{
	float total = 0;
	for (int i = 0; i < size; i++)
		total = total + apts[i].numOcc;
	return total/size;
}

void printAvailable( /* IN */ const AptType apts[], /* IN */ int size )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  prints apartment data for all apartments not currently occupied.
{
	for (int i = 0; i < size; i++)
		if (apts[i].numOcc == 0)
			cout << setw (5) << apts[i].aptNum;
	cout << endl;
}

string getCheapestAvailable( /* IN */ const AptType apts[], /* IN */ int size )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  returns name of the cheapest apartment not currently occupied.
{
	string cheapest;
	float minRent = 1000.0f;

	for (int i = 0; i < size; i++)
		if (apts[i].rent <= minRent)
		{
			minRent = apts[i].rent;
			cheapest = apts[i].aptNum;
		}

	return cheapest;
}
