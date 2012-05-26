#ifndef _CLAYER3_0_H
#define _CLAYER3_0_H

#include <iostream>
#include <fstream>
#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include "hvstmth.h"
#include <vector>
#include "hvstphys.h"

//this is a VERY crude band aid - needs to be worked on after glmain is all sorted out
#define SCALEX_1      (2.0f/320.0f)
#define SCALEX_2      SCALEX_1 * 2.0f
#define SCALEX_4      SCALEX_1 * 4.0f
#define SCALEX_8      SCALEX_1 * 8.0f
#define SCALEX_16     SCALEX_1 * 16.0f
#define SCALEX_32     SCALEX_1 * 32.0f
#define SCALEX_64     SCALEX_1 * 64.0f
#define SCALEX_128    SCALEX_1 * 128.0f
#define SCALEX_256    SCALEX_1 * 256.0f
#define SCALEX_512    SCALEX_1 * 512.0f

#define SCALEY_1      (2.0f/240.0f)
#define SCALEY_2      SCALEY_1 * 2.0f
#define SCALEY_4      SCALEY_1 * 4.0f
#define SCALEY_8      SCALEY_1 * 8.0f
#define SCALEY_16     SCALEY_1 * 16.0f
#define SCALEY_32     SCALEY_1 * 32.0f
#define SCALEY_64     SCALEY_1 * 64.0f
#define SCALEY_128    SCALEY_1 * 128.0f
#define SCALEY_256    SCALEY_1 * 256.0f
#define SCALEY_512    SCALEY_1 * 512.0f

class CChunkData;

class CLayer3_0
{
private:
	struct CEntData;

public:

	int tiles[2500];
	std::vector<HVSTMTH::rectangle*> hitboxes;
	std::vector<CEntData*> entData; 

	void addEntity(int ID, std::string name, int x, int y, std::vector<std::string> params);

private:
	struct CEntData
	{
		CEntData(int ID, std::string name, int x, int y, std::vector<std::string> params)
		{
			this->ID = ID;
			this->name = name;
			this->x = y;
			this->y = y;
			this->params = params;
		}
		int ID;
		std::string name;
		int x, y;
		std::vector<std::string> params;
	};
};

#endif