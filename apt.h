#include <iostream>
#include <fstream>    // For file I/O
#include <string>

using namespace std;

const int BUILDING_SIZE = 10;    // Number of apartments

struct AptType 
{
	string aptNum;   // apartment number
	int numOcc;      // number of current occupants
	int legalOcc;    // legal maximum occupancy
	int numBed;      // number of bedrooms
	int numBath;     // number of bathrooms
	float rent;      // monthly rent
};



class Apt
{
public:
	void readOccupants( ifstream& inFile );
	int totalOccupants();
	void printApts();
	void printApt( string aptNum );
	float getRent( /* IN */ string aptNum );
	float avgOccupancy();
	void printAvailable();
	string getCheapestAvailable();
private: 
	AptType apts[BUILDING_SIZE]; 
	int size;
};