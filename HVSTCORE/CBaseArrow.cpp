#include "CBaseArrow.h"

CBaseArrow::CBaseArrow()
{
	right.sprite = HVSTGFX::loadPNGFile("resource/sprites/items/arrow/arrowR.png",
										&right.pngFile, right.texture);
	exist = false;
	countDown = 0;
}

CBaseArrow::~CBaseArrow()
{
	
}

void CBaseArrow::move(HVSTGFX::directions dir)
{
	if (!exist)
		return;

	switch (dir)
	{
	case HVSTGFX::directions::RIGHT:
		x += .24f; //.006
		HVSTGFX::createSpritePNGX(.1f, .0675f, x, y, right);
		break;
	case HVSTGFX::directions::LEFT:
		x -= .24f;
		HVSTGFX::createSpritePNGX(.1f, .0675f, x, y, right);
		break;
	default:
		break;
	}
}