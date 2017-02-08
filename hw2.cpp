//This program decrypts messages by deleting every Nth character.
//Homework assignment #2, CS 125 taught by Terry Hostetler
//Program by Marissa Carson

                            // Header files:
#include <iostream>        // *Input-output stream
#include <fstream>        // *File stream
#include <string>        // *Allows "strings" of character data to be used

using namespace std;   //Standard namespace

                                                  // Function prototypes:
char Input (ifstream&, bool&);                   // *Prototype for Input function
int FindN (int);                                // *Prototype for N function
string Character (int, char, int);             // *Prototype for Character function
void Message (string, string&);               // *Prototype for Message function
void OutputMessage (string);                 // *Prototype for OutputMessage function
bool EndLine (string&);                     // *Prototype for EndLine function

int main ()                               // Main function
{
	                                    // Main variable declarations:
	ifstream inData;                   // *Input stream
	int N=3, count=3;                 // *Integer variables: N, and NumCh (number of characters in a line)
	bool endOfLine = false;          // *True or false: is it the end of the line?
	char inChar;                    // *Input character and determine if it is the end of a line
	string outMessage;             // *Output character
	string message = "";          // *The string made from adding all the outMessage characters together

	inData.open("hw2.in");                   // Opens the input file
	inChar = Input(inData, endOfLine);      // and retrieves a character through the Input function

	while (inData)                        // Continues until end of file
	{
		while ((endOfLine == false) && (inData))             // Continues until line ends
		{                                                   // For each line:                      
			count++;                                       // *Counts the number of characters in the line
			outMessage = Character(N, inChar, count);     // *Records each non-garbage character
			Message(outMessage, message);                // *Adds these characters to the output string
			inChar = Input(inData, endOfLine);          // *Gets next character, and detects end of line
		}
		if (endOfLine == true)                  // When a new line is starting but the file has not ended:
		{                                      // *Prepares to output a line break to string
			EndLine(outMessage);              // and sets endOfLine to false
			Message(outMessage, message);    // *Adds to string
			N = FindN(count);               // *Calculates the value of N using the character count
			count=0;                       // *Resets the character count
			inChar = Input(inData,        // *And once again retrieves a character from input
				endOfLine);       
		}
	}
	
	OutputMessage(message);         // Compiled text from function Message is 
	                               // output to the file "hw2.out"
	return 0;                     // And main, an integer function, returns a zero to say there are
	                             // no errors and to quit the program
}

char Input (ifstream& dataStream, bool& endLine)  // Input function header: 
	                                             // passes input file stream (inout parameter) 
												// and end of line trigger (inout parameter) by reference
                                               // *Preconditon: File "hw2.in" exists and is readable
{								              // *Postcondition: a character from the input file is returned
	char letter; 

	dataStream.get(letter);                // Records one character from the input file
	if (letter == '\n')                   // Detects an end of line
		endLine = true;                  // Notifies main function of line's end
	else                                // Or if the line doesn't end
		endLine = false;               // The end of line variable remains false
	return letter;                    // And the result of the function 
	                                 // returns the letter to the main function as a character
}

int FindN (int numCh)    // FindN function header: passes character count (in parameter) by value
                        // *Precondition: program has counted the number of characters in the last line
{                      // *Postcondition: N has been calculated and is returned to the main function
	int N;                             // Declares variable N
	N = (numCh % 3) + 2;              // Calculates N
	return N;                        // Returns the value of N to the main function
}

string Character (int N,  // Character function header: passes N (in parameter),
	char inLetter,       // the input character (in parameter),
	int letterCount)    // and the character count (in parameter) by value
                       // *Precondition: N has a value, and an input character has been recorded
                      // *Postcondition: The garbage characters are deleted, meaning that
{                    // only the non-garbage characters are returned to be outputted
	int countdown = letterCount % N;                // Determines if there is a remainder when
	                                               // dividing the letter count by N, therefore
{	                                              // whether or not it is an Nth character
	string output;                               // Declares a string variable that will be the output

	switch (countdown)                         // Output is determined by whether or not the character's 
		                                      // "countdown to N" is equal to zero (making it an Nth 
								             // character) or not. 
	{
		case 0  : output = "";             // If an Nth (garbage) character, 
			      break;                  // return a blank string
		default : output = inLetter;     // If not, return the input character
			      break;
	}                                  // The output (a character or a blank string)
	return output;                    // is returned to the main function (as outMessage)
}}

void Message (string newCharacter, // Message function header: passes a character (in parameter) 
	string& compiledMessage)      // by value and a compiled string (inout parameter) by reference
	                             // *Precondition: a message being typed and the characters
						        // meant to be added to it exist and are passed into this function
{						       // *Postcondition: the new character has been added to the message
	compiledMessage = compiledMessage + newCharacter;
}

void OutputMessage (string message)          // OutputMessage function header:
	                                        // passes string message (in parameter) by value
										   // *Precondition: there is a string of decoded 
										  // characters stored and ready for output
{                                        // *Postcondition: the computer outputs the string
	ofstream outData;                   // Declares output file stream
	outData.open("hw2.out");           // Opens output file
	outData << message;               // Writes the compiled message into the output file
}
                                    
bool EndLine (string& newLine)     // EndLine function header: passes an end of line  
	                              // character (out parameter) to the main function by reference
	                             // *Precondition: the input message reaches the end of a line
{						        // *Postcondition: the string begins a new line
	newLine = '\n';
	bool endLine = false;
	return endLine;
}