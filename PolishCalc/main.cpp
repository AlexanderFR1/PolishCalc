#include "headerForMethods.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//int i=0;
	float rez;
	std::string primer;
	charQueue polishQue(10);

	std::getline(std::cin, primer); //cin>>primer;	
	
	
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
