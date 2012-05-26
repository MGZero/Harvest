#ifndef _CBASENPC_H_
#define _CBASENPC_H_

#include "AI.h"
#include "physicalEnt.h"
#include "CBaseSound.h"
#include "CBaseHitBox.h"

class CBaseNPC : public CBasePhysEnt
{
public:
	CBaseNPC();
	virtual ~CBaseNPC();

	//actions
	virtual void animate(HVSTGFX::CSprite *frames, float speed, int frameCount){}
	double AIFindPoint(double * coords);
	double AIFindPoint(double xFind, double yFind);
	double* AIFindCoord(CBaseTheoryEnt entFind);

	//AI conditions
	bool AIHealth0, AIHealthLow, AINone;

	void setCondition(bool condition, bool value){condition = value;}

	//sprites
	HVSTGFX::CSprite spriteMain;

	//hitbox
	CBaseHitBox * mainBox;

	//schedules
protected:
	

public:


protected:
	CBaseSound soundMain;
	
	virtual void initialize(double m);

	HVSTPHYS::CVelocity velocity;
	HVSTPHYS::CMomentum momentum;
	HVSTPHYS::CAccel accel;
	HVSTPHYS::CEnergy energy;
	HVSTPHYS::CForce force;
	HVSTPHYS::CPower power;

	//special events EG roomStart
	//NOTE: THESE FUNCTIONS WILL ALWAYS RUN.
	virtual inline void runRoomStart(){};
	virtual inline void runRoomEnd(){};
	virtual inline void runDestroy(){};
	virtual inline void runCreate(){};
};

#endif