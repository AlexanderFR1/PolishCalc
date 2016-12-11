class floatResult
{
	int size;
	int currentIndex;
	 float *array;
public:
	floatResult(int Sz)
	{
		if (Sz<0)
		{
			throw "error";
		}
		size=Sz;
		array=new float [Sz];
		currentIndex=-1;//-1 => стек не имеет ничего
	}
	~ floatResult()
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

	void push ( float Elem)
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

	float pop()
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
