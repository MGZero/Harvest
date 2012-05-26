#include "CLinkedList.h"

CLinkedList::Node::Node(void *dataIn)
{
	data = new void*[1];
	data[0] = dataIn;
}


void CLinkedList::append(void *data)
{
	if (firstNode == 0)
	{
		firstNode = new Node(&data);
		lastNode = firstNode;
		previous = firstNode;
	}
	else
	{
		temporary = new Node(&data);
		lastNode->Next = temporary;
		temporary->Prev = lastNode;
		lastNode = temporary;
		delete temporary;
		temporary = 0;
	}
	nodeCount++;

}

bool CLinkedList::remove(void *scrap)
{
	Node *Previous = firstNode;
	for (Node * current = firstNode; current != 0; current = current->Next)
	{
		if (current->data == scrap && previous == current)
		{
			firstNode = 0;
			if (firstNode == 0) lastNode = 0;
			nodeCount--;
			return true;
		}
		else if (current->data == scrap && current->Next != 0)
		{
			previous->Next = current->Next;
			previous->Next->Prev = previous;
			nodeCount--;
			return true;
		}
		else if (current->data == scrap && current->Next == 0)
		{
			lastNode = previous;
			previous->Next = 0;
			nodeCount--;
			return true;
		}
		previous = current;
	}
	return false;
}
		

