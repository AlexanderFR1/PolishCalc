#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

int getPriority (char oper)//таблица приоритетов
{
	int prior;
	switch (oper)
	{
		case '+': 
		case '-': 
		{
			prior=1;
			break;
		}
		case '/': 
		case '*': 
		{
			prior=2;
			break;
		}
		case '(': 
		case ')': 
		{
			prior=0;
			break;
		}
	}
	return prior;
}

charQueue makePolish (char str[])//сделать из строки очередь с польской записью
{
	int len, maxPriority, currentPriority;
	maxPriority=0;
	currentPriority=0;
	len=strlen(str);
	

	charQueue polish (len);
	charStack opers (len);
	char tempOper;

	for (int i=0;i<len;i++)
	{
		if ( (str[i]>='0')&&(str[i]<='9') )//если встретили цифру, то сразу кладём в очередь
		{
			polish.push(str[i]);
		}
		else//а если оператор
		{
			if (str[i]=='(')
			{
				opers.push(str[i]);
			}
			if (str[i]==')')
			{
				{
					do//выталкивать всё, что до входной скобки, в очередь polish
					{
					
						tempOper=opers.pop();
						polish.push(tempOper);
					}
					while (tempOper!='(');
					opers.delTopEl();//удалить входную скобку
				}
			}
			else
			{
				//а если + - / * то
				currentPriority=getPriority(str[i]);
				if (currentPriority>maxPriority)
				{				
					opers.push(str[i]);
					maxPriority=currentPriority;
				}
				else//т.е currentPriority<=maxPriority
				{
					tempOper=opers.pop();
					polish.push(tempOper);
					opers.push(str[i]);
					maxPriority=getPriority(str[i]);
				}
			}
		}
		while( opers.isEmpty() )//пока стек операторов не пуст
			{
				polish.push (opers.pop() );//выталкивать всё оставшееся в очередь polish
			}
	}
	return polish;
}