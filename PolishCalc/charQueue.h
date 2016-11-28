
#include <stdio.h>
#include <iostream>

using namespace std;
class charQueue
{
	int size;
	string *array;
	int firstEl, lastEl;
public:
	charQueue (int Sz)//  конструктор
	{
		array = new string[Sz];
		size=Sz;
		firstEl=1;
		lastEl=0;
	}
	charQueue(const charQueue & objectT)//конструктор копирования
	{
		array = new string[objectT.size];
		for (int i = 0; i < objectT.size; i++)
		{
			array[i] = objectT.array[i];
		}
		//array = objectT.array;
		size = objectT.size;
		firstEl = objectT.firstEl;
		lastEl = objectT.lastEl;
	}
	charQueue& operator=(const charQueue& objectT)
	{
		if (this == &objectT)
			return *this;
		delete[]array;
		//array = objectT.array;
		array = new string[objectT.size];
		for (int i = 0; i < objectT.size; i++)
		{
			array[i] = objectT.array[i];
		}
		size = objectT.size;
		firstEl = objectT.firstEl;
		lastEl = objectT.lastEl;
		return *this;
	}
	~charQueue()

	{
		delete []array;
	}

	bool isEmpty()
	{
		return (lastEl+1)%size==firstEl;
	}
	bool isFull()
	{
		return (lastEl+2)%size==firstEl;
	}

	void push (string Elem)
	{
		if (isFull() )
		{
			throw "queue is full";
		}
		lastEl=(lastEl+1)%size;
		array[lastEl]=Elem;
	}
	string pop()
	{
		if (isEmpty() )
		{
			throw "queue is empty";
		}
		string temp;
		temp=array[firstEl];
		firstEl=(firstEl+1)%size;
		return temp;
	}
	int getPhysSize()
	{
		return size;
	}
};