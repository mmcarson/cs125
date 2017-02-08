//******************************************************************
// CS-125 HW5
// Marissa Carson
// This program takes a table with the data for a baseball team's
// player stats and uses a table with the data for the most recent
// game to create a new, updated set of player data.
//******************************************************************

#include "hw5_list.h"
// header file includes definition of struct PlayerType and class List

 
void GetPlayers( /* inout */ List& players );
void UpdatePlayers( /* inout */ List& players, /* out */ string& date );
void PrintPlayers( /* in */ List players, /* in */ string date );

int main()
{
    List players;
	string date;
 
    // Get initial player data from a file and load into List of players
	GetPlayers( players );
 
    // Get game data from a file and update List of players
	UpdatePlayers( players, date );
  
    // Sort List of players by batting average (high to low)
	players.SelSort();

	//date = "Jun 10, 2012";

    // Output updated List of players
	PrintPlayers( players, date );
 
	return 0;
}


//******************************************************************
void GetPlayers( /* inout */ List& players )
// Precondition:  there is an empty list
// Postcondition: the list has player data
{
	ifstream playerData;
	playerData.open("hw5_1.in");        // open input file

	PlayerType player;
	
	int wordCount = 0;
	string word;
	while (wordCount < 4)
	{
		playerData >> word;
		wordCount++;
	}                         // go 4 words into the file

	int numberOfPlayers;
	playerData >> numberOfPlayers;   // 5th word is # of players

	while (wordCount < 21)
	{
		playerData >> word;
		wordCount++;
	}                      // go 16 words into file

	players.Reset();     // go to beginning of list

	for (int index=0; index < numberOfPlayers; index++)
	{
		playerData >> player.name >> player.atBats 
			>> player.hits >> player.battingAvg;
		players.Insert(player);      // input each player into the list
	}
	
}
//******************************************************************
void UpdatePlayers( /* inout */ List& players, /* out */ string& date )
// Precondition:  player data from first input file has been stored in a list
// Postcondition: player data has been updated to include the data from this 
//                most recent game, whose date is also recorded as a string
{
	ifstream gameData;
	gameData.open("hw5_2.in");        // open input file

	int wordCount = 0;
	string word;
	while (wordCount < 4)
	{
		gameData >> word;
		wordCount++;
	}                         // go 4 words into the file

	int numberOfPlayers;
	gameData >> numberOfPlayers;   // 5th word is # of players

	while (wordCount < 6)
	{
		gameData >> word;
		wordCount++;
	}                         // go 2 words into the file

	gameData >> date;         // next word is the month
	wordCount++;

	while (wordCount < 9)
	{
		gameData >> word;
		date = date + ' ' + word;
		wordCount++;
	}                         // add day and year to date

	while (wordCount < 17)
	{
		gameData >> word;
		wordCount++;
	}                         // go 8 words into the file

	players.Reset();
	PlayerType player;                     // temporary player variable
	for (int i=0; i<numberOfPlayers; i++)
	{
		gameData >> player.name >> player.atBats >> player.hits;
		if (players.IsPresent(player))         // If player is already in the list, 
			players.UpdatePlayer(player);     // update their information. 
		else                                 // Otherwise add them
		{                                   // to the list.
			player.battingAvg = float(player.hits) / player.atBats;
			players.Insert(player);
		}
	}
}
//******************************************************************
void PrintPlayers( /* in */ List players, /* in */ string date )
// Precondition:  players have been updated and the date has been recorded
//                from the second input file
// Postcondition: player data has been output to file, "as of" the date of
//                the game in the second input file
{
	ofstream outData;
	outData.open("hw5.out");

	outData << "===================================================" << endl;
	outData << "Batting Statistics for " << players.Length() 
			<< " Players as of " << date << endl;
	outData << "===================================================" << endl;
	outData << "Name              At Bats   Hits   Batting Avg" << endl;
	outData << "---------------   -------   ----   -----------" << endl;

	players.Reset();

	for (int i=0; i<players.Length(); i++)
	{
		PlayerType player = players.GetNextItem();
		outData << left << setw(21) << player.name << setw(9)
			<< player.atBats << setw(8) << player.hits;
		if (player.battingAvg < 0.1)
			outData.precision(2);      // Because Terry can't bat and so his batting average is
		else                          // below 0.1 which tacked on an extra digit at the end and
			outData.precision(3);    // messed up the whole table
		outData << showpoint << player.battingAvg << endl;
	}
}
