#include "queue.h"

void * queue::dequeue()
{
	void * temp;

	temp = data.retrieve(0);
	data.remove(0);
	return temp;
}

void queue::enqueue(void *data)
{
	this->data.append(&data);
}

int queue::getCount()
{
	return data.getCount();
}