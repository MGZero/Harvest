#include "PhysicalEnt.h"
CBasePhysEnt::CBasePhysEnt(int ID, std::string name, List<std::string> params)
: CBaseTheoryEnt()
{
}

void CBasePhysEnt::live()
{
	CBaseTheoryEnt::live();
}

void CBasePhysEnt::moveToPoint(float toX, float toY, float speed)
{
	if (x < toX)
	{
		x += speed;
		x2 += speed;
	}
	else if (x > toX)
	{
		x -= speed;
		x2 -= speed;
	}
	else
	{
		x += 0.0f;
		x2 += 0.0f;
	}

	if (y < toY)
	{
		y += speed;
		y2 += speed;
	}
	else if (y > toY)
	{
		y -= speed;
		y2 -= speed;
	}
	else
	{
		y += 0.0f;
		y2 += 0.0f;
	}
}

bool CBasePhysEnt::move(int speed, int frames, std::string direction)
{
	static int frameCounter = 0;

	if (frameCounter >= frames)
	{
		frameCounter = 0;
		return true;
	}
	else
	{
		frameCounter += speed;
		if (direction.compare("left"))
			x -= speed*SCALEX_1;
		else if (direction.compare("right"))
			x += speed*SCALEX_1;
		else if (direction.compare("down"))
			y -= speed*SCALEY_1;
		else if (direction.compare("up"))
			y += speed*SCALEY_1;

		return false;
			
	}
	
}

void CBasePhysEnt::initHB(float x1, float y1, float width1, float height1)
{
	if (!_hb)
		_hb = new CBaseHitBox(x1, y1, width1, height1);
}

void CBasePhysEnt::clearHB()
{
	if (_hb)
	{
		delete _hb;
		_hb = 0;
	}
}

void CBasePhysEnt::resetHB(float x1, float y1, float width1, float height1)
{
	if (_hb)
	{
		clearHB();
		initHB(x1, y1, width1, height1);
	}
}

void CBasePhysEnt::setHBHotSpot(float *x, float *y)
{
	if (_hb)
		_hb->setHotSpot(x,y);
}

void CBasePhysEnt::checkEvents()
{
	//collision event is checked here
/*	if (_hb && _hb->collisions->getEvent(0))
	{
		runCollide();
	}*/

	CBaseTheoryEnt::checkEvents();
}