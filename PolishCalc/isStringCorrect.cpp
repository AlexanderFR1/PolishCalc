#include "headerForMethods.h"
#include <string.h>
bool isStringCorrect( string str)
{
	int len;
	len=str.length();
	int bracketsCount;
	bracketsCount=0;
	for (int i=0;i<len;i++)
	{
		//����������� �������
		if ( ( (str[i]<'0')||(str[i]>'9') )&&( (str[i]!='+')&&(str[i]!='-')&&(str[i]!='*')&&(str[i]!='/')&&(str[i]!='(')&&(str[i]!=')')&&(str[i]!=' ') ) )
		{
			throw "string is incorrect";
			return false;
		}
		//��� ��������� ������
		if ( ( (str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/') ) && ( (str[i+1]=='+')||(str[i+1]=='-')||(str[i+1]=='*')||(str[i+1]=='/') ) )
		{
			throw "string is incorrect";
			return false;
		}
		if (( (str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/') ) &&  (str[i+1]=='\0') )
		{
			throw "string is incorrect";
			return false;
		}
		//������
		/*if (str[i] == ' ')
		{

		}*/
		//������� ����� ������
		if ( str[i]=='(' )
		{
			bracketsCount++;
		}
		if ( str[i]==')' )
		{
			bracketsCount--;
		}
	}
	//���� ����������� ������ �� �����
	if ( bracketsCount!=0 )
	{
		throw "string is incorrect";
		return false;
	}

	return true;
}
