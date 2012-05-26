#include "CBaseMapManager.h"

CBaseMapManager::CBaseMapManager(CHMD3_0 * initMap) :
CBaseTheoryEnt()
{
	_currentMap = initMap;
}

CBaseMapManager::~CBaseMapManager()
{
	//remove the reference to the map but DON'T delete it
	_currentMap = 0;
}

void CBaseMapManager::swapMap(std::string mapID)
{
	//_swapMap(glbl->content->retrieveMap(mapID));
}

void CBaseMapManager::_swapMap(CHMD3_0 *map)
{
	_currentMap = map;
	//fire mapChanged event
}

void CBaseMapManager::runMapChange()
{
	//update all entities
	/*int count = _currentMap->_dataStream->layers.count();
	
	for (int i = 0; i < count; i++)
	{
		int countInner = _currentMap->_dataStream->layers[i]->entities.size();
		for (int j = 0; j < countInner; j++)
		{
			//if it's an iterator
			if (int countInner = _currentMap->_dataStream->layers[i]->entities[j]->getID() == 1)
			{
				CBaseMapIterator * temp = 0;
				temp = dynamic_cast<CBaseMapIterator*>(_currentMap->_dataStream->layers[i]->entities[j]);
				temp->applySwapFunc(&CBaseMapManager::swapMap);
			}
		}
	}*/
}

void CBaseMapManager::live()
{
	CBaseTheoryEnt::live();
}

CBaseMapManager * CBaseMapManager::init(CHMD3_0 *initMap)
{
	if (!_singleton)
		_singleton = new CBaseMapManager(initMap);

	return _singleton;
}

void CBaseMapManager::deinit()
{
	if (_singleton)
	{
		delete _singleton;
		_singleton = 0;
	}
}

void CBaseMapManager::_runMap()
{
	if (!_currentMap)
		return;

	_currentMap->createMap();
}