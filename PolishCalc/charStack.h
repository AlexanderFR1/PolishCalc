class charStack
{
	int size;
	int currentIndex;
	 char *array;
public:
	charStack(int Sz)
	{
		size=Sz;
		array=new  char [Sz];
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

	void push ( char Elem)
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

	 char pop()
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
