#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_


class node
{
public:

	node(void * data);
	~node(){}

	void *data;
	node *next;
	node *prev;
};

class LinkedList
{
public:
	LinkedList(){indexCounter = 0; firstNode = 0; lastNode = 0;lastReturn = 0; lastIndex = 0;}
	~LinkedList(){}

	void append(void * data);
	void remove(void *data);
	void remove(int index);
	int getCount();
	int getIndex(void * data);
	bool contains(void * data);
	void * retrieve(int index);
	void * retrieveSequential(int index); //move from the last known return
	void retrieve(void * buffer, void * data){};
	void insert(int at, void * data);
	void updateNode(void * data);
	void clear();


private:
	node *firstNode;
	node *lastNode;

	node *lastReturn;
	int lastIndex;

	int indexCounter;

};



#endif