/*
* Project: Penguin Derby
* File: race.h
* Author: Daniel Cole
* Version: 1.1
* Version Date: 6/24/2019
*
* Description: This is the header file of the race class, which
* controls the parameters and displaying of the race.
* Version 1.1 added support for inVerify, which gives input validation
*/

#include "penguin.h"
#include <iostream>
using namespace std;

class Race
{
private:
	int raceLen;
	int numOfContestants;
	int numOfPlayers;
	int numOfComputers;
	char colorArray[8] = {'B', 'R', 'G', 'Y', 'P', 'C', 'O', 'W'};		//Need to have a constant color array for reference in the races
	bool finished;
	Penguin *racePenguins;
	inVerify raceInputCheck;

public:
	void operator= (const Race &right);
	Race(const Race &a);
	Race();
	Race(int r, int nC, int nP, int nCom, bool f, Penguin *rP);
	~Race();
	int getRaceLen();
	void setRaceLen(int rL);
	Penguin& getRacePenguin(int penguinNum);
	void setRacePenguin(Penguin model, int penguinNum);
	char getColor(int i);
	int getNumOfPlayers();
	void setNumOfPlayers(int p);
	int getNumOfComputers();
	void setNumOfComputers(int c);
	void calcNumOfContestants();
	int getNumOfContestants();
	void runRace();
	void placementSort();
	void simulateRound();
	bool isFinished();
	void finalResult();
	void drawRace();
	void penguinSelection();
	void computerSelection();
	void promptPlayer(int playerNum);
	void computerTurn(int computerNum);
};