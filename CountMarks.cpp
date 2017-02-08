// Program Shell1 counts punctuation marks in a file.

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream  inData;
    char symbol;
    int  periodCt = 0;
    int  commaCt = 0;
    int  questionCt = 0;
    int  colonCt = 0;
    int  semicolonCt = 0;
	int  spaceCt = 0;

    inData.open("switch.dat");

	while (inData)
	{
		inData.get(symbol);
		switch (symbol)
		{
			case '.' : periodCt++;
					   break;
			case ',' : commaCt++;
					   break;
			case '?' : questionCt++;
					   break;
			case ':' : colonCt++;
					   break;
			case ';' : semicolonCt++;
					   break;
			case ' ' : spaceCt++;
					   break;
		}
	}

	cout << "Periods: " << periodCt << endl
		 << "Commas: " << commaCt << endl
		 << "Question marks: " << questionCt << endl
		 << "Colons: " << colonCt << endl
		 << "Semicolons: " << semicolonCt << endl
		 << "Spaces: " << spaceCt << endl;
            
    return 0;
}
