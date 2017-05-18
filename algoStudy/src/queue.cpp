#include "queue.h"
#include <iostream>
using namespace std;

#define AG_QUEUE_CAPACITY 8

int AGQ_container[AG_QUEUE_CAPACITY];
int AGQ_head = 0;
int AGQ_tail = 0;
int AGQ_size = 0;

int AGQ_enqueue(int value)
{
	if (AGQ_size < AG_QUEUE_CAPACITY)
	{
		AGQ_container[AGQ_tail++] = value;
		AGQ_tail %= AG_QUEUE_CAPACITY;
		AGQ_size++;
		return AGQ_size;
	}
	return -1;	
}

int AGQ_dequeue()
{
	if (AGQ_size == 0)
		return -1;

	int ret = AGQ_container[AGQ_head++];
	AGQ_head %= AG_QUEUE_CAPACITY;
	AGQ_size--;

	return ret;
}

int AGQ_main()
{
	while (true)
	{
		int input;
		cout << "input number: ";
		cin >> input;

		if (input < 0)
			break;

		if (input == 0)
		{
			int value = AGQ_dequeue();
			if (value == -1)
				cout << "queue empty!" << endl;
			else
				cout << "[" << value << "]" << endl;
		}
		else
		{
			if (AGQ_enqueue(input) == -1)
			{
				cout << "queue full!" << endl;
			}
		}
	}
	return 0;
}