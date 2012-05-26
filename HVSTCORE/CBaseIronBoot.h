#ifndef _CBASEIRONBOOT_H_
#define _CBASEIRONBOOT_H_

#include "PhysicalEnt.h"

class CBaseIronBoot : public CBasePhysEnt
{
public:
	CBaseIronBoot(){initialize();}
	~CBaseIronBoot(){}

	
private:
	void initialize();
	
};


#endif