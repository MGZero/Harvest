#include "CBaseEventTrigger.h"

void CBaseEventTrigger::signalHandler(CBaseEvent *ev)
{
	int index = 0;
	if ((index = _events.indexOf(ev)) != -1)
		ev->triggered = true;
	else
		throw "Event does not exist!";
}

CBaseEventTrigger::~CBaseEventTrigger()
{
	for (int i = 0; i < _events.count(); i++)
	{
		_events.cleanNode(i);
		_events[i] = 0;
	}

	_events.clear();
}

void CBaseEventTrigger::_addEvent(CBaseEvent *ev)
{
	int index = 0;
	if ((index = _events.indexOf(ev)) == -1)
		_events.add(ev);
	else
		throw "Event already exists!";
}

CBaseEvent * CBaseEventTrigger::getEvent(int index)
{
	return _events[index]; 
}

int CBaseEventTrigger::evCount()
{
	return _events.count();
}