/*
* Project: Penguin Derby
* File: penguin.cpp
* Author: Daniel Cole
* Version: 1.0
* Version Date: 5/15/2019
*
* Description: This is the implementation file of the penguin class.
*/

#include "penguin.h"

void Penguin::operator= (const Penguin &right)
{
	this->stamina = right.stamina;
	this->place = right.place;
	this->speed = right.speed;
	this->distanceRan = right.distanceRan;
	this->color = right.color;
}

Penguin::Penguin(const Penguin& a)
{
	this->stamina = a.stamina;
	this->place = a.place;
	this->speed = a.speed;
	this->distanceRan = a.distanceRan;
	this->color = a.color;
}

Penguin::Penguin()
{
	stamina = 3;
	place = 0;
	speed = 6;
	distanceRan = 0;
	color = 'Y';
}

Penguin::Penguin(int sta, int loc, int spd, int dis, char col)
{
	this->stamina = sta;
	this->place = loc;
	this->speed = spd;
	this->distanceRan = dis;
	this->color = col;
}

int Penguin::sprint()
{
	stamina = stamina - 1;
	distanceRan = distanceRan + speed;
	return speed;
}

int Penguin::moveRoll()
{
	int numRolled;
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> roll(1, speed);

	numRolled = roll(generator);
	distanceRan = distanceRan + numRolled;
	return numRolled;

}

int Penguin::getStamina()
{
	return stamina;
}

void Penguin::setStamina(int s)
{
	this->stamina = s;
}


int Penguin::getSpeed()
{
	return speed;
}

void Penguin::setSpeed(int s)
{
	this->speed = s;
}

int Penguin::getPlace()
{
	return place;
}

void Penguin::setPlace(int p)
{
	this->place = p;
}

int Penguin::getDistanceRan()
{
	return distanceRan;
}

void Penguin::setDistanceRan(int d)
{
	distanceRan = d;
}

char Penguin::getColor()
{
	return color;
}

void Penguin::setColor(char c)
{
	this->color = c;
}

bool Penguin::shouldSprint(int contestantNum, int raceLen)
{
	bool sprint = false;
	if (place == contestantNum && stamina > 0)
	{
		sprint = true;
	}
	else if (raceLen - distanceRan < speed + 3 && stamina > 0)
	{
		sprint = true;
	}
	return sprint;
}

