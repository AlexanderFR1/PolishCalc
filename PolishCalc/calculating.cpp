/*#include "charQueue.h"
#include "charStack.h"
#include "floatResult.h"*/
#include <string.h>
#include "headerForMethods.h"

float calculate(charQueue Polish)
{
	int tempResSize,intTemp;
	char temp;
	float Num1,Num2,num;
	tempResSize=Polish.getPhysSize();
	floatResult tempRes(tempResSize);
	do
	{
		temp=Polish.pop();
		if ( (temp>='0')&&(temp<='9') )//���� �� ������� ������������� �����
		{
			intTemp=static_cast<int>(temp);		
			tempRes.push(static_cast<float>(intTemp));//�� ����� � � ���� �������������� ����������
		}
		else//�� ���� ���� ��������� + - / *
		{
			Num2=tempRes.pop();
			Num1=tempRes.pop();
			switch (temp)
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
	while (Polish.isEmpty()==false);
	return (tempRes.pop() );
}