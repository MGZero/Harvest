#ifndef _EVENT_H_
#define _EVENT_H_

#include "list.h"
#include "command.h"
#include <vector>

class CBaseEvent
{
public:
	CBaseEvent(){triggered = false;}
	CBaseEvent(std::string name){triggered = false; _name = name;}
	virtual ~CBaseEvent(){}

	bool handleCheck();
	bool triggered;
	
	List<char> keyStrokesDown; //for keyboard events
	List<char> keyStrokesRelease; //keys that are released
	void * genericParam;
	std::vector<std::string> stringParams;
	std::vector<int> intParams;

	std::string getName();

private:
	std::string _name;
};

#endif

