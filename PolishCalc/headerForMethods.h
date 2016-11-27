//#pragma once
#include "charQueue.h"
#include "charStack.h"
#include "floatResult.h"
#include <string.h>

bool isStringCorrect( char str []);
charQueue makePolish (char str[]);
int getPriority (char oper);
float calculate(charQueue Polish);
void show(charQueue Polish);
char makeNumberChar(char strT[], int startIndex);
//bool isLittleNumber (char strT[], int startIndex);
//int makeNumber(char 