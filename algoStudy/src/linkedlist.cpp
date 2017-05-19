#include "linkedlist.h"

#include <iostream>
using namespace std;

struct AGLLnode
{
	int key;
	AGLLnode *next;
};

AGLLnode *AGLLNodeHead = nullptr;
AGLLnode *AGLLNodeTail = nullptr;
int AGLLNodeCount = 0;

void AGLLQ_insert_enqueue(int pos, int value)
{
	if (AGLLNodeCount < pos)
		return;

	if (AGLLNodeCount == 0 || pos == AGLLNodeCount)
		return AGLLQ_right_enqueue(value);
	else if(pos == 0)
		return AGLLQ_left_enqueue(value);

	AGLLnode *hnode = AGLLNodeHead;
	AGLLnode *node = new AGLLnode();
	node->key = value;
		
	while (--pos)
		hnode = hnode->next;

	node->next = hnode->next;
	hnode->next = node;
	AGLLNodeCount++;
}

void AGLLQ_right_enqueue(int value)
{
	AGLLnode *node = new AGLLnode();
	node->key = value;
	node->next = nullptr;

	if (!AGLLNodeHead)
	{
		AGLLNodeHead = node;
		AGLLNodeTail = node;
	}
	else
	{
		AGLLNodeTail->next = node;
		AGLLNodeTail = node;
	}	
	AGLLNodeCount++;
}

void AGLLQ_left_enqueue(int value)
{
	AGLLnode *node = new AGLLnode();
	node->key = value;
	node->next = nullptr;

	if (!AGLLNodeHead)
	{
		AGLLNodeHead = node;
		AGLLNodeTail = node;
	}
	else
	{
		node->next = AGLLNodeHead;
		AGLLNodeHead = node;
	}
	AGLLNodeCount++;
}

int AGLLQ_left_dequeue()
{
	int retValue = -1;
	if (AGLLNodeCount > 0)
	{
		retValue = AGLLNodeHead->key;
		AGLLnode *node = AGLLNodeHead;
		AGLLNodeHead = AGLLNodeHead->next;
		delete node;
		AGLLNodeCount--;
	}
	return retValue;
}

int AGLLQ_right_dequeue()
{
	int retValue = -1;
	if (AGLLNodeCount > 0)
	{
		AGLLnode *tnode = AGLLNodeTail;
		AGLLnode *hnode = AGLLNodeHead;

		while (hnode->next && hnode->next != AGLLNodeTail)
			hnode = hnode->next;

		retValue = AGLLNodeTail->key;
		hnode->next = nullptr;
		AGLLNodeTail = hnode;
		delete tnode;
		AGLLNodeCount--;
	}
	return retValue;
}

void AGLLQ_clear()
{
	AGLLnode *node = AGLLNodeHead;
	while (node)
	{
		AGLLnode *dnode = node;
		node = node->next;
		delete dnode;
	}
	AGLLNodeCount = 0;
}

int AGLLQ_main()
{

	AGLLQ_right_enqueue(1);
	AGLLQ_right_enqueue(2);
	AGLLQ_right_enqueue(3);
	AGLLQ_right_enqueue(4);
	AGLLQ_right_enqueue(5);

	AGLLQ_insert_enqueue(2,10);
	AGLLQ_insert_enqueue(4,11);

	int value = -1;
	while((value = AGLLQ_left_dequeue()) > -1)
		cout << "[" << value << "]" << endl;

	/*
	while (true)
	{
		int input;
		cout << "input number: ";
		cin >> input;

		if (input < 0)
			break;

		if (input == 0)
		{
			int value = AGLLQ_right_dequeue();
			if (value == -1)
				cout << "queue empty!" << endl;
			else
				cout << "[" << value << "]" << endl;
		}
		else
		{
			AGLLQ_left_enqueue(input);
		}
	}
	*/
	AGLLQ_clear();
	return 0;
}