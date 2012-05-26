#ifndef _CLINKEDLIST_H_
#define _CLINKEDLIST_H_

class CLinkedList
{
	class Node
	{
		public:
		void **data;
		Node *Next;
		Node *Prev;

	
		Node(){}
		Node(void * dataIn);
		Node(void * data, int elements);
		~Node(){};
	};

public:
	inline bool isEmpty(){return nodeCount == 0;}
	inline int numOfNodes(){return nodeCount;}
	void append(void * data);
	bool remove(void * scrap);
	void * retrieveData(int Node);

public:
	Node *firstNode;
	Node *lastNode;
	Node *temporary;
	Node *previous;
	int nodeCount;
};


#endif