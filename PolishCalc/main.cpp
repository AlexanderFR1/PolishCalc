#include "headerForMethods.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	//int i=0;
	float rez;
	char primer[10];
	charQueue polishQue(10);

	cin>>primer;	
	
	//создаётся пустая очередь для польской записи
	if (isStringCorrect(primer) )
	{
		polishQue=makePolish(primer);
		show (polishQue);
		cout<<'\n';
		rez=calculate(polishQue);
		cout<<rez;
	}
	else
	{
		cout<<"no";
	}
	//cin>>i;
	return 0;
}
