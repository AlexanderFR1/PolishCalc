
//используется для хранения операторов
#include <string>

using namespace std;

class charStack
{
	int size;
	int currentIndex;
	string *array;
public:
	charStack(int Sz)
	{
		if (Sz<0)
		{
			throw "error";
		}
		size=Sz;
		array=new string [Sz];
		currentIndex=-1;//-1 => стек не имеет ничего
	}
	charStack(const char & obj)
	{

	}
	~charStack()
	{
		delete []array;
	}


	bool isEmpty()
	{
		return currentIndex<0;
	}
	bool isFull()
	{
		return currentIndex==size-1;
	}

	void push ( string Elem)
	{
		if (isFull() )
		{
			throw "Stack Full";
		}
		currentIndex++;
		array[currentIndex]=Elem;
	}
	void delTopEl()
	{
		currentIndex--;
	}

	 string pop()
	{
		if (isEmpty() )
		{
			throw "stack is empty";
		}
		currentIndex--;
		return array[currentIndex+1];
	}

	int getCurrentSize()
	{
		return currentIndex;
	}

};
