#include "global_Objects.h"

CCONSOLE::CCONSOLE()
{
	consoleDump.open("console.dat",std::ios::out|std::ios::in);
}

void CCONSOLE::write()
{
	cputs(data.c_str());
	data.clear();
}

void CCONSOLE::writeLine()
{
	data += "\n";
	cputs(data.c_str());
	data.clear();
}

CCONSOLE::~CCONSOLE()
{
	consoleDump.close();
}

void GLOBALS::initInput()
{
	debugger->writeString("initializing input...");
	//glutInit(0,0);
	GKeyboardTrigger = GKeyboardTrigger->initialize();
	if (GKeyboardTrigger)
		debugger->writeString("input initialized!");
	else
	{
		debugger->writeString("input failed to initialize! Aborting...");
		throw "invalid input";
	}
	setUpTileCoords();	
}

GLOBALS::GLOBALS()
{
	
	//FMOD::System_Create(&tempSys);		// Create the main system object.
	//		tempSys->init(100, FMOD_INIT_NORMAL, 0);	// Initialize FMOD.
	debugger = new CDBG("debugDump.DBG");
	cmd = new CCONSOLE();
	debugger->confirm();
	GFrameTrigger = GFrameTrigger->initialize();
	GTextTrigger = GTextTrigger->init();
	resources = resources->init();
	//content = content->initialize("Resource/Test.HCF");
}

void GLOBALS::setUpTileCoords()
{
	//float x = -2.5f, y = -3.375f; 
	float x = -(SCALEX_1*400.0), y = -(SCALEY_1*400.0);
	//set up tile coordinates
	for (int i = 0; i < 2500; i++)
	{
		static int counter = 0;
		tileCoordX[i] = x;
		tileCoordY[i] = y;

		counter++;

		x += 16*SCALEX_1;//.1f;
		if (counter == 50)
		{
			counter = 0;
			x = -(SCALEX_1*400.0);
			y += 16*SCALEY_1;//.135f;
		}
	}
}

GLOBALS::~GLOBALS()
{
	delete debugger;
	delete cmd;
	resources->release();

	//release event triggers
	GFrameTrigger->release();
	GTextTrigger->release();
}

/************************************************
=================================================
============GLOBAL FUNCTION ONLY HERE============
=================================================
************************************************/

void GLOBALS::FUNCTIONS::changeMap(std::string mapName)
{
	
}