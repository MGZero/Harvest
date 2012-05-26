#include "CBaseMapIterator.h"

CBaseMapIterator::CBaseMapIterator() :
CBaseTheoryEnt()
{

}

CBaseMapIterator::~CBaseMapIterator()
{

}

void CBaseMapIterator::live()
{
	CBaseTheoryEnt::live();
}

void CBaseMapIterator::checkEvents()
{
	CBaseTheoryEnt::checkEvents();
}

void CBaseMapIterator::applySwapFunc(void (*swapper)(std::string))
{
	_distributeMap = swapper;
}

void CBaseMapIterator::_runCollide(CBaseTheoryEnt * collidee )
{
	_distributeMap(_mapID);
}

std::string CBaseMapIterator::getMapID()
{
	return _mapID;
}

void CMapTrigger::update()
{
	if (_distMap)
	{
		signalHandler(_events["distribute"]);
		_distMap = false;
	}
}

CMapTrigger::CMapTrigger()
{
	_addEvent(new CBaseEvent("distribute"));
}

CMapTrigger::~CMapTrigger()
{

}