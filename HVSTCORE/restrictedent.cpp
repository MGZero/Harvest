#include "restrictedent.h"

void CBaseRestrictedEnt::live()
{
	if (!fromEngine)
		delete this;
}

CBaseRestrictedEnt::CBaseRestrictedEnt(bool engine)
{
	fromEngine = engine;
}

CBaseRestrictedEnt::~CBaseRestrictedEnt()
{
	
}