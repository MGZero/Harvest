#ifndef _CBASECOUNTER_H_
#define _CBASECOUNTER_H_

#include "theoreticalEnt.h"

class CBaseCounter : public CBaseTheoryEnt
{
public:
	CBaseCounter(){}
	CBaseCounter(int start, int max);
	CBaseCounter(int start, int max, int min);
	~CBaseCounter(){}

private:
	int maximum;
	int minimum;
	int count;

public:
	void increment(int val);
	void decrement(int val);
	void reset();
	void toMax();
	int getMax(){return maximum;}
	int getMin(){return minimum;}
	int getValue(){return count;}
};

#endif