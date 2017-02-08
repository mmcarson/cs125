//******************************************************************
// Prompts program
// This program demonstrates the use of input prompts
//******************************************************************
#include <iostream>
#include <iomanip>    // For setprecision()
#include <string>

using namespace std;

/*const float SHIPPING_COST = float(4.95);*/     // named constant

int main()
{
    int   partNumber;
    int   quantity;
    float unitPrice;
    float totalPrice;
	float shippingCost;
	float each;
	string name;

    cout << fixed << showpoint            // Set up floating-pt.
         << setprecision(2);              //   output format

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter part number, quantity, and unit price: ";      // Prompt
    cin >> partNumber >> quantity >> unitPrice;                   // Read data

	if ( (unitPrice < 0) || (quantity < 0) )
		{
			cout << "ERROR: no purchase made." << endl;
			return 0;
	}

	each = .99;
	shippingCost = quantity * each;

	if (shippingCost > 3.00) 
		shippingCost = 3.00;
	if ((name == "Marissa") || (name == "Terry") || (name == "Evan"))
		shippingCost = 0.00;

    totalPrice = quantity * unitPrice + shippingCost;

	cout << endl << "Name is " << name << endl;          // Echo print
	cout << "Part " << partNumber << ", quantity " << quantity << ", at $ " << unitPrice << " each" << endl;
    cout << "Total is $ " << totalPrice << ", including shipping of $ " << shippingCost << endl;
	if (shippingCost == 0)
		cout << "Employee discount: free shipping!" << endl;


    return 0;
}
