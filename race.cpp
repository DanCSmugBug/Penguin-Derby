/*
* Project: Penguin Derby
* File: race.h
* Author: Daniel Cole
* Version: 1.1
* Version Date: 6/24/2019
*
* Description: This is the header file of the race class, which
* controls the parameters and displaying of the race.
* Version 1.1 added support for inVerify, implemented in the functions
* penguinSelection and promptPlayer
*/

#include "race.h"

void Race::operator= (const Race &right)
{
	this->raceLen = right.raceLen;
	this->numOfContestants = right.numOfContestants;
	this->numOfPlayers = right.numOfPlayers;
	this->numOfComputers = right.numOfComputers;
	this->finished = right.finished;
	this->racePenguins = right.racePenguins;
}

Race::Race(const Race &a)
{
	this->raceLen = a.raceLen;
	this->numOfContestants = a.numOfContestants;
	this->numOfPlayers = a.numOfPlayers;
	this->numOfComputers = a.numOfComputers;
	this->finished = a.finished;
	this->racePenguins = a.racePenguins;
	int counter = 0;	//correcting whatever colors are in penguins to what the race expects
	while (counter < numOfContestants)
	{
		racePenguins[counter].setColor(colorArray[counter]);
		counter++;
	}
}

Race::Race()
{
	raceLen = 50;
	numOfContestants = 4;
	numOfPlayers = 1;
	numOfComputers = 3;
	finished = false;
	racePenguins = new Penguin[numOfContestants];
	int counter = 0;
	while (counter < numOfContestants)
	{
		racePenguins[counter].setColor(colorArray[counter]);
		counter++;
	}
}

Race::Race(int r, int nC, int nP, int nCom, bool f, Penguin *rP)
{
	this->raceLen = r;
	this->numOfContestants = nC;
	this->numOfPlayers = nP;
	this->numOfComputers = nCom;
	this->finished = f;
	this->racePenguins = rP;
	int counter = 0;	//correcting whatever colors are in penguins to what the race expects
	while (counter < numOfContestants)
	{
		racePenguins[counter].setColor(colorArray[counter]);
		counter++;
	}
}

Race::~Race()
{
	delete[] racePenguins;
}

int Race::getRaceLen()
{
	return raceLen;
}

void Race::setRaceLen(int rL)
{
	this->raceLen = rL;
}

Penguin& Race::getRacePenguin(int penguinNum)
{
	return racePenguins[penguinNum];
}

void Race::setRacePenguin(Penguin model, int penguinNum)
{
	this->racePenguins[penguinNum] = model;
}

char Race::getColor(int i)
{
	return colorArray[i];
}

int Race::getNumOfPlayers()
{
	return numOfPlayers;
}

void Race::setNumOfPlayers(int p)
{
	this->numOfPlayers = p;
}

int Race::getNumOfComputers()
{
	return numOfComputers;
}

void Race::setNumOfComputers(int c)
{
	this->numOfComputers = c;
}

void Race::calcNumOfContestants()
{
	numOfContestants = numOfPlayers + numOfComputers;
	delete[]racePenguins; // Creating a new array of penguins based on current number
	racePenguins = new Penguin[numOfContestants];
	int counter = 0;
	while (counter < numOfContestants)
	{
		racePenguins[counter].setColor(colorArray[counter]); // setting char for each penguin
		counter++;
	}
}

int Race::getNumOfContestants()
{
	return numOfContestants;
}

void Race::runRace()
{
	drawRace();
	while (!finished)
	{
		simulateRound();
		isFinished();
	}
	finalResult();
}

void Race::placementSort()
{
	int counter = 0;
	while (counter < numOfContestants)
	{
		int numberAhead = 0;
		for (int i = 0; i < numOfContestants; i++)  // Iterate through all penguins and see how many it is tied with
		{  // or beating (including itself)
			if (racePenguins[counter].getDistanceRan() >= racePenguins[i].getDistanceRan())
			{
				numberAhead++;
			}
		}
		racePenguins[counter].setPlace(numOfContestants - (numberAhead - 1)); // the -1 accounts for itself
		counter++; // onto next penguin
	}
}

void Race::simulateRound()
{
	int counter = 0;
	while (counter < numOfPlayers)	//Determine what players will do
	{
		promptPlayer(counter);
		counter++;
	}
	while (counter < numOfContestants) //Determine what computers will do
	{
		computerTurn(counter);
		counter++;
	}
	placementSort();
	drawRace();
}

bool Race::isFinished()
{
	int counter = 0;
	while (counter < numOfContestants)
	{ // If a penguin has crossed the finish line (which is at the raceLen distance) then the race is over
		if (racePenguins[counter].getDistanceRan() >= raceLen)
		{
			finished = true;
		}
		counter++;
	}
	return finished;
}

void Race::finalResult()
{
	cout << "The race is over!" << endl;
	int counter = 0;
	int placement = 1;
	while (counter < numOfContestants)
	{
		for (int i = 0; i < numOfContestants; i++)
		{
			if (racePenguins[i].getPlace() == placement)
			{
				cout << "Penguin " << i + 1 << " takes " << placement;
				if (placement == 1)
				{
					cout << "st ";
				}
				else if (placement == 2)
				{
					cout << "nd ";
				}
				else if (placement == 3)
				{
					cout << "rd ";
				}
				else
				{
					cout << "th ";
				}
				cout << "place." << endl;
			}
		}
		placement++;
		counter++;
	}
}
void Race::computerSelection()	// Function to randomly generate penguin selections for some variety
{
	int comCount = 0;
	while (comCount < numOfComputers)	// while loop will cycle through all computer penguins
	{
		int currentCom = comCount + numOfPlayers;	// setting the current index for the penguin array
		int numRolled;
		random_device rd;		//randomly generating penguin selection for penguin using <random> library
		mt19937 generator(rd());
		uniform_int_distribution<int> roll(1, 5);

		numRolled = roll(generator);
		if (numRolled == 4)		// 4 is for the Bowler, setting stats and announcing result
		{
			racePenguins[currentCom].setSpeed(5);
			racePenguins[currentCom].setStamina(6);
			cout << "Rival penguin " << currentCom + 1 << " is a Bowler penguin." << endl;
		}
		else if (numRolled == 5)	// 5 is for the Stretchy, setting stats and announcing result
		{
			racePenguins[currentCom].setSpeed(7);
			racePenguins[currentCom].setStamina(1);
			cout << "Rival penguin " << currentCom + 1 << " is a Stretchy penguin." << endl;
		}
		else
		{
			cout << "Rival penguin " << currentCom + 1 << " is a Noodle penguin." << endl;
		}	// no code necessary to set penguins to default. Around 60% of penguins should be default
		comCount++;
	}
}

void Race::drawRace()	//This function draws the visual representation of the race.
{
	int pengCounter = 0;
	cout << endl;
	while (pengCounter != numOfContestants)	//While loop draws each penguin's lane.
	{
		int steps = 0;
		while (steps < racePenguins[pengCounter].getDistanceRan())	//While loop draws steps traveled
		{
			cout << "=";
			steps++;
		}
		cout << racePenguins[pengCounter].getColor();	//drawing the penguin themself
		int remaining = raceLen - racePenguins[pengCounter].getDistanceRan() - 2;  //subtract 2 to account for 
		// the drawing of both the distance traveled and the piece itself
		int count = 0;
		while (count <= remaining)		//While loop drawing remaining steps
		{
			cout << "-";
			count++;
		}
		if (steps < raceLen)
		{
			cout << "|-";	//If the finish line has not been passed it needs to be drawn
		}
		cout << endl;
		pengCounter++;
	}
}
void Race::penguinSelection()
{
	int players = 0;
	while (players < numOfPlayers)
	{
		int choice = 0;
		bool done = false;
		cout << "Player " << players + 1 << ", it is your time to pick." << endl;
		cout << "You have three different Penguin breeds to pick from: " << endl;
		cout << "The Noodle Penguin has a speed die of 6 and a stamina of 3." << endl;
		cout << "The Bowler Penguin has a speed die of 5 and a stamina of 6." << endl;
		cout << "The Stretchy Penguin has a speed die of 7 and a stamina of 1." << endl;
		do
		{			//This loop doesn't exit until a valid choice is placed for penguin
			cout << "Type 1 for Noodle, 2 for Bowler, and 3 for Stretchy." << endl;
			cout << "Please make your choice: ";
			try
			{
				choice = raceInputCheck.getGoodInt();
			}
			catch (string exceptionStr)
			{
				cout << exceptionStr;
			}
			if (choice < 4 && choice > 0)
			{
				done = true;
			}
		} while (!done);
		if (choice == 2)		// Setting stats for Bowler penguin choice
		{
			racePenguins[players].setSpeed(5);
			racePenguins[players].setStamina(6);
		}
		else if (choice == 3)		// Setting stats for Stretchy penguin choice
		{
			racePenguins[players].setSpeed(7);
			racePenguins[players].setStamina(1);
		}			// Unnecessary to make case for Noodle Penguin, as it is the default
		players++;	//onto the next player
		cout << endl;
	}

}

void Race::promptPlayer(int playerNum)
{
	int distanceLeft = raceLen - racePenguins[playerNum].getDistanceRan();
	int playerDecision = 0;
	int playerRun = 0;
	bool done = false;
	cout << "Player " << playerNum + 1 << ", what will you do this turn?" << endl;
	cout << "Your penguin is currently " << distanceLeft << " feet from the finish line." << endl;
	cout << "Your penguin currently has " << racePenguins[playerNum].getStamina() << " stamina left." << endl;
	while (!done)
	{
		cout << "Enter 1 to roll your die or 2 to sprint: ";
		try
		{
			playerDecision = raceInputCheck.getGoodInt();
		}
		catch (string exceptionStr)
		{
			cout << exceptionStr;
		}
		if (playerDecision == 2 || playerDecision == 1)
		{
			done = true;
		}
	}
	if (playerDecision == 2)
	{
		playerRun = racePenguins[playerNum].sprint();
		cout << "You will move " << playerRun << " feet." << endl;
	}
	else
	{
		playerRun = racePenguins[playerNum].moveRoll();
		cout << "You will move " << playerRun << " feet." << endl;
	}
	cout << endl;
}

void Race::computerTurn(int computerNum)
{
	int computerMove = 0;
	bool willSprint;
	willSprint = racePenguins[computerNum].shouldSprint(numOfContestants, raceLen);
	if (willSprint)
	{
		cout << "Rival Penguin " << computerNum + 1 << " has decided to sprint." << endl;
		computerMove = racePenguins[computerNum].sprint();
		cout << "They will move " << computerMove << " feet." << endl;
	}
	else
	{
		cout << "Rival Penguin " << computerNum + 1 << " has decided to roll." << endl;
		computerMove = racePenguins[computerNum].moveRoll();
		cout << "They will move " << computerMove << " feet." << endl;
	}
}