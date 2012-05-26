#ifndef _CBASECAMERA_H_
#define _CBASECAMERA_H_

#include "restrictedent.h"
#include "physicalent.h"
#include "logic.h"

class CBaseCamera : public CBaseRestrictedEnt
{
public:
	CBaseCamera(float viewX, float viewY, float myX, float myY, float boundX, float boundY, CBaseVector mySpeed, CBasePhysEnt * following, bool engine);
	~CBaseCamera();

	CBasePhysEnt * follow; //the entity to follow
	void live();
	void snapTo(float newX, float newY);

	float getx(){return x;}
	float gety(){return y;}
	HVSTLOG::CBaseHUD * HUD;

private:
	

	float viewPortWidth, viewPortHeight;
	float x, y;
	float rot;
	float scale;
	float xBound, yBound;
	CBaseVector speed;
	HVSTMTH::matrix *transformation;
	

	void update(float newX, float newY);
};

#endif