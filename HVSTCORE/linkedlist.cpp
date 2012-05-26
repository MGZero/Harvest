#include "linkedlist.h"

node::node(void *data)
{
	this->data = data;
	next = 0;
	prev = 0;
	
}

int LinkedList::getCount()
{
	return indexCounter;
}

void LinkedList::append(void *data)
{
	node * current = new node(data);

	if (firstNode == 0)
	{
		firstNode = current;
		lastNode = firstNode;
		lastReturn = firstNode;
		lastIndex = 0;
		indexCounter++;
	}
	else
	{
		lastNode->next = current;
		lastNode->next->prev = lastNode;
		lastNode = lastNode->next;
		indexCounter++;
	}
	
}

void LinkedList::insert(int at, void * data)
{
	node * temp = new node(data);
	node * current = firstNode;

	if (firstNode == 0)
		append(data);
	else
	{
		for (int i = 0; i < at; i++)
		{
			current = current->next;
		}
		temp->next = current->next;
		temp->prev = current;

		current->next = temp;
		temp->next->prev = temp;
	}
}

int LinkedList::getIndex(void * data)
{
	node * current = firstNode;
	int count = 0;

	while (current->data != data)
	{
		current = current->next;
		count++;
	}
	return count;
}

void LinkedList::remove(void *data)
{
	node * current = firstNode;

	if (firstNode == 0)
		return;
	else
		while (current != 0)
		{
			if (current->data = data)
			{
				current->next->prev = current->prev;
				current->prev = current->next;
				delete current;
				current = 0;
				indexCounter--;
				return;
			}

		}
}

void LinkedList::remove(int index)
{
	node * current = firstNode;

	if (firstNode == 0)
		return;
	else
	{
		for (int i = 0; i < index; i++)
			current = current->next;

		current->next->prev = current->prev;
		current->prev = current->next;
		delete current;
		current = 0;
		indexCounter--;
		return;
	}

}

void * LinkedList::retrieve(int index)
{
	node * current = firstNode;
	void * buffer = 0;

	if (current != 0)
	{
		for (int i = 0; i < indexCounter; i++)
		{
			if (i == index)
			{
				buffer = (void*)current->data;
				lastReturn = current;
				lastIndex = i;
				return buffer;
			}
			else
				current = current->next;
		}
	}

}

bool LinkedList::contains( void * data)
{
	node * current = firstNode;

	while ( current )
	{
		if (current->data = data)
			return true;

		current = current->next;
	}
	return false;
}

void * LinkedList::retrieveSequential(int index)
{
	node * current = lastReturn;
	void * buffer = 0;

	if (current = lastNode)
	{
		current = firstNode;
		lastReturn = firstNode;
		lastIndex = 0;
	}

	if (current && index >= lastIndex)
	{
		for (int i = lastIndex; i < indexCounter; i++)
		{
			if (i == index)
			{
				buffer = (void*)current->data;
				lastReturn = current;
				lastIndex = i;
				return buffer;
			}
			else
			{
					current = current->next;
			}
		}
	}
}
	
void LinkedList::updateNode(void * data)
{
	lastReturn->data = data;
}

void LinkedList::clear()
{
	node * current = 0;

	current = lastNode;

	while (current->prev != 0)
	{
		current = current->prev;
		delete current->next;
	}
	delete firstNode;
	firstNode = 0;
	lastNode = 0;
	lastReturn = 0;
	lastIndex = 0;

}