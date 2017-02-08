#include <iostream>
#include <cctype>     // For toupper()
#include <string>     // For string type
#include <iomanip>    // For table manipulation

using namespace std;

enum SizeType    { SMALL, MEDIUM, LARGE };
enum ToppingType { ANCHOVIES, MUSHROOMS, SAUSAGE, PEPPERONI, ONIONS };
enum CrustType   { THIN, EXTRATHICK, STUFFED };

struct PizzaType            // ennumerated pizza information
{
	SizeType     size;      // diameter in inches
	ToppingType  topping;   // topping (only one allowed)
	CrustType    crust;     // crust type
};

struct PizzaTypeStrings     // pizza information, in plain text
{
	string     size;
	string  topping;
	string    crust;
};

void GetPizzaOrder( /* out */ PizzaType&);
void PrintPizzaOrder( /* in */ PizzaTypeStrings, double);
double GetPizzaPrice( /* in */ PizzaType);
void ConvertToText( /* in */ PizzaType, /* out */ PizzaTypeStrings&);

int main()
{
    PizzaType pizza;
	PizzaTypeStrings pizzaText;
	double price;

	GetPizzaOrder( pizza );
	price = GetPizzaPrice( pizza );
	ConvertToText( pizza, pizzaText );
	PrintPizzaOrder( pizzaText, price);

    return 0;
}
//******************************************************************
void GetPizzaOrder( /* out */ PizzaType& p ) 
{
	char choice;

    cout << "What size would you like (S=Small, M=Medium, L=Large)?" << endl;
	cin >> choice;
	choice = toupper(choice);
	switch (choice)
	{
		case 'S': p.size = SMALL;
			break;
		case 'M': p.size = MEDIUM;
			break;
		case 'L': p.size = LARGE;
			break;
		//default : 
	}

    cout << "What topping would you like (A=Anchovies, M=Mushrooms, S=Sausage, P=Pepperoni, O=Onions)?" << endl;
	cin >> choice;
	choice = toupper(choice);
	switch (choice)
	{
		case 'A': p.topping = ANCHOVIES;
			break;
		case 'M': p.topping = MUSHROOMS;
			break;
		case 'S': p.topping = SAUSAGE;
			break;
		case 'P': p.topping = PEPPERONI;
			break;
		case 'O': p.topping = ONIONS;
			break;
		//default : 
	}

    cout << "What crust would you like (T=Thin, E=Extra Thick, S=Stuffed)?" << endl;
	cin >> choice;
	choice = toupper(choice);
	switch (choice)
	{
		case 'T': p.crust = THIN;
			break;
		case 'E': p.crust = EXTRATHICK;
			break;
		case 'S': p.crust = STUFFED;
			break;
		//default : 
	}

}
//******************************************************************
void PrintPizzaOrder( /* in */ PizzaTypeStrings ptext, double price ) 
{

    cout << endl << "Thank you for your order!" << endl;
    cout << endl << "Here is your pizza summary" << endl << endl;
    cout << "Size      Topping      Crust      Price" << endl;
    cout << "----      -------      -----      -----" << endl;
	cout << setw (6) << ptext.size << setw(11) << ptext.topping 
		<< setw(12) << ptext.crust << setw(10) << '$' << price << endl;

}

//***************************************************************
double GetPizzaPrice( /* in */ PizzaType p)
{
	double price;

	switch (p.size)
	{
		case SMALL: price = 10.95;
					break;
		case MEDIUM: price = 12.45;
					 break;
		case LARGE: price = 14.10;
					break;
	}

	switch (p.crust)
	{
		case THIN: return price;
		case EXTRATHICK: return (price + 1.00);
		case STUFFED: return (price + 2.00);
	}
}

//****************************************************************
void ConvertToText (PizzaType p, PizzaTypeStrings& ptext)
{
	switch (p.size)
	{
	case SMALL: ptext.size = "Small";
		break;
	case MEDIUM: ptext.size = "Medium";
		break;
	case LARGE: ptext.size = "Large";
		break;
	}

	switch (p.topping)
	{
	case ANCHOVIES: ptext.topping = "Anchovies";
		break;
	case MUSHROOMS: ptext.topping = "Mushrooms";
		break;
	case SAUSAGE: ptext.topping = "Sausage";
		break; 
	case PEPPERONI: ptext.topping = "Pepperoni";
		break;
	case ONIONS: ptext.topping = "Onions";
		break;
	}

	switch (p.crust)
	{
	case THIN: ptext.crust = "Thin";
		break;
	case EXTRATHICK: ptext.crust = "Extra Thick";
		break;
	case STUFFED: ptext.crust = "Stuffed";
		break;
	}

}