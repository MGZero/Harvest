#include "CBaseBush.h"

CBaseBush::CBaseBush()
{
	initialize();
}

void CBaseBush::initialize()
{
	bush.sprite = HVSTGFX::loadImageFile("resource/sprites/misc/bush.png", &bush.imgFile, bush.texture);

	//cut animation
	splode[0].sprite = HVSTGFX::loadImageFile("resource/sprites/misc/bush0.png", &splode[0].imgFile, splode[0].texture);
	splode[1].sprite = HVSTGFX::loadImageFile("resource/sprites/misc/bush1.png", &splode[1].imgFile, splode[1].texture);
	splode[2].sprite = HVSTGFX::loadImageFile("resource/sprites/misc/bush2.png", &splode[2].imgFile, splode[2].texture);
	splode[3].sprite = HVSTGFX::loadImageFile("resource/sprites/misc/bush3.png", &splode[3].imgFile, splode[3].texture);
	splodeCount = 0;
	
}