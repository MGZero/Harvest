#include "CBaseBoomerang.h"


void CBaseBoomerang::initialize()
{
	spinning[0].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer0.png", &spinning[0].pngFile, spinning[0].texture);
	spinning[1].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer1.png", &spinning[1].pngFile, spinning[1].texture);
	spinning[2].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer2.png", &spinning[2].pngFile, spinning[2].texture);
	spinning[3].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer3.png", &spinning[3].pngFile, spinning[3].texture);
	spinning[4].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer4.png", &spinning[4].pngFile, spinning[4].texture);
	spinning[5].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer5.png", &spinning[5].pngFile, spinning[5].texture);
	spinning[6].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer6.png", &spinning[6].pngFile, spinning[6].texture);
	spinning[7].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/boomerang/boomer7.png", &spinning[7].pngFile, spinning[7].texture);

	mass.magnitude = .89;
	weight = HVSTPHYS::Calc_Force(mass, 9.81);
	myCharge.magnitude = 0.0;
	isReturning = false;
	exist = false;
	countDown = 0.0;
	spinCount = 0;
}

void CBaseBoomerang::move(HVSTGFX::directions dir)
{
	if (!exist)
		return;


	HVSTGFX::animateX(spinning, .36f, 8, .1f, .135f, x, y, spinCount); //.09
	myEvents.ev_wait(myEvents.waitCount(75.0, countDown));

	if (myEvents.onWait)
		isReturning = true;
		
		
	if (isReturning)
	{
		myEvents.onWait = false;
		comeBack();
	}
	else
		switch (dir)
		{
		case HVSTGFX::directions::RIGHT:
			x += .012f; //.003
			x2 += .012f;
			break;
		case HVSTGFX::directions::DOWN:
			y -= .016f; //.004
			y2 -= .016f;
			break;
		case HVSTGFX::directions::UP:
			y += .016f;
			y2 += .016f;
			break;
		default:
			x -= .012f;
			x2 -= .012f;
			break;
		}


	
}

void CBaseBoomerang::comeBack()
{
	moveToPoint(returnX, returnY, .012f); //.003
}