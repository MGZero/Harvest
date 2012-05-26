#ifndef _CBASEMAPMANAGER_H_
#define _CBASEMAPMANAGER_H_

#include "restrictedEnt.h"
#include "HMD3.0.h"
#include "CBaseMapIterator.h"



class CBaseMapManager : public CBaseTheoryEnt
{
public:
	
	CBaseMapManager * init(CHMD3_0 * initMap = 0);
	void deinit();

	void live();

	//when the collision event of a iterator is fired, call this
	static void swapMap(std::string mapID);

private:
	CBaseMapManager(CHMD3_0 * initMap = 0);
	virtual ~CBaseMapManager();

	CBaseMapManager * _singleton;
	CHMD3_0 * _currentMap;
	
	void _swapMap(CHMD3_0 * map); //this is called by the public swapMap and actually swaps the current map.  It also fires the mapChanged Event, which entities will use to set themselves up (iterators, the player etc)
	void _runMap();

	void runMapChange();
};

#endif