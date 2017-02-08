//******************************************************************
// CS-125 HW5
// Put your name and program description here.
//******************************************************************
#include <iostream>    // For file I/O
#include <fstream>     // For file I/O
#include <string>
#include <iomanip>

using namespace std;

struct PlayerType
{
//  Data for each player
	string  name;
	int     atBats;
	int     hits;
	float   battingAvg;
};

const int MAX_LENGTH = 30;    // Maximum number of components allowed
typedef PlayerType ItemType;         // Type of each component

class List
{
public:
    List();
        // Constructor
        // Postcondition:
        //     Empty list is created

	bool IsEmpty() const;
        // Postcondition:
        //     Return value == true, if list is empty
        //                  == false, otherwise

    bool IsFull() const;
        // Postcondition:
        //     Return value == true, if list is full
        //                  == false, otherwise

    int Length() const;
         // Postcondition:
         //     Return value == length of list
  
    void Insert( /* in */ ItemType item );
        // Precondition:
        //     NOT IsFull()
        // Postcondition:
        //     item is in list
        //  && Length() == Length()@entry + 1

    void Delete( /* in */ ItemType item );
        // Precondition:
        //     NOT IsEmpty()
        // Postcondition:
        //     IF item is in list at entry
        //         First occurrence of item is no longer in list
        //       && Length() == Length()@entry - 1
        //     ELSE
        //         List is unchanged

    bool IsPresent( /* in */ ItemType item ) const;
        // Postcondition:
        //     Return value == true, if item is in list
        //                  == false, otherwise

    void Reset();
        // Postcondition:
        //     Iteration is initialized
        
    ItemType GetNextItem();   
        // Precondition:
        //     Iteration has been initialized by call to Reset;
        //     No transformers have been invoked since last call
        // Postcondition:
        //     Return value is the item at the current position 
        //     in the list on entry;
        //     If last item has been returned, the next call will
        //     return the first item.
            	
    void SelSort();
        // Postcondition:
        //     List components are in ascending order of value
            	
    void UpdatePlayer( /* inout */ ItemType item, /* in */ int atBats, /* in */ int hits );
        // Precondition:
        //     NOT IsFull() && item is in list
        // Postcondition:
        //     item data has been updated by adding in atBats and hits

private:
    int      length;
    int      currentPos;
    ItemType data[MAX_LENGTH];
};
 
void GetPlayers( /* inout */ List& players );
void UpdatePlayers( /* inout */ List& players, /* out */ string& date );
void PrintPlayers( /* in */ List players, /* in */ string date );

int main()
{
    List players;
	string date;
 
    // Get initial player data from a file and load into List of players
	GetPlayers( players );
 
    // Get game data from a file and update List of players
	UpdatePlayers( players, date );
  
    // Sort List of players by batting average (high to low)
	players.SelSort();

    // Output updated List of players
	PrintPlayers( players, date );
 
	return 0;
}

List::List()
// Constructor
// Postcondition:
//     length == 0
{
    length = 0;
}
//******************************************************************
bool List::IsEmpty() const
// Reports whether list is empty
// Postcondition:
//     Function value == true, if length == 0
//                    == false, otherwise
{
    return (length == 0);
}
//******************************************************************
bool List::IsFull() const
// Reports whether list is full
// Postcondition:
//     Function value == true, if length == MAX_LENGTH
//                    == false, otherwise
{
    return (length == MAX_LENGTH);
}
//******************************************************************
int List::Length() const
// Returns current length of list
// Postcondition:
//     Function value == length
{
    return length;
}
//******************************************************************
void List::Insert( /* in */ ItemType item )
// Inserts item into the list
// Precondition:
//     length < MAX_LENGTH
//  && item is assigned
// Postcondition:
//     data[length@entry] == item
//  && length == length@entry + 1
{
    data[length] = item;
    length++;
}
//******************************************************************
void List::Delete( /* in */ ItemType item )
// Deletes item from the list, if it is there
// Precondition:
//     length > 0
//  && item is assigned
// Postcondition:
//     IF item is in data array at entry
//           First occurrence of item is no longer in array
//        && length == length@entry - 1
//     ELSE
//           length and data array are unchanged
{
    int index = 0;    // Index variable

    while (index < length && item.name != data[index].name)
        index++;

    if (index < length)
    {                                 // Remove item
        data[index] = data[length-1];
        length--;
    }
}
//******************************************************************
bool List::IsPresent( /* in */ ItemType item ) const
// Searches the list for item, reporting whether it was found
// Precondition:
//     item is assigned
// Postcondition:
//     Function value == true, if item is in data[0..length-1]
//                    == false, otherwise
{
    int index = 0;    // Index variable

    while (index < length && item.name != data[index].name)
        index++;
    return (index < length);
}
//******************************************************************
  void List::Reset()
// Postcondition:
//     Iteration is initialized
  {
      currentPos = 0;
  }        
//******************************************************************      
 ItemType List::GetNextItem()
 // Precondition:
 //     Iteration has been initialized by call to Reset;
 //     No transformers have been invoked since last call
 // Postcondition:
 //     Returns item at the currentPos@entry in the list and
 //     resets current to next position or first position if
 //     last item is returned
  {
       ItemType item;
       item = data[currentPos];
       if (currentPos == length - 1)
           currentPos = 0;
       else
           currentPos++;
       return item;    
  }                  
//******************************************************************
void List::SelSort()
// Sorts list into ascending order
// Postcondition:
//     data array contains the same values as data@entry, rearranged
//     into ascending order
{
    ItemType temp;               // Temporary variable
    int      passCount;          // Loop control variable
    int      searchIndx;         // Loop control variable
    int      minIndx;            // Index of minimum so far

    for (passCount = 0; passCount < length - 1; passCount++)
    {
         
        minIndx = passCount;

        // Find the index of the smallest component
        // in data[passCount..length-1]

        for (searchIndx = passCount + 1; searchIndx < length;
                                                       searchIndx++)
            if (data[searchIndx].name < data[minIndx].name)
                minIndx = searchIndx;

            // Swap data[minIndx] and data[passCount]

         temp = data[minIndx];
         data[minIndx] = data[passCount];
         data[passCount] = temp;
   }
}
//******************************************************************
void GetPlayers( /* inout */ List& players )
{
}
//******************************************************************
void UpdatePlayers( /* inout */ List& players, /* out */ string& date )
{
}
//******************************************************************
void PrintPlayers( /* in */ List players, /* in */ string date )
{
}
