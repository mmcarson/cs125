// Program Favorit determines the favorite soft drink.
#include <iostream>
using namespace std;

enum  DrinksType {COKE, PEPSI, SPRITE, DR_PEPPER};
void Prompt();
int TotalSurveyed(int [], DrinksType);
void Percents(int [], DrinksType, int);

int main ()
{
    int  sums[4];
    int  number;
    DrinksType  index;
	int surveyed;

    for (index = COKE; index <= DR_PEPPER; index =  DrinksType(index+1))
	    sums[index] = 0;

    Prompt();
    cin  >> number;
    while (number != 4)
    {
		sums[number]++;
		 //   switch (number)
		 //{
		 //case 0: sums[COKE]++;
			// break;
		 //case 1: sums[PEPSI]++;
			// break;
		 //case 2: sums[SPRITE]++;
			// break;
		 //case 3: sums[DR_PEPPER]++;
			// break;
		 //}
	     //Prompt();
	     cin  >> number;
    }

    cout << sums[COKE] << " people surveyed prefer Coke." << endl;
	cout << sums[PEPSI] << " people surveyed prefer Pepsi." << endl;
	cout << sums[SPRITE] << " people surveyed prefer Sprite." << endl;
	cout << sums[DR_PEPPER] << " people surveyed prefer Dr. Pepper." << endl << endl;

	surveyed = TotalSurveyed(sums, index);
	cout << surveyed << " people participated in this survey." << endl << endl;

	Percents(sums, index, surveyed);

    return 0;
}

/*******************************************************/

void Prompt()
{
    cout  << "Enter a 0 if your favorite is a Coke."  << endl;
    cout  << "Enter a 1 if your favorite is a Pepsi." << endl;
    cout  << "Enter a 2 if your favorite is a Sprite." 
          << endl;
    cout  << "Enter a 3 if your favorite is a Dr. Pepper."
	        << endl;
    cout  <<"Enter a 4 if you wish to quit the survey."
	        << endl;
}

/*******************************************************/

int TotalSurveyed(int people[], DrinksType soda)
{
	int sum = 0;
	for (soda = COKE; soda <= DR_PEPPER; soda =  DrinksType(soda+1))
		sum = sum + people[soda];
	return sum;
}

/*******************************************************/

void Percents(int people[], DrinksType soda, int total)
{
	int percent;
	for (soda = COKE; soda <= DR_PEPPER; soda =  DrinksType(soda+1))
	{
		percent = people[soda] * 100 / total;
		cout << percent << '%' << " of people surveyed prefer ";
		switch (soda)
		{
		case COKE: cout << "Coke." << endl; break;
		case PEPSI: cout << "Pepsi." << endl; break;
		case SPRITE: cout << "Sprite." << endl; break;
		case DR_PEPPER: cout << "Dr. Pepper." << endl; break;
		}
	}
}