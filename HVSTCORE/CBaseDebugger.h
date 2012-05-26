#ifndef _CBASEDEBUGGER_H_
#define _CBASEDEBUGGER_H_

#include "restrictedent.h"
#include "DBG.h"

class CBaseDebugger : public CBaseRestrictedEnt
{
public:
	CBaseDebugger(bool engine);
	~CBaseDebugger();

	void writeToFile(std::string data);
	void live();

private:
	CDBG * debugFile;
};

#endif