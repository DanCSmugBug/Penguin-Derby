/*
* Project: Penguin Derby
* File: penguin.h
* Author: Daniel Cole
* Version: 1.1
* Version Date: 5/15/2019
*
* Description: This is the header file of the penguin class.
*/
#pragma once
#include <string>
#include <random>
#include "inVerify.h"
using namespace std;

class Penguin
{
private:
	int stamina;
	int place;
	int speed;
	int distanceRan;
	char color;

public:
	void operator= (const Penguin &right);
	Penguin(const Penguin& a);
	Penguin();
	Penguin(int sta, int loc, int spd, int dis, char col);
	int sprint();
	int moveRoll();
	int getStamina();
	void setStamina(int s);
	int getSpeed();
	void setSpeed(int s);
	int getPlace();
	void setPlace(int p);
	int getDistanceRan();
	void setDistanceRan(int d);
	char getColor();
	void setColor(char c);
	bool shouldSprint(int contestantNum, int raceLen);

};