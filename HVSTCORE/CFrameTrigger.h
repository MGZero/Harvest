#ifndef _CBASETRIGGER_H_
#define _CBASETRIGGER_H_

#include "CBaseEventTrigger.h"


class CFrameTrigger : public CBaseEventTrigger
{
public:
	
	~CFrameTrigger();

	void update();
	CFrameTrigger * initialize();
	void release();

private:
	CFrameTrigger();
	static CFrameTrigger * _singleton;


};

#endif

