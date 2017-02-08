// Program Shell

#include <iostream>
#include <string>
using namespace std;

const string MONTH = "September";
const string DATE = "5th";
const string YEAR = "2012";
const string FIRST_NAME = "Marissa";
const string LAST_NAME = "Carson";
int main ()
{
	string name;
	string date;
	name = LAST_NAME + ',' + ' ' + FIRST_NAME;
	date = MONTH + ' ' + DATE + ',' + ' ' + YEAR;
	cout << name << endl;
	cout << endl;
	cout << date << endl;
	cout << endl;
    return 0;
}
