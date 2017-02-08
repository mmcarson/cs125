#include <iostream>
#include <fstream>    // For file I/O

using namespace std;

void openInputFile( ifstream& inFile );
void readOccupants( ifstream& inFile, int occupants[], int size );
int totalOccupants( const int occupants[], int size );
void printViolators(const int occ[], const int legal[], int size );
void printAvailable(const int occ[], int size );
float AvgOccupancy(const int occ[], int size );

const int BUILDING_SIZE = 10;    // Number of apartments

int main()
{
    int occupants[BUILDING_SIZE]; // occupants[i] == # of occupants in apartment i+1
	int legalOcc[BUILDING_SIZE] = {3,5,3,3,4,2,5,3,3,3};  // legal occupancy
    int apt;                      // An apartment number
    ifstream inFile;              // occupant data (one integer per apartment)

	openInputFile( inFile );

	// read file of occupants and store into array
	readOccupants( inFile, occupants, BUILDING_SIZE );

	// calculate the total # of occupants in all apartments
	cout << "Total # of occupants = " << totalOccupants( occupants, BUILDING_SIZE ) << endl << endl;

	cout << "The average occupancy of these apartments is " 
		<< AvgOccupancy(occupants, BUILDING_SIZE) << " people." << endl << endl;

	cout << "The following apartments are available: " << endl;
	printAvailable(occupants, BUILDING_SIZE); 
	cout << endl << endl;

	cout << "These apartments are occupied beyond their legal limit: " << endl;
	printViolators(occupants, legalOcc, BUILDING_SIZE);
	cout << endl << endl;

    cout << "Begin apt. lookup..." << endl;
    do
    {
        cout << "Apt. number (1 through " << BUILDING_SIZE << ", or 0 to quit): ";
        cin >> apt;
        if (apt > 0)
            cout << "Apt. " << apt << " has " << occupants[apt-1] << " occupants" 
			     << " with a legal occupancy of " << legalOcc[apt-1] << endl;
    } while (apt > 0);

	cout << endl;

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

float AvgOccupancy(const int occ[], int size )
// Pre:    occ array contains occupancy data in indices 0 to size-1
// Post:  returns average number of occupants across all apartments
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum = sum + occ[i];
	return sum / size;
}

void printAvailable(const int occ[], int size )
// Pre:    occ array contains occupancy data in indices 0 to size-1
// Post:  prints the apartment numbers of all apartments that are currently available
// (i.e., occ == 0)
{
	for (int i = 0; i < size; i++)
	{
		if (occ[i] == 0)
			cout << i + 1 << "  ";
	}
}
void printViolators(const int occ[], const int legal[], int size )
// Pre:    occ array contains occupancy data in indices 0 to size-1
// Post:  prints the apartment numbers of all apartments exceeding legal maximum 
//           occupancy (i.e., with occ > legal)
{
	for (int i = 0; i < size; i++)
	{
		if (occ[i] > legal[i])
			cout << i + 1 << "  ";
	}
}