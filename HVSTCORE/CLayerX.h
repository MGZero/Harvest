#ifndef _CLAYER_X_
#define _CLAYER_X_

#include "CBaseHitBox.h"
#include "dictionary.h"

class CLayerX
{
public:
	CLayerX(int num);
	~CLayerX();
	
	List<CBaseHitBox *> hitboxes;
	dictionary<int, List<void *>*> entityMap;
	int tiles[2500];
	bool containsPlayer;

	void addEntity(int ID, void * ent);
	int entCount;
private:
	const int _layerNum;
};

#endif
