#ifndef _CTEXTTRIGGER_H_
#define _CTEXTTRIGGER_H_

#include "CBaseEventTrigger.h"


class CTextTrigger : public CBaseEventTrigger
{
public:
	
	void update();
	CTextTrigger * init();
	void release();

private:
	CTextTrigger();
	~CTextTrigger(){}

	static CTextTrigger * _singleton;

};

#endif