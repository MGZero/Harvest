#ifndef _CBASETIMER_H_
#define _CBASETIMER_H_

#include "CBaseEventTrigger.h"

#define ONE_SECOND 60

class CBaseTimer
{
public:
	CBaseTimer(){};
	CBaseTimer(int ticks);
	virtual ~CBaseTimer();

	void start();
	void pause();
	void restart();
	void stop();
	void unpause();
	void tick();

	int getTicks();
	int getCurrentTick();
	bool getStarted();
	bool getPaused();

private:
	int _ticks;
	int _currentTick;
	bool _started;
	bool _paused;
};

class CTimerTrigger : public CBaseEventTrigger
{
public:
	CTimerTrigger();
	~CTimerTrigger(){};

	CBaseTimer * getTimer();
	void createTimer(CBaseTimer * timerRef);
	void update();

private:
	CBaseTimer * _timerRef;

};

#endif