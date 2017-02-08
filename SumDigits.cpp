#include <iostream>
#include <fstream>
using namespace std;

int Minimum (ifstream&);

int main ()
{
	ifstream inData;

	inData.open("numbers.dat");
	
	cout << Minimum(inData) << endl;

	return 0;
}
int Minimum(ifstream& input)
{
	int number;
	int minimum;

	input >> minimum;

	while(input)
	{
		input >> number;
		if (number < minimum)
			minimum = number;
	}

	return minimum;
}