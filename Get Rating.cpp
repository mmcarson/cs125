#include <iostream>
#include <string>

using namespace std;


void GetRating(char&);                  // function prototype
void GetName(string&);                  // function prototype
void PrintNameAndRating(string, char);  // function prototype

int main()
{
    char  rating;
	string name;

	GetName(name);                           // function call
	while ((name != "quit") && (name != "Quit"))
	{
		GetRating(rating);                       // function call
		PrintNameAndRating( name, rating );      // function call
	}

	return 0;
}

// function definition
void GetName(/* out */ string& name)   // function heading
// Precondition:  None
// Postcondition: User has been prompted to enter a name or "quit"
//     && name == name entered
{	  
	cout << "Enter a name or " << '"' << "quit" << '"' << " to quit." << endl;
	cin >> name;
}

// function definition
void GetRating(/* out */ char& letter)  // function heading
// Precondition:  None
// Postcondition: User has been prompted to enter a letter
//     && letter == one of these input values: E, G, A, or P
{	        
    cout  << "Enter employee rating." << endl;
    cout  << "Use E(Excellent), G(Good), A(Average), or P(Poor) : ";
    cin >> letter;
    while((letter != 'E') && (letter != 'G') && 			    
		  (letter != 'A') && (letter != 'P'))
    {
        cout << "Rating invalid. Please enter again: ";
        cin   >> letter;
    }
}

// function definition
void PrintNameAndRating(/* in */ string name, 
	                    /* in */ char rating )  // function heading
// Precondition:  name and rating are assigned legal values
// Postcondition: Prints name and rating with labels
{	        
	cout << name << endl; 
	cout << "Rating: " << rating << endl;
}