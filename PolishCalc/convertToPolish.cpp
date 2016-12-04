#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

using namespace std;

int getPriority (char oper)//таблица приоритетов
{
	int prior;
//	char operT;
	//operT = oper[0];
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
	}
	return prior;
}

charQueue makePolish (string str)//сделать из строки очередь с польской записью
{
	int len, maxPriority, currentPriority;
	maxPriority=0;
	currentPriority=0;
	len=str.length();


	int sizeOfNumber;//размерность числа, бќльшего дев€ти
	int incCount;
	
	

	charQueue polish (len+2);
	charStack opers (len+2);
	std::string tempOper;
	tempOper="";
	for (int i=0;i<len;i++)
	{		
			if (str[i]=='(')
			{
				std::string s;
				s="(";
				opers.push(s);

			}
			//========здесь собака зарыта=========================================================
		if (str[i]==')')
			{				
					while (tempOper[0]!='(')//выталкивать всЄ, что до входной скобки, в очередь polish
					{	
						tempOper=opers.pop();
						if (tempOper[0]!='(')
						{
							polish.push(tempOper);
						}
					}
					maxPriority=0;
			}
//========================================
		if ( (str[i]>='0')&&(str[i]<='9') )//если встретили цифру, то
		{
			if ( ( (str[i+1]<'0')||(str[i+1]>'9') ) )//если встретили число от 0 до 9  (следующий символ - не цифра)
			{
				string temp;
				temp=str[i];
				polish.push(temp);
			}
			else//то есть если число больше 9  ================================================
			{
				{
					incCount=0;
					std::string tempNumber;
					sizeOfNumber=0;
					for (int j=i;( (str[j]>='0')&&(str[j]<='9') );j++ )
					{
						sizeOfNumber++;
					}			
					for (int g=0;g<sizeOfNumber;g++)//заполн€ем временный массив числом больше 9
					{
						tempNumber+=str[i+g];
						incCount++;
					}
					polish.push(tempNumber);//по идее, здесь в очередь должен зталкиватьс€ массив строк в виде string
					i=i+incCount-1;
				}
		   }
		}

		///////////////////== дальше - возн€ с операторами ==/////////////////////////////////////
		if ( (str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='*') )
			{
				currentPriority=getPriority(str[i]);
				if (currentPriority>=maxPriority)
				{
					string s;
					s = str[i];
					opers.push(s);
					//tempOper=str[i];
					maxPriority=currentPriority;
				}
				else//т.е currentPriority<maxPriority
				{
					string temp;					
					temp=opers.pop();
					polish.push(temp);
					temp=str[i];
					opers.push(temp);
					maxPriority=getPriority(str[i]);
				}
			}

	}
	while ( !opers.isEmpty() )//пока стек операторов не пуст
	{
		string tempLast;
		tempLast=opers.pop();
		if (tempLast[0]!='(')
		{
			polish.push(tempLast);//выталкивать всЄ оставшеес€ в очередь polish
		}
	}
		return polish;
}

void show(charQueue Polish)
{
	string temp;
	do
	{
		temp=Polish.pop();
		cout<<temp<<' ';
	}
	while (!Polish.isEmpty() );
}
//======================================================================================================================================================
//======================================================================================================================================================
//==================================================
//=========Ќ≈–јЅќ„≈≈=============================
//================================================
char makeNumberChar(char strT[], int startIndex )
{
	char *temp;
	int size; 	//в size лежит размерность числа
	size=0;
	for (int i=startIndex;( (strT[i]!='+')||(strT[i]!='-')||(strT[i]!='/')||(strT[i]!='*')||( strT[i]!='\0') );i++)
	{
		size++;
	}
	//size++;
	temp = new char [size+1];
	for (int i=startIndex;i<startIndex+size;i++)
	{
		temp[i-startIndex]=strT[i];//записываем в массив число
	}
	temp [size-1]='D';
	return *temp;
}