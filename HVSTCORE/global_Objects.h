#ifndef _GLOBAL_OBJECTS_H_
#define _GLOBAL_OBJECTS_H_
#include "DBG.h"
#include <string>
#include <sstream>
#include "linkedlist.h"
#include "list.h"
#include "graph.h"
#include "matrix.h"
#include "conio.h"
#include <iostream>
#include <map>
#include "CBaseHitBox.h"
#include "inputManager.h"
#include "CFrameTrigger.h"
#include "CResources.h"
#include "CBaseTextTrigger.h"
#include "CMessage.h"
#include "HCF.h"


#define DEBUG

class CCONSOLE
{
public:
	CCONSOLE();
	~CCONSOLE();

	void write();
	void writeLine();

	//std::ostream cout;
	//std::istream cin;
	std::string data;

private:
	std::filebuf consoleDump;
};



class GLOBALS
{
	
public:
	GLOBALS();
	~GLOBALS();

	void initInput();
	std::stringstream stringWork;
	CCONSOLE * cmd;
	CDBG * debugger;
	HVSTInput::CkeyboardTrigger * GKeyboardTrigger;
	CFrameTrigger * GFrameTrigger;
	CTextTrigger * GTextTrigger;
	CResources * resources;
	CHCF * content;

	float tileCoordX[2500];
	float tileCoordY[2500];

	void setUpTileCoords();

	static class FUNCTIONS
	{
	public:
		static void changeMap(std::string mapName); //pass the HMD file name
	};

	
};

extern GLOBALS * glbl;


#endif