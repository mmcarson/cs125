//******************************************************************
// Marissa's Power Table Program
// September 7th, 2012
// This program computes the square, cube, and fourth power of an integer.
//******************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

//int Square( int );
//int Cube( int );
//int Quart( int );

int main()
{
	int x = 1;

	cout << "x     x^2     x^3     x^4" << endl;
	cout << "-     ---     ---     ---" << endl;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;
	cout << x << setw(8) << x*x << setw(8) << x*x*x << setw(8) << x*x*x*x << endl;
	x++;



 //   cout << "The square of " << x << " is " << Square(x) << endl;
 //   cout << "The cube of " << x << " is " << Cube(x) << endl;
	//cout << "The fourth power of " << x << " is " << Quart(x) << endl;

    return 0;
}

//int Square( int n )
//{
//    return n * n;
//}
//
//int Cube( int n )
//{
//    return n * n * n;
//}
//
//int Quart( int n )
//{
//	return n * n * n * n;
//}