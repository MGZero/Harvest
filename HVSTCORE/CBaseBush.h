#ifndef _CBASEBUSH_H_
#define _CBASEBUSH_H_

#include "PhysicalEnt.h"

class CBaseBush : public CBasePhysEnt
{

public:
	CBaseBush();
	~CBaseBush(){}

	HVSTGFX::CSprite bush;
	HVSTGFX::CSprite splode[4];
	float splodeCount;
	void initialize();

private:
	
	void cut();
	void respawn();
	

};

#endif