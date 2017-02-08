//***********************************************************************
// This is homework assignment #4 for CS 125 taught by Terry Hostetler.
// The program grades multiple choice exams by inputting files for the
// answer key and the student answers, comparing them, and outputting 
// the data to a table in a file. 
//
// Marissa Carson											11.9.2012
//***********************************************************************

#include <iostream>
#include <fstream>    // For file I/O
#include <string>     // For character strings
#include <iomanip>    // For manipulating spacing in a table

using namespace std;

const int MAX_ANSWERS = 50;
enum Answer_Type {CORRECT, INCORR, NO_ANS};
typedef int AnswerSums[3];

struct GradingData    // A group of calculations regarding test data
{                     // for each student
	string name;
	AnswerSums answerSums;
	float totalScore;
	float percent;
};


void FillArray(/*inout*/ifstream& inData, /*out*/char answers[], /*out*/int& size);
// Fills an array with answers from an input file, counts # of questions
string GetName(/*inout*/ifstream& inData);
// Reads name from file
void CheckWithKey(/*in*/ const char key[], /*in*/ const char student[], 
	/*out*/ AnswerSums responses, /*in*/ int size);
// Compares students' answers with the key and returns the sums of the answers
void CalculateScore(/*inout*/ GradingData& studentData);
// Adds up the student's score based on their right and wrong answers
//      Correct answer: increase score by 1.0
//      Incorrect answer: decrease score by 0.25
//      No answer: score does not change
//      Score cannot go below 0.0
void Percent(/*inout*/ GradingData& studentData);
// Calculates the percent of maximum score
void PrintTableHeading(ofstream& outData);
// Adds table heading to output file
void PrintToTable(/*inout*/ ofstream& outData, /*in*/ const GradingData studentData);
// Adds student data to output file


int main()
{
	ifstream inData1, inData2;
	ofstream outData;
	char key[MAX_ANSWERS];
	char student[MAX_ANSWERS];
	GradingData studentData;
	int size=0;

	inData1.open("hw4.in1");
	inData2.open("hw4.in2");           // Open files
	outData.open("hw4.out");

	FillArray(inData1, key, size);           // Fills key
	PrintTableHeading(outData);        // Prepares table headings

	while (inData2)
	{
		studentData.name = GetName(inData2);
		FillArray(inData2, student, size);
		CheckWithKey(key, student, studentData.answerSums, size);
		CalculateScore(studentData);
		Percent(studentData);
		PrintToTable(outData, studentData);
	}

	return 0;
}

void FillArray(/*inout*/ifstream& inData, /*out*/char answers[], int& size)
// Precondition: input file has been opened
// Postcondition: array has been filled with data from input file
{
	char next;
	int i = 0;
	size = 0;

	inData.get(next);

	while (next != '.')
	{
		answers[i] = next;
		inData.get(next);
		i++;
		size++;
	}
	inData.get(next);
}

string GetName(/*inout*/ifstream& inData)
// Precondition: input file has been opened and has a student's name as the first ten characters
// Postcondition: those first ten characters have been returned as a string
{
	char ch;
	string name = "";

	for (int i=1; i <=10; i++)
	{
		inData.get(ch);
		name = name + ch;
	}
	
	return name;
}

void CheckWithKey(/*in*/ const char key[], /*in*/ const char student[], 
	/*out*/ AnswerSums responses, /*in*/ int size)
// Precondition: there are two arrays filled: one for the key, and one for the current student
// Postcondition: the number of correct, incorrect, and blank answers are returned
{
	responses[CORRECT]=0;
	responses[INCORR]=0;
	responses[NO_ANS]=0;

	for (int i=0; i < size; i++)
	{
		if (key[i] == student[i])
			responses[CORRECT]++;
		else if (student[i] == '#')         // Unanswered question is marked by a '#'
			responses[NO_ANS]++;
		else
			responses[INCORR]++;
	}

}

void CalculateScore(/*inout*/ GradingData& studentData)
// Precondition: number of correct, incorrect, and blank answers are given in answerSums
// Postcondition: score is returned 
{
	float score = 0;

	score += studentData.answerSums[CORRECT];           // Add one point for correct answer
	score -= studentData.answerSums[INCORR] * .25f;     // Subtract quarter point for incorrect answer

	if (score < 0)           // Score cannot be negative
		score = 0.0;

	studentData.totalScore = score;
}

void Percent(/*inout*/ GradingData& studentData)
// Precondition: score has been calculated, answer data is stored in studentData
// Postcondition: percent has been calculated and stored in studentData
{
	int total = studentData.answerSums[CORRECT] + 
		studentData.answerSums[INCORR] +
		studentData.answerSums[NO_ANS];      // Total number of questions (max score)

	studentData.percent = studentData.totalScore * 100 / total;
}

void PrintTableHeading(ofstream& outData)
// Precondition: output file opened
// Postcondition: table headings have been added to output file
{
	outData << setw(13) << left << "Name" << setw(10) << "Correct" << setw(9) << "Incorr"
		<< setw(9) << "No Ans" << setw(16) << "Total Score" << '%' << endl
		<< "----------   -------   ------   ------   -----------   -----" << endl;
}

void PrintToTable(/*inout*/ ofstream& outData, /*in*/ const GradingData studentData)
// Precondition: all data for the current student has been collected in struct studentData
// Postcondition: current student's data has been added to the output file's table
{
	outData << setw(16) << left << studentData.name << setw(10) 
		<< studentData.answerSums[CORRECT] << setw(9) << studentData.answerSums[INCORR]
		<< setw(9) << studentData.answerSums[NO_ANS] << setw(11) 
		<< studentData.totalScore << setprecision(4) << studentData.percent << endl;
}