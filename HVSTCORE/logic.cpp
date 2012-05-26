#include "logic.h"


HVSTLOG::CBaseHUD::CBaseHUD()
{
#ifdef _DEBUG
	glbl->debugger->writeString("Creating HUD...\n");
#endif

	x = .5f; y = .7f;
	float xVal = 1.45f;
	mouseX = 0.0f; mouseY = 0.0f;

	

	EHud[0].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/hudE.png",
								&EHud[0].imgFile,EHud[0].texture);
	EHud[1].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/hudEP.png",
								&EHud[1].imgFile,EHud[1].texture);

	RHud[0].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/hudR.png",
								&RHud[0].imgFile, RHud[0].texture);
	RHud[1].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/hudRP.png",
								&RHud[1].imgFile, RHud[1].texture);

	cursor.sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/cursor.png",
								&cursor.imgFile, cursor.texture);

	//magic meter =_=
	magMeter[0].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter.png",
											&magMeter[0].imgFile, magMeter[0].texture);
	magMeter[1].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter1.png",
											&magMeter[1].imgFile, magMeter[1].texture);
	magMeter[2].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter2.png",
											&magMeter[2].imgFile, magMeter[2].texture);
	magMeter[3].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter3.png",
											&magMeter[3].imgFile, magMeter[3].texture);
	magMeter[4].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter4.png",
											&magMeter[4].imgFile, magMeter[4].texture);
	magMeter[5].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter5.png",
											&magMeter[5].imgFile, magMeter[5].texture);
	magMeter[6].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter6.png",
											&magMeter[6].imgFile, magMeter[6].texture);
	magMeter[7].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter7.png",
											&magMeter[7].imgFile, magMeter[7].texture);
	magMeter[8].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter8.png",
											&magMeter[8].imgFile, magMeter[8].texture);
	magMeter[9].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter9.png",
											&magMeter[9].imgFile, magMeter[9].texture);
	magMeter[10].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter10.png",
											&magMeter[10].imgFile, magMeter[10].texture);
	magMeter[11].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter11.png",
											&magMeter[11].imgFile, magMeter[11].texture);
	magMeter[12].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter12.png",
											&magMeter[12].imgFile, magMeter[12].texture);
	magMeter[13].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter13.png",
											&magMeter[13].imgFile, magMeter[13].texture);
	magMeter[14].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter14.png",
											&magMeter[14].imgFile, magMeter[14].texture);
	magMeter[15].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter15.png",
											&magMeter[15].imgFile, magMeter[15].texture);
	magMeter[16].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter16.png",
											&magMeter[16].imgFile, magMeter[16].texture);
	magMeter[17].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter17.png",
											&magMeter[17].imgFile, magMeter[17].texture);
	magMeter[18].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter18.png",
											&magMeter[18].imgFile, magMeter[18].texture);
	magMeter[19].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter19.png",
											&magMeter[19].imgFile, magMeter[19].texture);
	magMeter[20].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter20.png",
											&magMeter[20].imgFile, magMeter[20].texture);
	magMeter[21].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter21.png",
											&magMeter[21].imgFile, magMeter[21].texture);
	magMeter[22].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter22.png",
											&magMeter[22].imgFile, magMeter[22].texture);
	magMeter[23].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter23.png",
											&magMeter[23].imgFile, magMeter[23].texture);
	magMeter[24].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter24.png",
											&magMeter[24].imgFile, magMeter[24].texture);
	magMeter[25].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter25.png",
											&magMeter[25].imgFile, magMeter[25].texture);
	magMeter[26].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter26.png",
											&magMeter[26].imgFile, magMeter[26].texture);
	magMeter[27].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter27.png",
											&magMeter[27].imgFile, magMeter[27].texture);
	magMeter[28].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter28.png",
											&magMeter[28].imgFile, magMeter[28].texture);
	magMeter[29].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter29.png",
											&magMeter[29].imgFile, magMeter[29].texture);
	magMeter[30].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter30.png",
											&magMeter[30].imgFile, magMeter[30].texture);
	magMeter[31].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter31.png",
											&magMeter[31].imgFile, magMeter[31].texture);
	magMeter[32].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter32.png",
											&magMeter[32].imgFile, magMeter[32].texture);
	magMeter[33].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter33.png",
											&magMeter[33].imgFile, magMeter[33].texture);
	magMeter[34].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter34.png",
											&magMeter[34].imgFile, magMeter[34].texture);
	magMeter[35].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter35.png",
											&magMeter[35].imgFile, magMeter[35].texture);
	magMeter[36].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter36.png",
											&magMeter[36].imgFile, magMeter[36].texture);
	magMeter[37].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter37.png",
											&magMeter[37].imgFile, magMeter[37].texture);
	magMeter[38].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter38.png",
											&magMeter[38].imgFile, magMeter[38].texture);
	magMeter[39].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter39.png",
											&magMeter[39].imgFile, magMeter[39].texture);
	magMeter[40].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter40.png",
											&magMeter[40].imgFile, magMeter[40].texture);
	magMeter[41].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter41.png",
											&magMeter[41].imgFile, magMeter[41].texture);
	magMeter[42].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter42.png",
											&magMeter[42].imgFile, magMeter[42].texture);
	magMeter[43].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter43.png",
											&magMeter[43].imgFile, magMeter[43].texture);
	magMeter[44].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter44.png",
											&magMeter[44].imgFile, magMeter[44].texture);
	magMeter[45].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter45.png",
											&magMeter[45].imgFile, magMeter[45].texture);
	magMeter[46].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/magMeter46.png",
											&magMeter[46].imgFile, magMeter[46].texture);



	for (int i = 0; i < 10; i++, xVal -= .05f)
		heart[i] = new HVSTLOG::CBaseHeart(x - xVal, y + .1f);

	xVal = 1.45f;
	for (int i = 10; i < 20; i++, xVal -= .05f)
		heart[i] = new HVSTLOG::CBaseHeart(x - xVal, y + .05f);

	heart[19]->active = true;
	heartCount = 20;
	MP = 46;
}

HVSTLOG::CBaseHudButton::CBaseHudButton(int ID, std::string name, List<std::string> params) :
CBaseTheoryEnt(ID, name, params)
{
	_button = params[0][0];

	_buttonPressed = new HVSTGFX::CAnimation(1,0,32,32);
	_buttonReleased = new HVSTGFX::CAnimation(1,0,32,32);

	_buttonPressed->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[atoi(params[1].c_str())]);
	_buttonReleased->addSprite((HVSTGFX::CSprite*)glbl->resources->getResourceList("sprite")[atoi(params[2].c_str())]);

	spriteStates.addSprite(_buttonPressed);
	spriteStates.addSprite(_buttonReleased);
}

void HVSTLOG::CBaseHudButton::runKeyDown(List<char> keyStrokes)
{
	if (keyStrokes.count() != 0)
	{
		if (keyStrokes.indexOf(_button) != -1)
		{

		}
	}
}

void HVSTLOG::CBaseHudButton::runKeyRelease(List<char> keyStrokes)
{
	if (keyStrokes.count() != 0)
	{
		if (keyStrokes.indexOf(_button) != -1)
		{

		}
	}
}

HVSTLOG::CBaseHudButton::~CBaseHudButton()
{
	delete _buttonPressed;
	delete _buttonReleased;
}

void HVSTLOG::CBaseHudButton::live()
{
	CBaseTheoryEnt::live();
}

void HVSTLOG::CBaseHUD::damage()
{
	if (heart[0]->heartGone != 4)
	{
		for (int i = 0; i < 20; i++)
		{
			if (heart[i]->active)
			{
				heart[i]->heartGone++;

				if (heart[i]->heartGone == 4)
				{
					if (i != 0)
					{
						heart[i]->active = false;
						heart[i - 1]->active = true;
					}
				}
				return;
			}
		}
	}
}

//FIXME: Sometimes doesn't properly set active
void HVSTLOG::CBaseHUD::heal()
{
	if (heart[19]->heartGone != 0)
	{
		for (int i = 0; i < 20; i++)
		{
			if (heart[i]->active)
			{
				heart[i]->heartGone--;

				if (heart[i]->heartGone == 0)
				{
					if (i != 19)
					{
						heart[i]->active = false;
						heart[i + 1]->active = true;
						//heart[i + 1]->heartGone = 3;
					}
				}
				return;
			}
		}
	}
}

void HVSTLOG::CBaseHUD::MPUp()
{
	if (MP != 46)
		MP++;
}

void HVSTLOG::CBaseHUD::MPDown()
{
	if (MP != 0)
		MP--;
}

void HVSTLOG::CBaseHUD::setHeartX(int heartCount, float x1)
{
	heart[heartCount]->x = x1;
}

void HVSTLOG::CBaseHUD::setHeartY(int heartCount, float y1)
{
	heart[heartCount]->y = y1;
}

void HVSTLOG::CBaseHUD::moveHUD(float x1, float y1)
{
	x = x1; y = y1;
}

void HVSTLOG::CBaseHUD::drawHUD()
{
	HVSTGFX::createSprite(.1f, .135f, mouseX, mouseY, cursor);

	if (!GetAsyncKeyState(0x45))
		HVSTGFX::createSprite(SCALEX_32, SCALEY_32, x, y, EHud[0]);
	else
		HVSTGFX::createSprite(SCALEX_32, SCALEY_32, x, y, EHud[1]);

	if (!GetAsyncKeyState(0x52))
		HVSTGFX::createSprite(SCALEX_32, SCALEY_32, x + .2f, y - .2f, RHud[0]);
	else
		HVSTGFX::createSprite(SCALEX_32, SCALEY_32, x + .2f, y - .2f, RHud[1]);

	for (int i = 0; i < heartCount; i++)
		HVSTGFX::createSprite(.05f, .0675f, heart[i]->x, heart[i]->y, heart[i]->hearts[heart[i]->heartGone]);

	HVSTGFX::createSprite(.8f, .135f, heart[0]->x, heart[10]->y - .18f, magMeter[MP]);
}

HVSTLOG::CBaseHeart::CBaseHeart(float xS, float yS)
{
	x = xS; y = yS;


	hearts[0].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/heartFull.png", &hearts[0].imgFile, hearts[0].texture);
	hearts[1].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/heart34.png", &hearts[1].imgFile, hearts[1].texture);
	hearts[2].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/heartHalf.png", &hearts[2].imgFile, hearts[2].texture);
	hearts[3].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/heart14.png", &hearts[3].imgFile, hearts[3].texture);
	hearts[4].sprite = HVSTGFX::loadImageFile("resource/sprites/HUD/heartEmp.png", &hearts[4].imgFile, hearts[4].texture);

	heartGone = 0;
	active = false;
}

void HVSTLOG::setUpHeart(float x, float y, HVSTLOG::CBaseHUD * HUD, int index)
{
	HUD->heart[index] = new HVSTLOG::CBaseHeart(x,y);

#ifdef _DEBUG
	if (!HUD->heart[index])
		glbl->debugger->writeString("Failed to created heart\n");
	else
		glbl->debugger->writeString("Successfully created heart\n");
#endif
}