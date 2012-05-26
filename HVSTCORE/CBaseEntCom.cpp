#include "CBaseEntCom.h"

void CBaseEntCom::loadIdentity(CBaseEventTrigger &trigger, std::string name)
{
	int count = trigger.evCount();
	CBaseEvent * temp = 0;

	for (int i = 0; i < count; i++)
	{
		temp = trigger.getEvent(i);
		if (temp->getName() == name)
		{
			_eventIdentity = temp;
			temp = 0;
			break;
		}
	}
}

void CBaseEntCom::clearIdentity()
{
	if (_eventIdentity)
		_eventIdentity = 0;
}

void CBaseEntCom::triggerIdentity()
{
	if (_eventIdentity)
		_eventIdentity->triggered = true;
}

void CBaseEntCom::runLoadIdentity(void *trigger, std::string name)
{
	CBaseEventTrigger * tempTrigger = (CBaseEventTrigger*)trigger;

	loadIdentity(*tempTrigger, name);
}

void CBaseEntCom::runNewFrame()
{
	triggerIdentity();
	clearIdentity();
}