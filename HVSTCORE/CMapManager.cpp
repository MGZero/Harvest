#include "CMapManager.h"

CMapManager::CMapManager()
{
	_entityRefs = new CHED();
}

CMapManager::~CMapManager()
{
	delete _entityRefs;
}

void CMapManager::_createMap()
{
	_checkCollisions();
	_entLive();
	_allDraw();
}

void CMapManager::_entLive()
{
	for (std::vector<CInternal>::iterator itr = _internalLayers.begin(); itr != _internalLayers.end(); itr++)
	{
		itr->execInternal();
	}
}

void CMapManager::_checkCollisions()
{
	for (std::vector<CInternal>::iterator itr = _internalLayers.begin(); itr != _internalLayers.end(); itr++)
		(itr)->checkCollisions();
}

void CMapManager::swapHMD(CHMD3_0 * swap)
{
	_currentHMD = swap;
	_processMap();
}

void CMapManager::_processMap()
{
	//process layers
	for (int i = 0; i < _currentHMD->_dataStream->layers.count(); i++)
	{
		CInternal temp(_currentHMD->_dataStream->layers[i], _entityRefs);
		_internalLayers.insert(_internalLayers.end(), temp);
	}

	//process tileset
	_tileSet = glbl->resources->_tileData[_currentHMD->_dataStream->peekContentStream().getTileResource()];
}

void CMapManager::_allDraw()
{
	for (std::vector<CInternal>::iterator itr = _internalLayers.begin(); itr != _internalLayers.end(); itr++)
	{
		CInternal * const temp = &*itr;
		temp->drawInternals(_tileSet);
	}
}



