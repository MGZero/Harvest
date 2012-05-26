#ifndef _CBASEARROW_H_
#define _CBASEARROW_H_

#include "PhysicalEnt.h"


class CBaseArrow : public CBasePhysEnt
{
public:
	CBaseArrow();
	~CBaseArrow();

	HVSTGFX::CSprite right, left, up, down;
	void move(HVSTGFX::directions dir);

	bool exist;
	int countDown;
};

#endif