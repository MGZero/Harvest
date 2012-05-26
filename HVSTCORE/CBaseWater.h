#ifndef _CBASEWATER_H_
#define _CBASEWATER_H_

#include "PhysicalEnt.h"
#include "HVSTMTH.h"

//cycles
#define WATER0 0
#define WATER1 1
#define WATER2 2
#define WATER3 3

class CBaseWater : public CBasePhysEnt
{

public:
	CBaseWater(){initialize(HVSTMTH::randomNum(0,10));};
	~CBaseWater();

	
	float waterCount;
	HVSTGFX::CSprite waterFrames[4];

	int getCycle(){return cycle;}
	void initialize(int TYPE);
	void live();

private:
	int cycle;

};

#endif