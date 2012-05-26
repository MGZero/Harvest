#include "CBasePlayer.h"

CBasePlayer::CBasePlayer()
{
	//blah blah blah life goes on...
	//player has no parameters right now
	/*The player is a special case entity that is spawned once and only once on the engine start.  When a new map is loaded, the player is NOT repsawned, it's moved to
	the specified coordinates and then any data from the map or save file is loaded into it*/

	x = 0;
	y = 0;
	x2 = SCALEX_32;
	y2 = -SCALEY_32;
	//=================================================
	//Allocate memory
	//=================================================
	_sprIdleDown = new HVSTGFX::CAnimation(1,0,32,32);
	_sprIdleUp = new HVSTGFX::CAnimation(1,0,32,32);
	_sprIdleLeft  = new HVSTGFX::CAnimation(1,0,32,32);
	_sprIdleRight = new HVSTGFX::CAnimation(1,0,32,32);

	//walking animations
	_sprWalkDown = new HVSTGFX::CAnimation(10,.3,32,32);
	_sprWalkUp = new HVSTGFX::CAnimation(10, .3,32,32);
	_sprWalkLeft = new HVSTGFX::CAnimation(10, .3, 32,32);
	_sprWalkRight = new HVSTGFX::CAnimation(10,.3,32,32);

	//shooting animations
	_sprShootLeft = new HVSTGFX::CAnimation(15, .2,32,32);
	_sprShootRight = new HVSTGFX::CAnimation(15, .2,32,32);

	//==================================================
	//Request resources
	//==================================================
	_sprIdleUp->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[0]);
	_sprIdleDown->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[10]);
	_sprIdleLeft->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[20]);
	_sprIdleRight->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[30]);

	spriteStates.addSprite(_sprIdleUp);
	spriteStates.addSprite(_sprIdleDown);
	spriteStates.addSprite(_sprIdleLeft);
	spriteStates.addSprite(_sprIdleRight);

	for (int i = 0; i < 10; i++)
		_sprWalkUp->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);
	
	spriteStates.addSprite(_sprWalkUp);

	for (int i = 10; i < 20; i++)
		_sprWalkDown->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);

	spriteStates.addSprite(_sprWalkDown);

	for (int i = 20; i < 30; i++)
		_sprWalkLeft->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);

	spriteStates.addSprite(_sprWalkLeft);

	for (int i = 30; i < 40; i++)
		_sprWalkRight->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);

	spriteStates.addSprite(_sprWalkRight);

	for (int i = 40; i < 55; i++)
		_sprShootLeft->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);
	
	spriteStates.addSprite(_sprShootLeft);

	for (int i = 55; i < 70; i++)
		_sprShootRight->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[i]);
	
	spriteStates.addSprite(_sprShootRight);
	spriteStates.swapState(_sprIdleUp);
	
}

void CBasePlayer::live()
{
	CBasePhysEnt::live();
}

void CBasePlayer::runAnimEnd()
{
	
}

void CBasePlayer::runNoKey()
{
	
	switch (direction)
	{
	case HVSTGFX::directions::UP:
		spriteStates.swapState(_sprIdleUp);
		break;

	case HVSTGFX::directions::DOWN:
		spriteStates.swapState(_sprIdleDown);
		break;

	case HVSTGFX::directions::LEFT:
		spriteStates.swapState(_sprIdleLeft);
		break;

	default:
		spriteStates.swapState(_sprIdleRight);
		break;
	}
}

void CBasePlayer::runKeyDown(List<char> keyStrokes)
{
	if (keyStrokes.count() != 0)
	{
		//walk up
		if (keyStrokes.indexOf('W') != -1)
		{
			y += SCALEY_1;
			direction = HVSTGFX::directions::UP;
			spriteStates.swapState(_sprWalkUp);
		}

		//walk down
		if (keyStrokes.indexOf('S') != -1)
		{
			y -= SCALEY_1;
			direction = HVSTGFX::directions::DOWN;
			spriteStates.swapState(_sprWalkDown);
		}

		//walk left
		if (keyStrokes.indexOf('A') != -1)
		{
			x -= SCALEX_1;
			direction = HVSTGFX::directions::LEFT;
			spriteStates.swapState(_sprWalkLeft);
		}

		//walk right
		if (keyStrokes.indexOf('D') != -1)
		{
			x += SCALEX_1;
			direction = HVSTGFX::directions::RIGHT;
			spriteStates.swapState(_sprWalkRight);
		}

		//E & R buttons
		if (keyStrokes.indexOf('E') != -1)
		{

		}
	}
}