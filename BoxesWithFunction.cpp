// Program Shell2 promps for the number of dollar signs for
// the top of the box.  That number / 2 - 2  lines are 
// printed with dollar signs on the sides.        

#include <iostream>
#include <iomanip>
using namespace std;

void  Print(int numSigns);
// FILL IN documentation. 

int main ()
{
    int  number;

    cout  << "Enter the number of dollar signs for the top; "
	  << "press return. "  << endl;
    cout  << "Enter end-of-file characer to quit."  << endl;
    cin  >> number;
    while (cin)
    {
	Print(number);
	cout  << "Enter the number of dollar signs for the top; "
	      << "press return. "  << endl;
	cout  << "Enter end-of-file characer to quit."  << endl;


	cin >> number;
    }
    return 0;
}

//**************************************

void  Print(int numSigns)
// FILL IN documentation.
{
	for (int count = 1; count <= numSigns; count++)
	{
		cout << '$';
	}
	cout << endl;
	for (int count = 1; count <= ((numSigns/2)-2); count++)
	{
		cout << '$' << setw(numSigns - 1) << '$' << endl;
	}
	for (int count = 1; count <= numSigns; count++)
	{
		cout << '$';
	}
	cout << endl; 
}

