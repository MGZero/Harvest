#include "NPCTest.h"

CNPCTest::CNPCTest()
{
	initialize(50);
}

CNPCTest::~CNPCTest()
{
	
}

void CNPCTest::initialize(double m)
{
	mass.magnitude = m;
	weight = HVSTPHYS::Calc_Force(mass, 9.81);
	width = .2f; height = .27f;
	

	x = .3f;
	y = .3f;
	
}