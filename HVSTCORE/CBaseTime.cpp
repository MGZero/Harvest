#include "CBaseTime.h"


clock_t DELTATIME::handleTime(clock_t tThen, clock_t tNow, clock_t tDelta)
{
	tNow = clock();

	if (tThen == 0)
	{
		tDelta = tNow;
	}
	else
	{
		tDelta = tNow - tThen;
	}

	tThen = tNow;
	return tDelta;
}
