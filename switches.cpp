// Program Switches demonstrates the use of the Switch 
// statement.

#include <iostream>
using namespace std;

int main ()
{
    char  letter;
    int  first;
    int  second;
    int  answer;

    cout  << "Enter an A for addition or an S for" << endl
          << "subtraction, followed by two integer "  << endl
          << "numbers.  Press return.  Enter a Q to quit."  
          << endl;
    cin   >> letter;
    while ((letter != 'Q') && (letter != 'q'))
    {
         cin  >> first  >> second;

       switch (letter)
       {
			case 'a' :
			case 'A' : answer = (first + second);
                       cout << first  << " + "  << second
                            << " is "  << answer  << endl;
                       break;
			case 's' : 
            case 'S' : answer = (first - second);
		               cout << first  << " - "  << second
			              << " is "  << answer  << endl;
		               break;
			case 'q' : 
			case 'Q' : break;
			default  : cout << "Invalid letter input. Please type" << endl
						    << "A for addition, S for subtraction," << endl
							<< "Or Q to quit." << endl;
					   cin  >> letter;
					   break;
        }
        cin  >> letter;
    }

    return 0;
}

