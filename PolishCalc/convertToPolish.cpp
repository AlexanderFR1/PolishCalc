//#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

using namespace std;

int getPriority (string oper)//������� �����������
{
	int prior;
	char operT;
	operT = oper[0];
	switch (operT)
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

charQueue makePolish (char str[])//������� �� ������ ������� � �������� �������
{
	int len, maxPriority, currentPriority;
	maxPriority=0;
	currentPriority=0;
	len=strlen(str);


	int sizeOfNumber;
	
	

	charQueue polish (len+2);
	charStack opers (len+2);
	char tempOper;

	for (int i=0;i<len;i++)
	{		
			if (str[i]=='(')
			{
				//string *temp;
				//temp=new string[1];
				//temp[0]=str[i];
				//opers.push(*temp);
				string s = "";
				s+=str[i];
				opers.push(s);
			}
			//========����� ������ (�����) ���� ������
		if (str[i]==')')
			{				
					while (tempOper!='(')//����������� ��, ��� �� ������� ������, � ������� polish
					{	//char *temp;
						//temp=new char[1];
						string temp;
						temp=opers.pop();
						if (tempOper!='(')
						polish.push(temp);
					}
					maxPriority=0;
			}
//========================================
		if ( (str[i]>='0')&&(str[i]<='9') )//���� ��������� �����, �� ����� ����� � �������
		{
			//if ( (str[i+1]=='+')||(str[i+1]=='-')||(str[i+1]=='/')||(str[i+1]=='*')||(str[i+1]=='(')||(str[i+1]==')') ) 
			if ( !( (str[i+1]=='0')&&(str[i+1]<='9') ) )//���� ��������� ����� �� 0 �� 9  (��������� ������ - �� �����)
			{
				//char *temp;
				//temp=new char[1];
				string temp;
				temp=str[i];
				opers.push(temp);
			}
			else//�� ���� ���� ����� ������ 9  ================================================
			{
				if (!( (str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='*')||(str[i]=='(')||(str[i]==')') ))//��������� �� ��, ��� ������ ����� ����� �����
				{
					string *tempNumber;
					sizeOfNumber=0;
					for (int j=i;!( (str[j]>='0')&&(str[j]<='9') );j++ )
					{
						sizeOfNumber++;
					}			
					tempNumber = new string [sizeOfNumber];//������ ��������� ������ ��� ����� ������ 9;
					for (int j=0;j<sizeOfNumber;j++)//��������� ��������� ������ ������ ������ 9
					{
						tempNumber[j]=str[i+j];		
					}
					polish.push(tempNumber);//�� ����, ����� � ������� ������ ������������ ������ ����� � ���� string
											 //����� �� ��� ��������, ������ ��������; ���� ��� �� ��������
					delete []tempNumber;//������� ��������� ������
					//*tempNumber=NULL;//� �������� ���������
				}
		   }
		}

		///////////////////== ������ - ����� � ����������� ==/////////////////////////////////////
		if ( (str[i]=='+')||(str[i]=='-')||(str[i]=='/')||(str[i]=='*') )
			{
				currentPriority=getPriority(str[i]);
				if (currentPriority>=maxPriority)
				{
					string s = "";
					s += str[i];
					opers.push(s);
					tempOper=str[i];
					maxPriority=currentPriority;
				}
				else//�.� currentPriority<maxPriority
				{
					char *temp;
					temp=new char[1];
					temp[0]=str[i];
					*temp=opers.pop();
					polish.push(temp);
					opers.push(*temp);
					maxPriority=getPriority(str[i]);
				}
			}

	}
	while ( !opers.isEmpty() )//���� ���� ���������� �� ����
	{
		polish.push(opers.pop());//����������� �� ���������� � ������� polish
	}
		return polish;
}

void show(charQueue Polish)
{
	char temp;
	do
	{
		temp=Polish.pop();
		cout<<temp<<' ';
	}
	while (!Polish.isEmpty() );
}

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