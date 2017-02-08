#include <iostream>
#include <fstream>    // For file I/O

using namespace std;

void openInputFile( ifstream& inFile );
void readOccupants( ifstream& inFile, int occupants[], int size );
int totalOccupants( const int occupants[], int size );
int mostOccupants( const int occupants[], int size );
int numNotOccupied( const int occupants[], int size );

const int BUILDING_SIZE = 10;    // Number of apartments

int main()
{
    int occupants[BUILDING_SIZE]; // occupants[i] == # of occupants in apartment i+1
    int apt;                      // An apartment number
    ifstream inFile;              // occupant data (one integer per apartment)

	openInputFile( inFile );

	// read file of occupants and store into array
	readOccupants( inFile, occupants, BUILDING_SIZE );

	// calculate the total # of occupants in all apartments
	cout << "Total # of occupants = " << totalOccupants( occupants, BUILDING_SIZE ) << endl;
	cout << "Most occupants in an apartment = " << mostOccupants( occupants, BUILDING_SIZE ) << endl;
	cout << "Number of apartments not occupied = " << numNotOccupied (occupants, BUILDING_SIZE ) << endl << endl;

    cout << "Begin apt. lookup..." << endl;
    do
    {
        cout << "Apt. number (1 through " << BUILDING_SIZE << ", or 0 to quit): ";
        cin >> apt;
        if (apt != 0)
            cout << "Apt. " << apt << " has " << occupants[apt-1] << " occupants" << endl;
    } while (apt != 0);

    return 0;
}

void openInputFile( ifstream& inText )
{	
	inText.open( "apartments.in" );
    if ( !inText )
    {
        cout << "Can't open the input file.";  
        exit(1);        // halts program                
    }
}

void readOccupants( ifstream& inFile, int occupants[], int size )
{
    for (int i = 0; i < size; i++)
    {
        inFile >> occupants[i];
        // cout << occupants[i] << endl;
    }
}

int totalOccupants( const int occupants[], int size )
{
	int total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + occupants[i];
    }
	return total;
}

int mostOccupants( const int occupants[], int size )
    // Pre:    occupants array contains occupancy data in indices 0 to size-1
	// Post:  returns the most occupants in any apartment
{
	int most = 0;
	for (int i = 0; i < size; i++)
	{
		if (occupants[i] > most)
			most = occupants[i];
	}
	return most;
}

int numNotOccupied( const int occupants[], int size )
    // Pre:    occupants array contains occupancy data in indices 0 to size-1
	// Post:  returns the number of apartments not occupied
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (occupants[i] == 0)
			count++;
	}
	return count;
}