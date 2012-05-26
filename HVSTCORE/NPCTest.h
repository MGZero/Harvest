#ifndef _NPCTEST_H_
#define _NPCTEST_H_

#include "CBaseNPC.h"

class CNPCTest : public CBaseNPC
{

public:
	CNPCTest();
	virtual ~CNPCTest();

private:
	virtual void initialize(double m);



};

#endif

