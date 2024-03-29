﻿/*
 * Project: Penguin Derby
 * File: PenguinDerby.cpp
 * Author: Daniel Cole
 * Version: 1.0
 * Version Date: 6/24/2019
 *
 * Description: This program simulates a race between 4 different
 * penguins, the first of which the player is controlling. The player
 * is able to choose between die rolls and forcing the penguin to sprint
 * if the penguin has enough stamina. In the end, the winner is determined
 * by which penguin reaches the finish line first. A visual of the race
 * is drawn with symbols every turn.
 * New to version 1.1: Added input validation to avoid input errors.
 */

#include <iostream>
#include <random>
#include <string>
#include "penguin.h"
#include "inVerify.h"
#include <stdlib.h>
#include "race.h"
using namespace std;


int main()
{
	inVerify inputCheck;
	bool again = false;
	do
	{
		int playerNum = -1, computerNum = -1, raceLen = 0;
		cout << "Welcome to the Penguin Derby!" << endl;
		cout << "Here at the derby we host the greatest penguin race you've ever seen!" << endl;
		do // Checking for race length size
		{
			cout << "Enter the length of the race. We recommend 50." << endl;
			cout << "The number cannot be less than 20 or greater than 100: ";
			try
			{
				raceLen = inputCheck.getGoodInt();
			}
			catch(string exceptionStr)
			{
				cout << exceptionStr;
			}
			
			cout << endl;
		} while (raceLen < 20 || raceLen > 100);
		do // prompting player on how many players there are
		{
			cout << "Enter the number of players in the race. You can have " << endl;
			cout << "no more than a total of 8 players and computers: ";
			try
			{
				playerNum = inputCheck.getGoodInt();
			}
			catch (string exceptionStr)
			{
				cout << exceptionStr;
			}
			cout << endl;
		} while (playerNum < 0 || playerNum > 8);
		do // prompting player on how many computers there are
		{
			cout << "Enter the number of computers in the race. You can have " << endl;
			cout << "no more than a total of 8 players and computers: ";
			try
			{
				computerNum = inputCheck.getGoodInt();
			}
			catch (string exceptionStr)
			{
				cout << exceptionStr;
			}
			cout << endl;
		} while (computerNum + playerNum < 1 || computerNum > 8 - playerNum);
		Race penguinRace;
		penguinRace.setRaceLen(raceLen);  // Setting up the race's size
		penguinRace.setNumOfPlayers(playerNum);
		penguinRace.setNumOfComputers(computerNum);
		penguinRace.calcNumOfContestants();
		int count = 0;
		while (count < playerNum) // declaring what each player's penguin is
		{
			cout << "Player " << count + 1 << " your penguin is the " << penguinRace.getColor(count) << " penguin." << endl;
			count++;
		}
		penguinRace.penguinSelection();		// Allowing players to pick their penguins
		penguinRace.computerSelection();	// Having computers pick their penguins
		penguinRace.runRace();				// running the entirety of the race

		char response;
		bool answered = false;
		while (!answered)	// seeing if the players want to go again
		{
			cout << "Would you like to play again? Y/N" << endl;		
			try
			{
				response = inputCheck.getGoodChar();
			}
			catch (string exceptionStr)
			{
				cout << exceptionStr;
			}
			if (response == 'Y' || response == 'y')
			{
				again = true;
				answered = true;
			}
			else if (response == 'N' || response == 'n')
			{
				again = false;
				answered = true;
			}
		}

	} while (again);

    return 0;
}

