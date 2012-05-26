#include "CNPCDemo.h"
#include "global_Objects.h"

CNPCDemo::CNPCDemo()
{
	initialize();
}

void CNPCDemo::initialize()
{

	mass.magnitude = 54.3;
	weight = HVSTPHYS::Calc_Force(mass, 9.81);
	std::string text[3];
	soundMain.mySound = NULL;

	text[0] = "Wait..why am I here?  This is only ademo!";
	text[1] = "Hmm? This is programmed by someone  named MG-Zero?";
	text[2] = "Oh, my. This will never get finished..";

	spriteMain.sprite = HVSTGFX::loadImageFile("resource/sprites/npc/zelda/zelda0.png", &spriteMain.imgFile, spriteMain.texture);
	
	if (!spriteMain.sprite)
		glbl->debugger->writeString("Failed to load zelda0.png");
		
	
	
	//dialog1 = new CBaseTXTBox(3, text);
	
	x = .2f;
	y = .5f;
	x2 = .7f;
	y2 = .23f;
	width = .2f;
	height = .27f;

	mainBox = new CBaseHitBox(x, y, .15f, .24f);
}

CNPCDemo::~CNPCDemo()
{
	//delete dialog1;
	delete mainBox;
}

void CNPCDemo::speak(float x, float y)
{

//dialog1->drawTextBoxX(x, y, true);

}