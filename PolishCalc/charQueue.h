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
		firstEl=1;
		lastEl=0;
	}
	charQueue(const charQueue & objectT)//конструктор копирования
	{
		array = new char[objectT.size];
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
		array = new char[objectT.size];
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