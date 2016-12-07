#include <string>
#include "headerForMethods.h"
#include <cstdlib>

float calculate(charQueue Polish)
{
	int tempResSize,intTemp;
	string temp;
	float Num1,Num2,num;
	tempResSize=Polish.getPhysSize();
	floatResult tempRes(tempResSize);
	do
	{
		temp=Polish.pop();
		if ( (temp[0]>='0')&&(temp[0]<='9') )//���� �� ������� ������������� �����
		{
			if (temp.length()>1)//�, ��� ���������, �����
			{
				char* tempChar;
				tempChar=new char[temp.length()];
				for (int g=0;g<temp.length();g++)
					tempChar[g]=temp[g];
				int value;
				value=atoi(tempChar);				
				tempRes.push(static_cast<float>(value));//�� ����� ����� � ���� �������������� ����������
			}
			else
			{
				char tempus;
				tempus=temp[0];
				intTemp=static_cast<int>(tempus);		
				tempRes.push(static_cast<float>(intTemp)-'0');//�� ����� � � ���� �������������� ����������
			}
		}
		else//�� ���� ���� ��������� + - / *
		{
			Num2=tempRes.pop();
			Num1=tempRes.pop();
			switch (temp[0])
			{
			case '+':
				{
					num=Num1+Num2;
					tempRes.push (num);
					break;
				}
			case '-':
				{
					num=Num1-Num2;
					tempRes.push (num);
					break;
				}
				case '/':
				{
					num=Num1/Num2;
					tempRes.push (num);
					break;
				}
			case '*':
				{
					num=Num1*Num2;
					tempRes.push (num);
					break;
				}
			}
		}
	}
	while (!Polish.isEmpty());
	return (tempRes.pop() );
}