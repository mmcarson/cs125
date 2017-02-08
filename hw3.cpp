//*********************************************************************
// Marissa Carson
//*********************************************************************
// This is Homework Assignment 3 for CS 125, taught by Terry Hostetler.
// The program is used for calculation regarding ceramic floor tiles.
// It will take data about a number of rooms, their dimensions, and the 
// size of tiles being used, and figure out the number of tiles needed 
// and how many will be left over, assuming tiles come in boxes of 20. 
//*********************************************************************

#include <iostream>

using namespace std;

struct Measurement          // a length measurement in feet + inches
{
	int feet;
	int inches;
};

struct RoomSize             // dimensions of a room
{
	Measurement width;
	Measurement length;
};

struct EndData              // data to be printed at the end
{
	int totalTiles;         // total tiles needed
	int boxes;              // # of 20-tile boxes to order
	int leftover;           // # of leftover tiles
};

void GetDimension(/* out */ Measurement&);
// Out: a dimension in the room size, error-free.
int TilesInRoom(/* in */ RoomSize, /* in */Measurement); 
// Returns # of tiles in a room. In: room size, tile size. 
int Boxes(/* in */ int); // Returns number of boxes needed. 
// In: total number of tiles needed. 
int Leftover(/* in */ int, /* in */ int); // Returns # of leftover tiles.
// In: total number of tiles needed, number of boxes. 
void PrintEndData(/* in */ EndData); // Prints data at the end.
// In: set of data including # total tiles needed, boxes, and leftover tiles.

//*************************************************************************

int main()
{
	int roomCount;                      // Number of rooms being tiled
	RoomSize size;                      // Size of current room
	Measurement tileSize;               // Size of tiles
	int tilesInRoom;                    // Number of tiles in current room
	EndData data;                       // Data to be printed at the end

	data.totalTiles = 0;

	cout << "Enter number of rooms: ";
	do{
		cin >> roomCount;
		cout << endl;
		if (roomCount <= 0)             // Checks that input value is positive
		{
			cout << "Invalid input. Please enter a positive integer" << endl
			     << "for the number of rooms." << endl;
		}
	} while (roomCount <=0);

	cout << "Enter size of tile in inches: ";
	do{
		cin >> tileSize.inches;
		cout << endl;
		if (tileSize.inches <= 0)       // Checks that input value is positive
		{
			cout << "Invalid input. Please enter a positive integer" << endl
			     << "for the tile size in inches." << endl;
		}
	} while (tileSize.inches <= 0);

	// For each room: 
	for (int roomNumber = 1; roomNumber <= roomCount; roomNumber++)
	{
		cout << "Enter room width (feet and inches, separated by a space):";
		GetDimension(size.width);
		cout << "Enter room length (feet and inches, separated by a space):";
		GetDimension(size.length);

		// Calculate and print number of tiles in current room, based on 
		// room dimensions and tile size.
		tilesInRoom = TilesInRoom(size, tileSize);
		cout << "Room requires " << tilesInRoom << " tiles." << endl;

		// Adds the current room's tile count to the total.
		data.totalTiles = data.totalTiles + tilesInRoom;
	}

	// Calculates number of 20-tile boxes needed
	data.boxes = Boxes(data.totalTiles);

	// Calculates number of tiles left over
	data.leftover = Leftover(data.boxes, data.totalTiles);

	PrintEndData(data);

	return 0;
}

//************************************************************************

void GetDimension(/*out*/Measurement& dimension)
// Reads and error-checks an inches and feet measurement.
// Precondition: a variable of type Measurement has been declared.
// Postcondition: valid (meaning both inches and feet are positive and 
// inches are less than 12) data has been assigned to that variable.
{
	do{               // Reads input values until they are valid
		cin >> dimension.feet >> dimension.inches;
		cout << endl;
		if ((dimension.feet <= 0) && (dimension.inches <= 0))
		{                               // Checks that input value is positive
			cout << "Invalid input. Please enter positive integers" << endl
				 << "for feet and inches of the room width." << endl;
		}
		if (dimension.inches > 11)     // Inches must be < 12
		{
			cout << "Invalid input. Please enter a value less than 12" << endl
				 << "for the number of inches inches of the room width." << endl;
		}
	} while (((dimension.feet <= 0) && (dimension.inches <= 0)) || (dimension.inches > 11)); 
}

//************************************************************************

int TilesInRoom(/*in*/RoomSize room, /*in*/Measurement tile)
// Calculates the number of tiles needed to cover a room of given dimensions.
// Precondition: valid measurements for the room dimensions and the tile size are given.
// Postcondition: the number of tiles of a particular size needed to cover 
// the floor of a room of particular dimensions is returned as an integer value.
{
	// Convert measurements in feet + inches to inches
	int length = room.length.feet * 12 + room.length.inches;
	int width = room.width.feet * 12 + room.width.inches;

	// Divide each dimension by the tile size
	int vtiles = length / tile.inches;
	int htiles = width / tile.inches;

	// Round up to the nearest multiple of the tile size
	if ((length % tile.inches) != 0)
		vtiles = vtiles + 1;
	if ((width % tile.inches) != 0)
		htiles = htiles + 1;

	// Multiply the horizontal # tiles by the vertical # tiles to get the total
	return (htiles * vtiles);
}

//************************************************************************

int Boxes(/*in*/int tiles)
// Calculates number of 20-tile boxes needed for a certain number of tiles.
// Precondition: the number of total tiles has been calculated and input. 
// Postcondition: the number of boxes has been calculated and output.
{
	if ((tiles % 20) == 0)
		return (tiles / 20);
	else                            // Round up if needed
		return (tiles / 20 + 1);
}

//************************************************************************

int Leftover(/*in*/int boxes, /*in*/ int tiles)
// Calculates leftover tiles
// Precondition: values exist for # of boxes, and total # of tiles
// Postcondtion: leftover tiles calculated, value returned
{
	return (boxes * 20 - tiles);
}

//************************************************************************

void PrintEndData(/*in*/EndData info)
// Precondition: user has finished entering data for all rooms; tiles, 
// boxes, and leftovers have been calculated.
// Postcondition: The data is printed to the screen.
{
	cout << "Total tiles required is " << info.totalTiles << '.' << endl;
	cout << "Number of boxes needed is " << info.boxes << '.' << endl;
	cout << "There will be " << info.leftover << " extra tiles." << endl;
}