#include "CBaseTimer.h"

CBaseTimer::CBaseTimer(int ticks)
{
	_ticks = ticks;
	_currentTick = 0;
	_started = false;
	_paused = false;
}

CBaseTimer::~CBaseTimer()
{
}

void CBaseTimer::pause()
{
	_paused = true;
}

void CBaseTimer::restart()
{
	_currentTick = 0;
}

void CBaseTimer::stop()
{
	_started = false;
	_currentTick = 0;
}

void CBaseTimer::unpause()
{
	_paused = false;
}

void CBaseTimer::start()
{
	_started = true;
	_currentTick = 0;
}

void CBaseTimer::tick()
{
	if (_started && !_paused)
	{
		_currentTick++;
	}
}

CTimerTrigger::CTimerTrigger()
{
	CBaseEvent * timerEnd = new CBaseEvent;
	_addEvent(timerEnd);
}

CBaseTimer * CTimerTrigger::getTimer()
{
	return _timerRef;
}

int CBaseTimer::getTicks()
{
	return _ticks;
}

int CBaseTimer::getCurrentTick()
{
	return _currentTick;
}

bool CBaseTimer::getPaused()
{
	return _paused;
}

bool CBaseTimer::getStarted()
{
	return _started;
}

void CTimerTrigger::createTimer(CBaseTimer * timerRef)
{
	_timerRef = timerRef;
}

void CTimerTrigger::update()
{
	if (_timerRef->getStarted() && !_timerRef->getPaused())
	{
		_timerRef->tick();

		if (_timerRef->getCurrentTick() >= _timerRef->getTicks())
		{
			signalHandler(_events[0]);
			delete _timerRef;
		}
	}
}