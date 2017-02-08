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
            	
    void UpdatePlayer( /* inout */ ItemType item );
        // Precondition:
        //     NOT IsFull() && item is in list
        // Postcondition:
        //     item data has been updated by adding in atBats and hits

private:
    int      length;
    int      currentPos;
    ItemType data[MAX_LENGTH];
};