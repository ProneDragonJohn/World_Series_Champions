/******************************************************************
* John Velazquez
* October 1st, 2019
* Programming Fundamentals II - Fall 2019
*******************************************************************
* World Series Champions - This program uses two files:
*
* This program displays the contents of the Teams.txt file on the
* screen and prompts the user to enter the name of one of the teams.
* The program then displays the number of times that team has won
* the World Series in the time period from 1903 to 2012.
*******************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

void displayMenu();
void processMenu();
void getTeams(vector<string> &);
void getWinners(vector<string> &);
void displayNumWins(const vector<string>, const vector<string>);

int main()
{
	displayMenu();
	processMenu();

	return 0;
}

/**********************************************************************
** displayMenu()
***********************************************************************
** Displays a 2 choice menu. Prompts the user to enter 1 to list the
** teams or 2 to exit the program
***********************************************************************/
void displayMenu()
{
	cout << "MLB - WORLD SERIES WINNER DATABASE\n\n"
		<< "1. List Teams\n"
		<< "2. Exit Program\n\n"
		<< "Your choice: ";
}

/**********************************************************************
** processMenu()
***********************************************************************
** Processes the menu choice inputted by the user
***********************************************************************/
void processMenu() //Process the menu choice inputted by the user
{
	const int ROSTER = 1,
		QUIT = 2;

	int choice = 0;

	vector<string> teams = { " " };
	vector<string> winners = { " " };

	do
	{
		cin >> (choice);

		switch(choice)
		{
			case 1:
				winners.clear();
				teams.clear();
				getTeams(teams);
				getWinners(winners);
				displayNumWins(winners, teams);
				displayMenu();
				break;

			case 2:
				if (choice == QUIT)
				{
					cout << "Goodbye!\n";
				}
				break;
		}
	}while(choice != QUIT);
}

/**********************************************************************
** getTeams(vector<string> &teams)
***********************************************************************
** Checks for the Teams.txt file and opens the file if it is available
** Then reads each line into a string and pushes that string onto a 
** vector 
***********************************************************************/
void getTeams(vector<string> &teams) 
{
	teams.clear();

	ifstream teamsFile;
	string teamRoster = " ";

	teamsFile.open("Teams.txt");

	if(teamsFile)
	{
		while (getline(teamsFile, teamRoster) && !teamsFile.eof())
		{
			teams.push_back(teamRoster);
		}
	}
	else
	{
		cout << "\nFile open error: The file 'Teams.txt' could not be opened or processed. Please make sure that the filename is correct and the file is not damaged or has been moved from the program folder.\n\n";
	}

	teamsFile.close();
}

/**********************************************************************
** getWinners(vector<string> &winners)
***********************************************************************
** Checks for the WorldSeriesWinners.txt file and opens the file if it 
** is available. Then reads each line into a string and pushes that 
** string onto a vector
***********************************************************************/
void getWinners(vector<string> &winners)
{
	ifstream winnersFile;

	string winningRoster = " ";

	winnersFile.open("WorldSeriesWinners.txt");

	if (winnersFile)
	{
		while (getline(winnersFile, winningRoster) && !winnersFile.eof())
		{
			winners.push_back(winningRoster);
		}
	}
	else
	{
		cout << "\nFile open error: The file 'WorldSeriesWinners.txt' could not be opened or processed. Please make sure that the filename is correct and the file is not damaged or has been moved from the program folder.\n\n";
	}

	winnersFile.close();
}

/***************************************************************************
** displayNumWins(const vector<string> winners, const vector<string> teams)
****************************************************************************
** Displays the teams from the teams vectors and prompts the user to enter 
** a team name and moves through the winners vector counting the amount of
** times the entered team name is found. (Case sensitive)
****************************************************************************/
void displayNumWins(const vector<string> winners, const vector<string> teams)
{
	string teamName = " ";
	int count = 0;

	cout << "\n\n";

	for(string v : teams)
	{
		cout << v << "\n";
	}

	cout << "\nEnter a team name: ";
	cin.get();
	getline(cin, teamName);

	for(size_t n = 0; n < winners.size(); n++)
	{
		if (teamName == winners[n])
		{
			count++;
		}
	}

	cout << "\nThe " << teamName << " have won the Major League Baseball World Series " << count << " times!\n\n";
}