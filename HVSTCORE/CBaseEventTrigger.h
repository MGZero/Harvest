#ifndef _CBASEEVENTTRIGGER_H_
#define _CBASEEVENTTRIGGER_H_
#include "event.h"

class CBaseEventTrigger
{
public:
	CBaseEventTrigger(){}
	virtual ~CBaseEventTrigger();

	void signalHandler(CBaseEvent * ev); //signal the event handlers in the entities
	CBaseEvent * getEvent(int index); //use this to reference the events
	int evCount();

protected:
	List<CBaseEvent*> _events; //list of events that this trigger can fire
	void _addEvent(CBaseEvent * ev);
};
#endif