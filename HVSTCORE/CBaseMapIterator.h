#ifndef _CBASEMAPITERATOR_H_
#define _CBASEMAPITERATOR_H_

#include "theoreticalEnt.h"
#include "HMD3.0.h"

class CMapTrigger;

class CBaseMapIterator : public CBaseTheoryEnt
{
public:

	CBaseMapIterator();
	virtual ~CBaseMapIterator();

	void live();
	void applySwapFunc(void (*swapper)(std::string mapID));
	std::string getMapID();
private:

	std::string _mapID;
	
	virtual void _runCollide(CBaseTheoryEnt * collidee);
	CMapTrigger * _mapTrigger;
	void (*_distributeMap)(std::string mapID);
	
	

protected:
	virtual void checkEvents();

	

};

class CMapTrigger : public CBaseEventTrigger
{
public:
	CMapTrigger();
	~CMapTrigger();
	
    void update();

private:
	bool _distMap;

};

#endif