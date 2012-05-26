#ifndef _CITEMMANAGER_H_
#define _CITEMMANAGER_H_

#include "CBaseArrow.h"
#include "CBaseBomb.h"
#include "CBaseBoomerang.h"
#include "List.h"

class CItemManager
{
public:
	~CItemManager();

	void updateItems();

	void addArrow();
	void addBomb();
	void createBoomerang();

	CItemManager * initialize();

private:
	CItemManager();

	(CBaseArrow *) _arrows[2];
	(CBaseBomb *) _bombs[3];
	CBaseBoomerang * _boomerang;

	static CItemManager * _singleton;

	void _removeArrow(int i);
	void _removeBomb(int i);
	void _removeBoomerang();

};

#endif