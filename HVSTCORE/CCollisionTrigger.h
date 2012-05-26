#ifndef _CCOLLISIONTRIGGER_H_
#define _CCOLLISIONTRIGGER_H_

#include "CBaseEventTrigger.h"
#include <vector>

//the only state that is to be ignored is NOCOLL
enum collisionState
{
	COLLISION = 0,
	NOCOLL,
	NOTCHECKED
};

class CCollisionTrigger : public CBaseEventTrigger
{
public:
	CCollisionTrigger();
	~CCollisionTrigger();

	void update();
	collisionState collState;
	std::vector<int> IDs;

};

#endif