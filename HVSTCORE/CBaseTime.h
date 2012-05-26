#ifndef _CBASETIME_H_
#define _CBASETIME_H_


#include <ctime> //for delta timing



namespace DELTATIME
{
	clock_t handleTime(clock_t tThen, clock_t tNow, clock_t tDelta);
};


#endif