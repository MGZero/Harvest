#include "CBaseIronBoot.h"

void CBaseIronBoot::initialize()
{
	mass.magnitude = 89.70;
	weight = HVSTPHYS::Calc_Force(mass, 9.81);
	myCharge.magnitude = -10.5;
}