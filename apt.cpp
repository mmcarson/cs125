#include <iostream>
#include <fstream>    // For file I/O
#include <string>
#include <iomanip>
#include "apt.h"

void Apt::readOccupants( ifstream& inFile )
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

int Apt::totalOccupants()
{
	int total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + apts[i].numOcc;
    }
	return total;
}

void Apt::printApts()
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

void Apt::printApt( /* IN */ string aptNum )
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

float Apt::getRent( /* IN */ string aptNum )
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  returns rent for aptNum
{
	for (int i = 0; i < size; i++)
		if (apts[i].aptNum == aptNum)
			return apts[i].rent;
}

float Apt::avgOccupancy()
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  returns average number of occupants across all apartments
{
	float total = 0;
	for (int i = 0; i < size; i++)
		total = total + apts[i].numOcc;
	return total/size;
}

void Apt::printAvailable()
// Pre:    apts array contains apartment data in indices 0 to size-1
// Post:  prints apartment data for all apartments not currently occupied.
{
	for (int i = 0; i < size; i++)
		if (apts[i].numOcc == 0)
			cout << setw (5) << apts[i].aptNum;
	cout << endl;
}

string Apt::getCheapestAvailable()
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
