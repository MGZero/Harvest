#include "CBaseCounter.h"

CBaseCounter::CBaseCounter(int start, int max)
{
	maximum = max;
	minimum = 0;
	count = start;
}

CBaseCounter::CBaseCounter(int start, int max, int min)
{
	count = start;
	maximum = max;
	minimum = min;
}

void CBaseCounter::increment(int val)
{
	int temp;
	int tempMax = maximum;
	
	temp = tempMax - count;

	if (temp == 0)
		return;
	else if (temp < 0)
		return;
	else
		for (int i = 0; i < val; i++)
			if (count != maximum)
				count++;
			else
				return;
}

void CBaseCounter::decrement(int val)
{
	int temp;
	int tempMin = minimum;
	
	temp = count - tempMin;

	if (temp == 0)
		return;
	else if (temp < 0)
		return;
	else
		for (int i = 0; i < val; i++)
			if (count != maximum)
				count--;
			else
				return;
}
