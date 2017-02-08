// This program calculates the area of a square.
// The user is prompted to enter the number of inches on each side. 

#include <iostream>
using namespace std;

int main()
{
	int inches;
	cout << "Enter the number of inches on each side: ";
	cin >> inches; 
	cout << endl << "The area is " << inches * inches << endl;

	return 0;

}