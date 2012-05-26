#include "CBaseNPC.h"

CBaseNPC::CBaseNPC()
{
	initialize(1);

}

CBaseNPC::~CBaseNPC()
{

}



//used to find distance
double CBaseNPC::AIFindPoint(double xFind, double yFind)
{
	double location;

	location = HVSTMTH::distance(x, y, xFind, yFind);
	return location;
}

double CBaseNPC::AIFindPoint(double *coords)
{
	double location;

	location = HVSTMTH::distance(x, y, coords[0], coords[1]);
	return location;
}

double* CBaseNPC::AIFindCoord(CBaseTheoryEnt entFind)
{
	double coords[2];

	coords[0] = entFind.x;
	coords[1] = entFind.y;

	return coords;
}

void CBaseNPC::initialize(double m)
{

	mass.magnitude = m;
	weight = HVSTPHYS::Calc_Force(mass, 9.81);

}

