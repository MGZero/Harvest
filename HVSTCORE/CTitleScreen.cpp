#include "CTitleScreen.h"

CTitleScreen::CTitleScreen() 
{
#ifdef _DEBUG
	glbl->debugger->writeString("Creating Title Screen...\n");
#endif
	title.sprite = HVSTGFX::loadImageFile("resource/sprites/title/title.png", &title.imgFile, title.texture);
	_BGM = new CBaseSound("resource/sounds/music/title.ogg", true);
	_onTitle = false;

	this->animationTrigger = new HVSTGFX::CAnimationTrigger();
}

CTitleScreen::~CTitleScreen()
{
	delete _BGM;
	_BGM = 0;
}

void CTitleScreen::render()
{
	HVSTGFX::createSprite(SCALEX_512, SCALEY_512, -1.0f, -3.3f, title);
}

HVSTGFX::CSprite CTitleScreen::getSprite()
{
	return title;
}

void CTitleScreen::live()
{
	CBaseTheoryEnt::live();

	//considering making this event driven
	if (_onTitle)
	{
		//do something
	}
	else
	{
		//do something
	}
}

void CTitleScreen::runKeyDown(List<char> keyStrokes)
{
	if (keyStrokes.count() != 0 && keyStrokes.indexOf((char)13) != -1)
	{
		//go to main game
		_onTitle = false;
	}
}

void CTitleScreen::runNewFrame()
{
	
}