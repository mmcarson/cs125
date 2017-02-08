//******************************************************************
// Activity program
// This program outputs an appropriate activity
// for a given temperature
//******************************************************************
#include <iostream>

using namespace std;

int main()
{
    int temperature;    // The outside temperature
    char stormy;

    // Read and echo temperature

	cout << "Enter the outside temperature: ";
    cin >> temperature;
    cout << "Is it stormy? (Y/N): ";
    cin >> stormy;

	cout << endl << "The current temperature is " << temperature << " degrees and the weather is ";
	if (stormy == 'Y')
      cout << "stormy." << endl; 
	else 
      cout << "clear." << endl; 

    // Print activity

    cout << "The recommended activity is ";
    if ((temperature > 85) && (stormy != 'Y' && stormy != 'y' ) )
        cout << "swimming." << endl;
    else if ((temperature > 70) && (stormy != 'Y' && stormy != 'y' ))
	{
        cout << "tennis, ";
		cout << "provided it's not raining";
	}
    else if ((temperature > 32) && (stormy != 'Y' && stormy != 'y' ))
        cout << "golf." << endl;
    else if ((temperature > 0) && (stormy != 'Y' && stormy != 'y' ))
        cout << "skiing." << endl;
    else
        cout << "stay inside!." << endl;

    return 0;
}
