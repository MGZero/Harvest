#include "CInternal.h"

CInternal::CInternal(CLayer3_0 * layer, CHED * entityRef)
{
	int hbCount = 0;
	//get the tiles
	for (int i = 0; i < 2500; i++)
	{
		_tiles[i] = layer->tiles[i];
	}

	//create entities
	for (int i = 0; i < layer->entData.size(); i++)
	{
		CBaseTheoryEnt * temp = entityRef->createEnt(layer->entData[i]->ID,layer->entData[i]->name,
													 layer->entData[i]->x,layer->entData[i]->y,layer->entData[i]->params);
		_entities.insert(entMap::value_type(layer->entData[i]->name, temp));

		//inject entity hitboxes

		for (int j =0; j < temp->hitboxes.size(); j++)
			_hitBoxes.push_back(temp->hitboxes[j]);
	}

	//create hitboxes

	for (std::vector<HVSTMTH::rectangle*>::iterator itr = layer->hitboxes.begin();itr != layer->hitboxes.end();itr++)
	{
		HVSTMTH::rectangle * tempRect = *itr;
		CBaseHitBox *temp = new CBaseHitBox(tempRect->x, tempRect->y, tempRect->width, tempRect->height);
		_hitBoxes.push_back(temp);
	}
}

CInternal::~CInternal()
{
	for (entMap::iterator i = _entities.begin(); i != _entities.end();i++)
	{
		delete i->second;
		i->second = 0;
	}

	for (int i = 0; i < _hitBoxes.size(); i++)
	{
		delete _hitBoxes[i];
		_hitBoxes[i] = 0;
	}

	_entities.erase(_entities.begin(), _entities.end());
}

void CInternal::cleanNulls()
{
	//check entities for nulls
	entMap::iterator i = _entities.begin();

	while (i != _entities.end())
	{
		if (i->second == 0)
			_entities.erase(i++);
		else
			i++;
	}

	hbMap::iterator j = _hitBoxes.begin();

	while (j != _hitBoxes.end())
	{
		if (*j == 0)
			_hitBoxes.erase(j++);
		else
			j++;
	}
}

void CInternal::_execEntities()
{
	for (entMap::iterator i = _entities.begin(); i != _entities.end();i++)
		i->second->live();
}

int * CInternal::getTileMap()
{
	int * temp = &_tiles[0];
	return temp;
}

void CInternal::drawInternals(CTileSheetX * const tileMap)
{
	_drawTiles(tileMap);
	_drawEntities();
}

CBaseTheoryEnt * CInternal::getEntByIndex(int index)
{
	entMap::iterator itr = _entities.begin();

	for (int i = 0; i < index; i++, itr++);

	return itr->second;
}

CBaseTheoryEnt * CInternal::getEntByName(std::string name)
{
	return _entities[name];
}

CBaseHitBox CInternal::getHitboxByIndex(int index)
{
	return *_hitBoxes[index];
}

void CInternal::_drawEntities()
{
	for (entMap::iterator i = _entities.begin(); i != _entities.end();i++)
		i->second->draw();
}

void CInternal::execInternal()
{
	_execEntities();
}

void CInternal::checkCollisions()
{
	for (hbMap::iterator i = _hitBoxes.begin(); i != _hitBoxes.end();i++)
	{
		(*i)->checkBoxes(_hitBoxes);
	}
}

void CInternal::_drawTiles(CTileSheetX *const tileMap)
{
	for (int i = 0; i < 2500; i++)
		tileMap->createTile(i, tileMap->getXCoord(i), tileMap->getYCoord(i));
}