/*
* Project: Penguin Derby
* File: inVerify.cpp
* Author: Daniel Cole
* Version: 1.0
* Version Date: 6/24/2019
*
* Description: Implementation file for inVerify
*/
#include "inVerify.h"

// function for returning legitamite integers
int inVerify::getGoodInt()
{
	int value;
	cin >> value;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw string("ERROR: BAD INPUT \n");
	}
	else
	{
		return value;
	}
}

// function for returning legitamite strings
string inVerify::getGoodStr()
{
	string word;
	cin >> word;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw string("ERROR: BAD INPUT \n");
	}
	else
	{
		return word;
	}
}

// function for returning legitamite characters
char inVerify::getGoodChar()
{
	char letter;
	cin >> letter;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw string("ERROR: BAD INPUT \n");
	}
	else
	{
		return letter;
	}
}