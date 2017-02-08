// The program cannot be run on compilers without the string class.
// Program Greet prints a greeting on the screen.

#include <iostream>
#include <string>
using namespace std;

const string FIRST_NAME = "Marissa"; 
const string LAST_NAME = "Carson";
const string MESSAGE = "Good morning";
int  main ()
{
    string message;
	string name;
    message = MESSAGE + ',';
	name = FIRST_NAME + ' ' + LAST_NAME + '!';
    cout  << message << endl;
	cout  << name    << endl;
    return 0;
}

