#ifndef _RESTRICTEDENT_H_
#define _RESTRICTEDENT_H_

#include "theoreticalEnt.h"
#include "CBaseHitBox.h"

class CBaseRestrictedEnt : public CBaseTheoryEnt
{
	//restricted entities cannot be spawned through a map, they're core entities such as the camera
public:
	virtual ~CBaseRestrictedEnt();
	CBaseRestrictedEnt(){}
	
private:
	virtual void live();
	CBaseRestrictedEnt(bool engine);

protected:
	bool fromEngine; //if the entity was spawned by the player or the engine
	
};

#endif