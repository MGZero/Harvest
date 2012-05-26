#ifndef _CBASEBOMB_H_
#define _CBASEBOMB_H_

#include "physicalEnt.h"
#include "CBaseSound.h"
#include "CBaseHitBox.h"
class CBaseBomb : public CBasePhysEnt
{

	//make sure to implement the physics engine on this

public:
	CBaseBomb();
	~CBaseBomb(){}

	bool exist;
	bool exploding;
	bool goneOff;
	int countDown;
	int bombCount;
	HVSTGFX::CSprite explode[22];
	HVSTGFX::CSprite idle[16];

	float explodeCount;
	float idleCount;

	void tick();
	void kaboom();
	void initialize();

	CBaseSound * explodeSfx;

	CBaseHitBox * mainBox;
	CBaseHitBox * physBox;

};



#endif