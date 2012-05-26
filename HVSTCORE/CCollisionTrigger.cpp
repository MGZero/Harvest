#include "CCollisionTrigger.h"

CCollisionTrigger::CCollisionTrigger()
{

	CBaseEvent * collision = new CBaseEvent("Collision");

	_events.add(collision);
}

CCollisionTrigger::~CCollisionTrigger()
{
	_events.cleanNode(0);
}

void CCollisionTrigger::update()
{
	if (collState == COLLISION)
	{
		_events[0]->intParams = IDs;
		_events[0]->triggered = true;
	}
}