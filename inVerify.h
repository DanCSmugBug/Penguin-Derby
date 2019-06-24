#pragma once

/*
* Project: Penguin Derby
* File: inVerify.h
* Author: Daniel Cole
* Version: 1.0
* Version Date: 6/24/2019
*
* Description: inVerify, or Input Verification, is a class designed to be
* called upon to handle inputsand throw exceptions when errors occur.
* It is a broad class with only a few functions designed to simplify code. 
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class inVerify
{
private:
public:
	int getGoodInt();
	string getGoodStr();
	char getGoodChar();
};