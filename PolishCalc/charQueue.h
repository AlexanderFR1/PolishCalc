class charQueue
{
	int size;
	char *array;
	int firstEl, lastEl;
public:
	charQueue (int Sz)//  конструктор
	{
		array = new char[Sz];
		size=Sz;
		firstEl=0;
		lastEl=1;
	}
	~charQueue()

	{
		delete []array;
	}

	bool isEmpty()
	{
		return (firstEl+1)%size==lastEl;
	}
	bool isFull()
	{
		return (lastEl+2)%size==firstEl;
	}

	void push (char Elem)
	{
		if (isFull() )
		{
			throw "queue is full";
		}
		lastEl=(lastEl+1)%size;
		array[lastEl]=Elem;
	}
	char pop()
	{
		if (isEmpty() )
		{
			throw "queue is empty";
		}
		char temp;
		temp=array[firstEl];
		firstEl=(firstEl+1)%size;
		return temp;
	}
	int getPhysSize()
	{
		return size;
	}
};