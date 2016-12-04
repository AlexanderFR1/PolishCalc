#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

using namespace std;

int getPriority (char oper)//������� �����������
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

charQueue makePolish (string str)//������� �� ������ ������� � �������� �������
{
	int len, maxPriority, currentPriority;
	maxPriority=0;
	currentPriority=0;
	len=str.length();


	int sizeOfNumber;//����������� �����, �������� ������
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
			//========����� ������ ������=========================================================
		if (str[i]==')')
			{				
					while (tempOper[0]!='(')//����������� ��, ��� �� ������� ������, � ������� polish
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
		if ( (str[i]>='0')&&(str[i]<='9') )//���� ��������� �����, ��
		{
			if ( ( (str[i+1]<'0')||(str[i+1]>'9') ) )//���� ��������� ����� �� 0 �� 9  (��������� ������ - �� �����)
			{
				string temp;
				temp=str[i];
				polish.push(temp);
			}
			else//�� ���� ���� ����� ������ 9  ================================================
			{
				{
					incCount=0;
					std::string tempNumber;
					sizeOfNumber=0;
					for (int j=i;( (str[j]>='0')&&(str[j]<='9') );j++ )
					{
						sizeOfNumber++;
					}			
					for (int g=0;g<sizeOfNumber;g++)//��������� ��������� ������ ������ ������ 9
					{
						tempNumber+=str[i+g];
						incCount++;
					}
					polish.push(tempNumber);//�� ����, ����� � ������� ������ ������������ ������ ����� � ���� string
					i=i+incCount-1;
				}
		   }
		}

		///////////////////== ������ - ����� � ����������� ==/////////////////////////////////////
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
				else//�.� currentPriority<maxPriority
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
	while ( !opers.isEmpty() )//���� ���� ���������� �� ����
	{
		string tempLast;
		tempLast=opers.pop();
		if (tempLast[0]!='(')
		{
			polish.push(tempLast);//����������� �� ���������� � ������� polish
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
//=========���������=============================
//================================================
char makeNumberChar(char strT[], int startIndex )
{
	char *temp;
	int size; 	//� size ����� ����������� �����
	size=0;
	for (int i=startIndex;( (strT[i]!='+')||(strT[i]!='-')||(strT[i]!='/')||(strT[i]!='*')||( strT[i]!='\0') );i++)
	{
		size++;
	}
	//size++;
	temp = new char [size+1];
	for (int i=startIndex;i<startIndex+size;i++)
	{
		temp[i-startIndex]=strT[i];//���������� � ������ �����
	}
	temp [size-1]='D';
	return *temp;
}