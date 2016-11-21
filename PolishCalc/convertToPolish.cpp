#pragma once
#include <string>
#include <iostream>
/*#include "charQueue.h"
#include "charStack.h"*/
#include "headerForMethods.h"

int getPriority (char oper)//������� �����������
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

charQueue makePolish (char str[])//������� �� ������ ������� � �������� �������
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
		if ( (str[i]>='0')&&(str[i]<='9') )//���� ��������� �����, �� ����� ����� � �������
		{
			polish.push(str[i]);
		}
		else//� ���� ��������
		{
			if (str[i]=='(')
			{
				opers.push(str[i]);
			}
			if (str[i]==')')
			{
				{
					do//����������� ��, ��� �� ������� ������, � ������� polish
					{
					
						tempOper=opers.pop();
						polish.push(tempOper);
					}
					while (tempOper!='(');
					opers.delTopEl();//������� ������� ������
				}
			}
			else
			{
				//� ���� + - / * ��
				currentPriority=getPriority(str[i]);
				if (currentPriority>maxPriority)
				{				
					opers.push(str[i]);
					maxPriority=currentPriority;
				}
				else//�.� currentPriority<=maxPriority
				{
					tempOper=opers.pop();
					polish.push(tempOper);
					opers.push(str[i]);
					maxPriority=getPriority(str[i]);
				}
			}
		}
		while( opers.isEmpty() )//���� ���� ���������� �� ����
			{
				polish.push (opers.pop() );//����������� �� ���������� � ������� polish
			}
	}
	return polish;
}