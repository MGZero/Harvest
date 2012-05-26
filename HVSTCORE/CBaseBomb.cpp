#include "CBaseBomb.h"


void CBaseBomb::initialize()
{
	exist = false;
	exploding = false;
	goneOff = false;
	mass.magnitude = 5.0;
	bombCount = 0;

	idleCount = 0;
	explodeCount = 0;

	explode[0].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb0.png", &explode[0].pngFile, explode[0].texture);
	explode[1].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb1.png", &explode[1].pngFile, explode[1].texture);
	explode[2].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb2.png", &explode[2].pngFile, explode[2].texture);
	explode[3].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb3.png", &explode[3].pngFile, explode[3].texture);
	explode[4].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb4.png", &explode[4].pngFile, explode[4].texture);
	explode[5].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb5.png", &explode[5].pngFile, explode[5].texture);
	explode[6].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb6.png", &explode[6].pngFile, explode[6].texture);
	explode[7].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb7.png", &explode[7].pngFile, explode[7].texture);
	explode[8].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb8.png", &explode[8].pngFile, explode[8].texture);
	explode[9].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb9.png", &explode[9].pngFile, explode[9].texture);
	explode[10].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb10.png", &explode[10].pngFile, explode[10].texture);
	explode[11].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb11.png", &explode[11].pngFile, explode[11].texture);
	explode[12].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb12.png", &explode[12].pngFile, explode[12].texture);
	explode[13].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb13.png", &explode[13].pngFile, explode[13].texture);
	explode[14].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb14.png", &explode[14].pngFile, explode[14].texture);
	explode[15].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb15.png", &explode[15].pngFile, explode[15].texture);
	explode[16].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb16.png", &explode[16].pngFile, explode[16].texture);
	explode[17].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb17.png", &explode[17].pngFile, explode[17].texture);
	explode[18].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb18.png", &explode[18].pngFile, explode[18].texture);
	explode[19].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb19.png", &explode[19].pngFile, explode[19].texture);
	explode[20].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb20.png", &explode[20].pngFile, explode[20].texture);
	explode[21].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bomb21.png", &explode[21].pngFile, explode[21].texture);

	HVSTGFX::CAnimation explosion(explode, 22, .28f, 64,64);
	spriteStates.addSprite(explosion);

	idle[0].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid0.png", &idle[0].pngFile, idle[0].texture);
	idle[1].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid1.png", &idle[1].pngFile, idle[1].texture);
	idle[2].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid2.png", &idle[2].pngFile, idle[2].texture);
	idle[3].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid3.png", &idle[3].pngFile, idle[3].texture);
	idle[4].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid0.png", &idle[4].pngFile, idle[4].texture);
	idle[5].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid1.png", &idle[5].pngFile, idle[5].texture);
	idle[6].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid2.png", &idle[6].pngFile, idle[6].texture);
	idle[7].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid3.png", &idle[7].pngFile, idle[7].texture);
	idle[8].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid0.png", &idle[8].pngFile, idle[8].texture);
	idle[9].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid1.png", &idle[9].pngFile, idle[9].texture);
	idle[10].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid2.png", &idle[10].pngFile, idle[10].texture);
	idle[11].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid3.png", &idle[11].pngFile, idle[11].texture);
	idle[12].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid0.png", &idle[12].pngFile, idle[12].texture);
	idle[13].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid1.png", &idle[13].pngFile, idle[13].texture);
	idle[14].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid2.png", &idle[14].pngFile, idle[14].texture);
	idle[15].sprite = HVSTGFX::loadPNGFile("resource/sprites/items/bomb/bombid3.png", &idle[15].pngFile, idle[15].texture);

	HVSTGFX::CAnimation idling(idle, 16, .8f, 32,32);
	spriteStates.addSprite(idling);

	explodeSfx = new CBaseSound("resource/sounds/items/bombExp.wav", false);
	mainBox = new CBaseHitBox();
	physBox = new CBaseHitBox();

}

CBaseBomb::CBaseBomb()
{
	initialize();
}

void CBaseBomb::tick()
{
	if (!exist)
		return;
	
		bombCount = 1;
		if (!exploding)
			//myEvents.ev_AnimEnd(HVSTGFX::animateX(idle, .28, 16, .2f, .27f, x, y, idleCount));  //.07
			spriteStates.currentState = 1;

		if (myEvents.onAnimEnd || goneOff == true)
		{
			exploding = true;
			myEvents.onAnimEnd = false;
			goneOff = true;
			kaboom();
		}
	
}

void CBaseBomb::kaboom()
{
	spriteStates.currentState = 0;
	//myEvents.ev_AnimEnd(HVSTGFX::animateX(explode, .8f, 22, .4f, .54f, x - .11f, y - .05, explodeCount)); //.2
	if (!explodeSfx->active)
		explodeSfx->active = true;
	else
		if (explodeSfx->playCount == 0)
		{

			//explodeSfx->emitSound();
			//explodeSfx->playCount++;
			explodeSfx->playSfx();
		}


	if (myEvents.onAnimEnd)
	{

		exploding = false;
		goneOff = false;
		exist = false;
		mainBox->x = .0f;
		mainBox->y = .0f;
		mainBox->x2 = .0f;
		mainBox->y2 = .0f;
		bombCount = 0;
		//explodeSfx->playCount = 0;
		explodeSfx->reset();
		
	}

}
	