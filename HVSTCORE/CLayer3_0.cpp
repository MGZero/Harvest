#include "CLayer3_0.h"


void CLayer3_0::addEntity(int ID, std::string name, int x, int y, std::vector<std::string> params)
{
	//ENT_FACTORY(ID)
	entData.push_back(new CEntData(ID, name, x, y, params)); 
}