#include "CBaseWater.h"


CBaseWater::~CBaseWater()
{
	
}


void CBaseWater::live()
{
	//HVSTGFX::animateX(waterFrames, .2f, 4, SCALEX_16, SCALEY_16, x, y, waterCount);
}

void CBaseWater::initialize(int TYPE)
{
	waterCount = 0;

	switch (TYPE)
	{

	case 0:
		waterFrames[0].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water00.png", &waterFrames[0].imgFile, waterFrames[0].texture);
		waterFrames[1].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water01.png", &waterFrames[1].imgFile, waterFrames[1].texture);
		waterFrames[2].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water02.png", &waterFrames[2].imgFile, waterFrames[2].texture);
		waterFrames[3].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water03.png", &waterFrames[3].imgFile, waterFrames[3].texture);
		break;

	case 1:
		waterFrames[0].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water10.png", &waterFrames[0].imgFile, waterFrames[0].texture);
		waterFrames[1].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water11.png", &waterFrames[1].imgFile, waterFrames[1].texture);
		waterFrames[2].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water12.png", &waterFrames[2].imgFile, waterFrames[2].texture);
		waterFrames[3].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water13.png", &waterFrames[3].imgFile, waterFrames[3].texture);
		break;

	case 2:
		waterFrames[0].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water20.png", &waterFrames[0].imgFile, waterFrames[0].texture);
		waterFrames[1].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water21.png", &waterFrames[1].imgFile, waterFrames[1].texture);
		waterFrames[2].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water22.png", &waterFrames[2].imgFile, waterFrames[2].texture);
		waterFrames[3].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water23.png", &waterFrames[3].imgFile, waterFrames[3].texture);
		break;

	case 3:
		waterFrames[0].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water30.png", &waterFrames[0].imgFile, waterFrames[0].texture);
		waterFrames[1].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water31.png", &waterFrames[1].imgFile, waterFrames[1].texture);
		waterFrames[2].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water32.png", &waterFrames[2].imgFile, waterFrames[2].texture);
		waterFrames[3].sprite = HVSTGFX::loadImageFile("resource/sprites/water/water33.png", &waterFrames[3].imgFile, waterFrames[3].texture);
		break;

	default:
		waterFrames[0].sprite = HVSTGFX::loadImageFile("resource/sprites/water/waterStill.png", &waterFrames[0].imgFile, waterFrames[0].texture);
		waterFrames[1].sprite = HVSTGFX::loadImageFile("resource/sprites/water/waterStill.png", &waterFrames[1].imgFile, waterFrames[1].texture);
		waterFrames[2].sprite = HVSTGFX::loadImageFile("resource/sprites/water/waterStill.png", &waterFrames[2].imgFile, waterFrames[2].texture);
		waterFrames[3].sprite = HVSTGFX::loadImageFile("resource/sprites/water/waterStill.png", &waterFrames[3].imgFile, waterFrames[3].texture);
		break;

	}
}