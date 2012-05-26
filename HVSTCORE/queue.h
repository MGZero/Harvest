#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linkedlist.h"

class queue
{
public:
	void * dequeue();
	void enqueue(void * data);
	int getCount();

private:
	LinkedList data;
};

#endif