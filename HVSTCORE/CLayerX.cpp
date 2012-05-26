#include "CLayerX.h"

CLayerX::~CLayerX()
{
	
}

CLayerX::CLayerX(int num): 
_layerNum(num)
{
	containsPlayer = false;
}

void CLayerX::addEntity(int ID, void * ent)
{
	if (entityMap.Keys().indexOf(ID) == -1)
		entityMap.append(ID, new List<void*>);
	
	entityMap[ID]->add(ent);
}

