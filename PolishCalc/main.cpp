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

	polishQue=makePolish(primer);
	rez=calculate(polishQue);
	cout<<rez;
	//cin>>i;
	return 0;
}
