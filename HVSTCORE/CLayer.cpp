#include "CLayer.h"

void CLayer::initialize(CLayer data)
{
	layerNum = data.getLayerNum();

	for (int i = 0; i < 2500; i++)
	{
		tiles[i] = data.getTileNum(i);
	}

	hitBoxCount = data.getHBCount();

	for (int i = 0; i < hitBoxCount; i++)
	{
		hitBoxes[i].x = data.hitBoxes[i].x;
		hitBoxes[i].y = data.hitBoxes[i].y;
		hitBoxes[i].x2 = data.hitBoxes[i].x2;
		hitBoxes[i].y2 = data.hitBoxes[i].y2;

		hitBoxes[i].width = data.hitBoxes[i].width;
		hitBoxes[i].height = data.hitBoxes[i].height;
		hitBoxes[i].area = data.hitBoxes[i].area;
	}
}

void CLayer::determineEnt(int ID, float x, float y, int layerNum)
{

	switch (ID)
	{

	

	case 1:
		{
			CBaseBush* data = new CBaseBush();
			HVSTGFX::adjustCoords(x, y);
			data->x = x; data->y = y;
			data->x2 = data->x + SCALEX_16;
			data->y2 = data->y - SCALEY_16;
			bush.insert(bush.end(), data);
			bushCount++;
		}
		break;

	case 2:
		{
			CBaseWater* data = new CBaseWater();
			HVSTGFX::adjustCoords(x, y);
			data->x = x; data->y = y;
			data->x2 = data->x + SCALEX_16;
			data->y2 = data->y - SCALEY_16;
			water.insert(water.end(), data);
			waterCount++;
		}
		break;
		
	default:
		break;
	}
}

void CLayer::clear()
{
	player.clear();
	bush.clear();
	water.clear();

	playerCount = 0;
	bushCount = 0;
	waterCount = 0;

	hitBoxes.clear();
	hitBoxCount = 0;
}

CLayer::~CLayer()
{
	
}