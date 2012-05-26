#include "event.h"


bool CBaseEvent::handleCheck()
{
	return triggered;
}

std::string CBaseEvent::getName()
{
	return _name;
}