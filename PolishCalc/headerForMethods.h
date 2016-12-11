//#pragma once
#include "charQueue.h"
#include "charStack.h"
#include "floatResult.h"
#include <string.h>

bool isStringCorrect( string str );
//extern "C" 
	charQueue makePolish (string str);
int getPriority (char oper);
//extern "C" 
	float calculate(charQueue Polish);
void show(charQueue Polish);
//char makeNumberChar(char strT[], int startIndex);
//bool isLittleNumber (char strT[], int startIndex);
//int makeNumber(char 