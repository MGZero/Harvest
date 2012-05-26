#ifndef _CMAPMANAGER_H_
#define _CMAPMANAGER_H_

#include "CInternal.h"
#include "HMD3.0.h"

class CMapManager
{
public:
	CMapManager();
	~CMapManager();

	void swapHMD(CHMD3_0 * swap);
	

private:
	CHED * _entityRefs;
	CHMD3_0 * _currentHMD;
	std::vector<CInternal> _internalLayers;
	CTileSheetX * _tileSet;

	void _entLive(); //call entity live() methods
	void _allDraw(); //draw everything
	void _createMap(); //call this each cycle.  This will render and make things happen
	void _checkCollisions(); //check the hitboxes
	void _processMap();
};


#endif
