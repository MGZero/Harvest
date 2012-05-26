#include "inputManager.h"

HVSTInput::CkeyboardTrigger * HVSTInput::CkeyboardTrigger::_singleton;

void HVSTInput::CkeyboardTrigger::update()
{
	//clear keys
	_events[0]->keyStrokesDown.clear();
	_pollKeys();
	//keydown events
	for(int i = 0; i < 128; i++)
	{
		if (_keyboard[i]->getKeyState() < 0)
			_events[0]->keyStrokesDown.add(_keyboard[i]->getKey());
	}

	//keyup events
	for (int i = 0; i < 128; i++)
	{
		if (_keyboard[i]->getPrevState() < 0 && _keyboard[i]->getKeyState() >= 0)
		{
			_events[1]->keyStrokesRelease.add(_keyboard[i]->getKey());
			_events[0]->keyStrokesDown.remove(_keyboard[i]->getKey());
		}
	}
	if (_events[0]->keyStrokesDown.count() > 0)
	{
		try
		{
			_events[4]->triggered = false;
			signalHandler(_events[0]);
		}
		catch (const char * error)
		{
			//do something..
		}
	}

	if (_events[1]->keyStrokesRelease.count() > 0)
	{
		try
		{
			signalHandler(_events[1]);
		}
		catch (const char * error)
		{
			//do something...
		}
	}

	if (_events[0]->keyStrokesDown.count() == 0)
	{
		try
		{
			_events[0]->triggered = false;
			signalHandler(_events[4]);
		}
		catch (const char * error)
		{

		}
	}
}

HVSTInput::CkeyboardTrigger::CkeyboardTrigger()
{
	int k = 0;
	CBaseEvent * keyDown = new CBaseEvent("Key Down");
	CBaseEvent * keyUp = new CBaseEvent("Key Up");
	CBaseEvent * mouseClick = new CBaseEvent("Mouse Click");
	CBaseEvent * mouseRelease = new CBaseEvent("Mouse Release");
	CBaseEvent * noKey = new CBaseEvent("No Key");

	_addEvent(keyDown);
	_addEvent(keyUp);
	_addEvent(mouseClick);
	_addEvent(mouseRelease);
	_addEvent(noKey);

	//initialize keyboard
	for (int i = 0; i < 256; i++)
		_keyboard[i] = new CKey(i);

	k = 0;
}

HVSTInput::CkeyboardTrigger * HVSTInput::CkeyboardTrigger::initialize()
{
	if (!_singleton)
		_singleton = new CkeyboardTrigger();

	return _singleton;
}

HVSTInput::CkeyboardTrigger::~CkeyboardTrigger()
{
	delete [] _keyboard;
}

void HVSTInput::CkeyboardTrigger::deinitialize()
{
	if (_singleton)
	{
		delete _singleton;
		_singleton = 0;
	}
}


HVSTInput::CKey::CKey(int keyCode)
{
	_key = keyCode;
	_previousState = 0;
	_currentState = 0;
}

int HVSTInput::CKey::getKeyState()
{
	return _currentState;
}

int HVSTInput::CKey::getPrevState()
{
	return _previousState;
}

void HVSTInput::CKey::setKeyState()
{
	_previousState = _currentState;
	_currentState = GetKeyState((char)_key);
}

int HVSTInput::CKey::getKey()
{
	return _key;
}

void HVSTInput::CkeyboardTrigger::_pollKeys()
{
	for (int i = 0; i < 256; i++)
	{
		_keyboard[i]->setKeyState();
	}
}


