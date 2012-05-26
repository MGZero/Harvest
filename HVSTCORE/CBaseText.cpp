#include "CBaseText.h"

CBaseText::CBaseText(int ID, std::string name, List<std::string> params)
{
	this->_ID = ID;
	this->mapName = name;
	this->_currentMsg = 0;

	//parameters will determine font, background and screen position
}

CBaseText::~CBaseText()
{
	if (_currentMsg)
	{
		delete _currentMsg;
		_currentMsg = 0;
	}
}

void CBaseText::checkEvents()
{
	CBaseTheoryEnt::checkEvents();
	if (glbl->GTextTrigger->getEvent(0)->triggered){}
		runOnTextShow((CMessage*)glbl->GTextTrigger->getEvent(0)->genericParam);
}

void CBaseText::_showText()
{
	
}

void CBaseText::live()
{
	CBaseTheoryEnt::live();
}

void CBaseText::runOnTextShow(CMessage * message)
{
	static int letterCount = 0; //keeps track of how much of the message to draw
	//just do this every call, shallow copy won't take long
	_currentMsg = message;

	for (int i = 0; i < letterCount; i++)
	{
		//flip on which letters should be drawn
	}




}