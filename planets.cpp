#include <iostream>
#include <cctype>
#include <string>     // For string type

using namespace std;

enum Planet_Type { MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO };

string planetToName( Planet_Type p );
Planet_Type nameToPlanet( string s );

int main()
{
	string planet;
	Planet_Type p;

	cout << "please enter the name of a planet: ";
	cin >> planet;
	
	for (string::size_type /* or int */ i=0; i < planet.length(); i++)
		planet[i] = tolower(planet[i]);

	p = nameToPlanet( planet );

	for (/*Planet_Type*/ p /* = nameToPlanet(planet)*/; p >= MERCURY; p = Planet_Type (p - 1))
	{
		cout << planetToName (p) << endl;
	}

	return 0;
}

Planet_Type nameToPlanet( /* IN */  string s )
{
	if (s == "mercury")
		return MERCURY;
	if (s == "venus")
		return VENUS;
	if (s == "earth")
		return EARTH;
	if (s == "mars")
		return MARS;
	if (s == "jupiter")
		return JUPITER;
	if (s == "saturn")
		return SATURN;
	if (s == "uranus")
		return URANUS;
	if (s == "neptune")
		return NEPTUNE;
	if (s == "pluto")
		return PLUTO;
	return EARTH;

}

string planetToName( /* IN */  Planet_Type p )
{
	switch (p)
	{
		case 0: return "Mercury";
		case 1: return "Venus";
		case 2: return "Earth";
		case 3: return "Mars";
		case 4: return "Jupiter";
		case 5: return "Saturn";
		case 6: return "Uranus";
		case 7: return "Neptune";
		case 8: return "Pluto";
		default: return "error";
	}
			
		
}