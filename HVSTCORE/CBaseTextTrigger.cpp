#include "CBaseTextTrigger.h"

CTextTrigger * CTextTrigger::_singleton;

CTextTrigger::CTextTrigger()
{
	CBaseEvent * textDisplay = new CBaseEvent("Text Display");

	_events.add(textDisplay);
}

CTextTrigger * CTextTrigger::init()
{
	if (!_singleton)
		_singleton = new CTextTrigger();

	return _singleton;
}

void CTextTrigger::release()
{
	if (_singleton)
		delete _singleton;
	else
		throw "Tried to release uninitialized component CBaseTextTrigger!";
}

void CTextTrigger::update()
{

}