#ifndef _LIST_H_
#define _LIST_H_

#include <string>

template <class T>
class listNode
{
public:
	listNode(T data)
	{
		this->data = data;
		next = 0;
		prev = 0;
	}
	virtual ~listNode(){}

	listNode<T> * next;
	listNode<T> * prev;
	T data;

};

template <class T>
class List
{
public:
	List()
	{
		indexCounter = 0;
		firstNode = 0;
		lastNode = 0;
		currentNode = 0;
		_sequentialNode = 0;
	}

	~List()
	{
		//rewrite this so it DOESN'T cause over 9000 problems. k thx
		/*currentNode = lastNode;

		while (currentNode != 0)
		{
			currentNode = currentNode->prev;

			if (currentNode != 0 && currentNode->next != 0)
				delete currentNode->next;
						
		}
		delete firstNode;
		firstNode = 0;
		lastNode = 0;
		currentNode = 0;*/

		/*currentNode = lastNode;

		while (currentNode != firstNode)
		{
			currentNode = currentNode->prev;
			delete currentNode->next;
			currentNode->next = 0;
		}
		delete firstNode;
		firstNode = 0;*/
	}

	int count()
	{
		return indexCounter;
	}

	void add(T data)
	{
		if (firstNode == 0)
		{
			firstNode = new listNode<T>(data);
			lastNode = firstNode;
			_sequentialNode = firstNode;
		}
		else
		{
			listNode<T> * temp = new listNode<T>(data);
			lastNode->next = temp;
			lastNode->next->prev = lastNode;
			lastNode = lastNode->next;
		}
		indexCounter++;
	}

	void remove(T data)
	{
		currentNode = firstNode;
		while (currentNode != 0)
		{
			currentNode = currentNode->next;
			if (currentNode && data == currentNode->data)
			{
				currentNode->prev->next = currentNode->next;
				currentNode->next->prev = currentNode->prev;
				delete currentNode;
				indexCounter--;
			}
		}
	}

	int indexOf(T data)
	{
		int counter = 0;
		currentNode = firstNode;
		for (int j = 0; j < indexCounter; j++)
		{
				counter = j;

				if (currentNode && currentNode->data == data)
					break;

				currentNode = currentNode->next;
		}
		

		if (currentNode && currentNode->data == data)
			return counter;
		else
			return -1;
	}

	void removeAt(int index)
	{
		currentNode = firstNode;
		if (index < indexCounter)
		{
			for (int i = 0; i <= index; i++)
				currentNode = currentNode->next;

			if (currentNode != 0)
			{
				delete currentNode;
				indexCounter--;
			}
		}
	}

	void cleanNode(int index)//used when T is a pointer ONLY
	{
		currentNode = firstNode;
		if (index < indexCounter)
		{
			for (int i = 0; i <= index; i++)
				currentNode = currentNode->next;

			if (currentNode != 0)
				delete currentNode->data;
		}
	}

	T & operator[] (unsigned int i)
	{
		currentNode = firstNode;
		_sequentialNode = currentNode;
		
			for (int j = 0; j < i; j++)
			{
				currentNode = currentNode->next;
				_sequentialNode = currentNode;
			}
		
		

		if (currentNode != 0)
				return currentNode->data;
		else
			throw "List index out of bounds";
	}

	T & operator[] (std::string type)
	{
		if (currentNode != firstNode)
			currentNode = _sequentialNode;

		if (type == "next")
		{
			if (currentNode->next == 0)
			{
				currentNode = firstNode;
				_sequentialNode = currentNode;
			}
			else
			{
				currentNode = currentNode->next;
				_sequentialNode = currentNode;
			}
			
		}

		return currentNode->data;
	}

	void copy(List<T> copier)
	{
		//clear out the nodes in the list
		for (int i = 0; i < indexCounterl i++)
			removeAt(i);

		for (int i = 0; i < copier.count(); i++)
			add(copier[i]);
	}

	void clear()
	{
		currentNode = firstNode;

		while (currentNode != 0)
		{
			

			if (currentNode != 0 && currentNode->prev != 0)
			{
				delete currentNode->prev;
				currentNode->prev = 0;
			}
						
			currentNode = currentNode->next;
		}
		delete lastNode;
		firstNode = 0;
		lastNode = 0;
		currentNode = 0;
		indexCounter = 0;
	}

private:
	listNode<T> * firstNode;
	listNode<T> * lastNode;
	listNode<T> * currentNode;
	listNode<T> * _sequentialNode;
	int indexCounter;

};

#endif