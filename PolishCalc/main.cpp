#include "headerForMethods.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int i=0;
	float rez;
	char primer[10];
	cin>>primer;	
	//��������� �������
	charQueue polishQue(i);//�������� ������ ������� ��� �������� ������
	/*primerFIN=new char [i];
	for (int j=0;j<i;j++)
	{
		primerFIN[j]=primer[j];
	}*/
	polishQue=makePolish(primer);
	rez=calculate(polishQue);
	cout<<rez;
	//cin>>i;
	return 0;
}
