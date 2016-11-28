#include "headerForMethods.h"
#include<string.h>
bool isStringCorrect( char str [])
{
	int len;
	len=strlen(str);
	int bracketsCount;
	bracketsCount=0;
	for (int i=0;i<len;i++)
	{
		//недопустиые символы
		if ( ( (str[i]<'0')||(str[i]>'9') )&&( (str[i]!='+')&&(str[i]!='-')&&(str[i]!='*')&&(str[i]!='/')&&(str[i]!='(')&&(str[i]!=')')&&(str[i]!=' ') ) )
		{
			//throw "string is incorrect";
			return false;
		}
		//два оператора подряд
		if ( ( (str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/') ) && ( (str[i+1]=='+')||(str[i+1]=='-')||(str[i+1]=='*')||(str[i+1]=='/') ) )
		{
			//throw "string is incorrect";
			return false;
		}
		//пробел
		/*if (str[i] == ' ')
		{

		}*/
		//подсчёт числа скобок
		if ( str[i]=='(' )
		{
			bracketsCount++;
		}
		if ( str[i]==')' )
		{
			bracketsCount--;
		}
	}
	//если соотношение скобок не равно
	if ( bracketsCount!=0 )
	{
		return false;
	}

	return true;
}
