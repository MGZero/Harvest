#include "CFrameTrigger.h"

CFrameTrigger * CFrameTrigger::_singleton;

CFrameTrigger::CFrameTrigger()
{
	CBaseEvent * frameEvent = new CBaseEvent("frame");

	_events.add(frameEvent);
}

CFrameTrigger * CFrameTrigger::initialize()
{
	if (!_singleton)
		_singleton = new CFrameTrigger();

	return _singleton;
}

void CFrameTrigger::release()
{
	if (_singleton)
		delete _singleton;
	else
		throw "Tried to release uninitialized component CFrameTrigger!";
}

CFrameTrigger::~CFrameTrigger()
{
	
}

void CFrameTrigger::update()
{
	signalHandler(_events[0]);
}