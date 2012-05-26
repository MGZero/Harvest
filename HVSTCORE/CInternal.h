#ifndef _CINTERNAL_H_
#define _CINTERNAL_H_

#include "HED.h"
#include "global_Objects.h"
#include <vector>

typedef std::map<std::string, CBaseTheoryEnt*> entMap;
typedef std::vector<CBaseHitBox*> hbMap;

class CInternal
{
public:
	CInternal(CLayer3_0 * layer, CHED * entityRef);
	~CInternal();

	CBaseTheoryEnt * getEntByIndex(int index);
	CBaseTheoryEnt * getEntByName(std::string name);
	CBaseHitBox getHitboxByIndex(int index);

	void execInternal();
	void drawInternals(CTileSheetX * const tileMap);
	void cleanNulls();
	int * getTileMap();
	void checkCollisions();

private:
	entMap _entities;
	hbMap _hitBoxes;
	int _tiles[2500];

	
	void _execEntities();
	void _execHitBoxes();
	void _drawEntities();
	void _drawTiles(CTileSheetX * const tileMap);
	
};

#endif