#ifndef _PHYSICALENT_H_
#define _PHYSICALENT_H_

//#include "HVSTDATMAIN.h"
#include "theoreticalEnt.h"
#include "CBaseHitBox.h"

class CBasePhysEnt : public CBaseTheoryEnt
{

public:
	CBasePhysEnt(){}
	CBasePhysEnt(int ID, std::string name, List<std::string> params);
	virtual ~CBasePhysEnt(){}

	void moveToPoint(float toX, float toY, float speed);

	//phyics properties
	HVSTPHYS::CMass mass;
	HVSTPHYS::CForce weight;
	HVSTPHYS::CCharge charge;
	HVSTPHYS::CVelocity velocity;
	HVSTPHYS::CAccel accel;
	HVSTPHYS::CMomentum momentum;
	HVSTPHYS::CForce force; //force to exert

	virtual void live();
	bool move(int speed, int frames, std::string direction);
	
	void clearHB();
	void resetHB(float x1, float y1, float width1, float height1);
	void initHB(float x1, float y1, float width1, float height1);
	void setHBHotSpot(float * x, float * y);

private:
	CBaseHitBox * _hb;

protected:
	
	virtual void runCollide(){}
	float width, height;
	virtual void checkEvents();
	
	
};

#endif