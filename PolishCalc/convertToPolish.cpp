//#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

using namespace std;

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
		/*case '(': 
		case ')': 
		{
			prior=0;
			break;
		}*/
	}
	return prior;
}

charQueue makePolish (char str[])//сделать из строки очередь с польской записью
{
	int len, maxPriority, currentPriority;
	maxPriority=0;
	currentPriority=0;
	len=strlen(str);


	int sizeOfNumber;
	char *tempNumber;
	

	charQueue polish (len+2);
	charStack opers (len+2);
	char tempOper;

	for (int i=0;i<len;i++)
	{		
			if (str[i]=='(')
			{
				opers.push(str[i]);
			}
			//========здесь собака (вроде) БЫЛА зарыта
		if (str[i]==')')
			{				
					while (tempOper!='(')//выталкивать всё, что до входной скобки, в очередь polish
					{	
						tempOper=opers.pop();
						if (tempOper!='(')
						polish.push(tempOper);
					}
					maxPriority=0;
			}
//========================================
		if ( (str[i]>='0')&&(str[i]<='9') )//если встретили цифру, то сразу кладём в очередь
		{
			//if ( (str[i+1]=='+')||(str[i+1]=='-')||(str[i+1]=='/')||(str[i+1]=='*')||(str[i+1]=='(')||(str[i+1]==')') ) 
			if ( !( (str[i+1]=='0')&&(str[i+1]<='9') ) )//если встретили число от 0 до 9  (следующий символ - не цифра)
			{
				polish.push(str[i]);
			}
			else//то есть если число больше 9  ================================================
			{
				if (!( (str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='*')||(str[i]=='(')||(str[i]==')') ))//проверяем на то, что дальше опять будет цифра
				{
					sizeOfNumber=0;
					for (int j=i;!( (str[j]>='0')&&(str[j]<='9') );j++ )
					{
						sizeOfNumber++;
					}
			
					tempNumber = new char[sizeOfNumber+2];//создаём временный массив для числа больше 9;
														  //резервируем место для разделительного символа и символа конца \0
					for (int j=0;j<sizeOfNumber;j++)//заполняем временный массив числом больше 9
					{
						tempNumber[j]=str[i+j];
						tempNumber[sizeOfNumber]='_';
			
					}
					polish.push(*tempNumber);//по идее, здесь в очередь должен зталкиваться массив строк
											 //будет ли это работать, вопрос открытый; ПОКА ЧТО НЕ РАБОТАЕТ
					delete []tempNumber;//очищаем временный массив
					*tempNumber=NULL;//и обнуляем указатель
				}
		   }
		}

		///////////////////== дальше - возня с операторами ==/////////////////////////////////////
		if ( (str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='*') )
			{
				currentPriority=getPriority(str[i]);
				if (currentPriority>=maxPriority)
				{
					opers.push(str[i]);
					tempOper=str[i];
					maxPriority=currentPriority;
				}
				else//т.е currentPriority<maxPriority
				{
					tempOper=opers.pop();
					polish.push(tempOper);
					opers.push(str[i]);
					maxPriority=getPriority(str[i]);
				}
			}

	}
	while ( !opers.isEmpty() )//пока стек операторов не пуст
	{
		polish.push(opers.pop());//выталкивать всё оставшееся в очередь polish
	}
		return polish;
}

void show(charQueue Polish)
{
	char temp;
	do
	{
		temp=Polish.pop();
		cout<<temp;
	}
	while (!Polish.isEmpty() );
}

//==================================================
//=========НЕРАБОЧЕЕ=============================
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