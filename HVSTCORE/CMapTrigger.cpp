#include "CMapTrigger.h"

CMapTrigger::CMapTrigger()
{
	_events.add(new CBaseEvent("distribute"));
	_distMap = false;
}

CMapTrigger::~CMapTrigger()
{

}

void CMapTrigger::update()
{
	if (_distMap)
	{
		signalHandler(_events["distribute"]);
		_distMap = false;
	}
}
