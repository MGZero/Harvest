#ifndef _CBASEBOOMERANG_H_
#define _CBASEBOOMERANG_H_

#include "PhysicalEnt.h"

class CBaseBoomerang : public CBasePhysEnt
{
	
public:
	CBaseBoomerang(){initialize();}
	~CBaseBoomerang(){}

	void move(HVSTGFX::directions dir);
	void comeBack();
	bool getReturn(){return isReturning;}

	HVSTGFX::CSprite spinning[8];
	float spinCount;
	bool exist;
	float returnX, returnY;
	bool isReturning;

private:
	void initialize();
	
	int countDown;
	
	
};

#endif