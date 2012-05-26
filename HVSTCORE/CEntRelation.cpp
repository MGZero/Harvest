#include "CEntRelation.h"

bool CEntRelation::checkFiringEvent(int evCheck)
{
	return (evCheck == firingEvent);
}

CEntRelation::CEntRelation (void * entActedOn, int eventToFire, int firingEvent )
{
	this->entActedOn = entActedOn;
	this->eventToFire = eventToFire;
	this->firingEvent = firingEvent;
}