/********************************************************************************

  Copyright © 2008 Crystal Rook Software

  -----------------------------------------------------------------------------

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  -----------------------------------------------------------------------------       

  File:    HVSTPHYS.cpp
  Authors: Steve Calandra


  -----------------------------------------------------------------------------       

   October 25 08
	
	  File Created.

*********************************************************************************/


#include "HVSTPHYS.h"
#include "HVSTMTH.h"

int HVSTPHYS::calc_CollisionScale(int hardness1, int hardness2)
{
	if ( (hardness1 >= 0 && hardness1 <= 4) || (hardness2 >= 0 && hardness2 <= 4) ) //if there is a squishy object involved..
	{
		return 1; //mostly elastic
	}
	else if ( (hardness1 >= 5 && hardness1 <= 9 ) || (hardness2 >= 5 && hardness2 <= 9 ) ) //if there's a soft object involved
	{
		return 0; //mostly inelastic
	}
	else if ( ( (hardness1 >= 0 && hardness1 <= 4) && (hardness2 >= 5 && hardness2 <= 9) ) || (hardness2 >= 0 && hardness2 <= 4) && (hardness1 >= 5 && hardness1 <= 9) ) //soft and squishy
	{
		int determinant = 0;

		determinant = abs(hardness1 - hardness2);
		if (determinant <= 4)
			return 1;
		else
			return 0;
	}
	else if ( (hardness1 >= 10 && hardness1 <= 14) && (hardness2 >= 10 && hardness2 <= 14) )
	{
		int determinant = 0;

		determinant = abs(hardness1 - hardness2);
		if (determinant >= 2)
			return 1;
		else
			return 0;
	}
	return 0;
}

void CBaseVector::calcDirection()
{
	float temp = 0;

	temp = tan(Y/X);
	direction = HVSTMTH::radToDeg(temp);
}

void CBaseVector::breakUp()
{
	X = magnitude * sinh(direction);
	Y = magnitude * cosh(direction);
}

void CBaseVector::normalize()
{
	magnitude = sqrt((X*X) + (Y*Y));
}

HVSTPHYS::CForce HVSTPHYS::Calc_Force(CMass mass, CAccel accel)
{
	CForce tempForce;

	tempForce.magnitude = mass.magnitude * accel.magnitude;
	return tempForce;
}

HVSTPHYS::CForce HVSTPHYS::Calc_Force(CEnergy work, CDistance distance)
{
	CForce tempForce;

	tempForce.magnitude = work.magnitude/distance.magnitude;
	return tempForce;
}

HVSTPHYS::CForce HVSTPHYS::Calc_Force(CMass mass, float accel)
{
	CForce tempForce;

	tempForce.magnitude = mass.magnitude*accel;
	return tempForce;
}

HVSTPHYS::CDistance HVSTPHYS::Calc_Distance(CAccel accel, CTime time)
{
	CDistance tempDist;

	tempDist.magnitude = (.5)*accel.magnitude*HVSTMTH::raiseTo(time.magnitude,2);
	return tempDist;
}

HVSTPHYS::CDistance HVSTPHYS::Calc_Distance(CEnergy springEn, CSpringC constant)
{
	CDistance tempDist;

	tempDist.magnitude = sqrt(2*springEn.magnitude/constant.magnitude);
	return tempDist;
}

HVSTPHYS::CDistance HVSTPHYS::Calc_Distance(CVelocity vi, CAccel accel, CTime time)
{
	CDistance tempDist;

	tempDist.magnitude = (vi.magnitude*time.magnitude) + 
						 (.5)*accel.magnitude*HVSTMTH::raiseTo(time.magnitude,2);
	return tempDist;
}

HVSTPHYS::CVelocity HVSTPHYS::Calc_Velocity(CMass mass1, CMass mass2, CVelocity vel1, CVelocity vel2)
{
	CVelocity tempVel;
	tempVel.magnitude = ((mass1.magnitude - mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel1.magnitude;
	tempVel.magnitude += ((2*mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel2.magnitude;

	tempVel.X = ((mass1.magnitude - mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel1.X;
	tempVel.X += ((2*mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel2.X;

	tempVel.Y = ((mass1.magnitude - mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel1.Y;
	tempVel.Y += ((2*mass2.magnitude)/(mass1.magnitude + mass2.magnitude))*vel2.Y;

	return tempVel;
}

HVSTPHYS::CVelocity HVSTPHYS::Calc_Velocity(CVelocity vel1, CVelocity vel2)
{
	CVelocity tempVel;

	tempVel.magnitude = 2*vel1.magnitude - vel2.magnitude;
	tempVel.X = 2*vel1.X - vel2.X;
	tempVel.Y = 2*vel1.Y - vel2.Y;

	return tempVel;
}

HVSTPHYS::CVelocity HVSTPHYS::Calc_Velocity(CVelocity vel1)
{
	return vel1;
}

void HVSTPHYS::Calc_VelocityS(CVelocity &vel1, CVelocity &vel2)
{
	CVelocity tempVel = vel1;

	vel1 = vel2;
	vel2 = tempVel;

}

HVSTPHYS::CVelocity HVSTPHYS::Calc_VelocityM(CMass mass1, CMass mass2, CVelocity vel1, CVelocity vel2)
{
	CVelocity tempVel;

	tempVel.magnitude = ((mass1.magnitude * vel1.magnitude) + (mass2.magnitude * vel2.magnitude))/(mass1.magnitude + mass2.magnitude);
	tempVel.X = ((mass1.magnitude * vel1.X) + (mass2.magnitude * vel2.X))/(mass1.magnitude + mass2.magnitude);
	tempVel.Y = ((mass1.magnitude * vel1.Y) + (mass2.magnitude * vel2.Y))/(mass1.magnitude + mass2.magnitude);

	return tempVel;
}


HVSTPHYS::CVelocity HVSTPHYS::Calc_Velocity(CMomentum momentum, CMass mass)
{
	CVelocity tempVel;

	tempVel.magnitude = (momentum.magnitude)/(mass.magnitude);
	tempVel.X = (momentum.X)/(mass.magnitude);
	tempVel.Y = (momentum.Y)/(mass.magnitude);

	return tempVel;
}

HVSTPHYS::CEnergy HVSTPHYS::Calc_Kinetic(CMass mass, CVelocity velocity)
{
	CEnergy tempKE;

	tempKE.magnitude = .5 * (mass.magnitude)*(HVSTMTH::raiseTo(velocity.magnitude, 2));
	return tempKE;
}

HVSTPHYS::CPower HVSTPHYS::Calc_Power(CEnergy work, CTime time)
{
	CPower tempPower;

	tempPower.magnitude = work.magnitude/time.magnitude;
	return tempPower;
}

HVSTPHYS::CAccel HVSTPHYS::Calc_Accel(CMass mass, CForce force)
{
	CAccel tempAccel;

	tempAccel.magnitude = force.magnitude/mass.magnitude;
	return tempAccel;
}

HVSTPHYS::CAccel HVSTPHYS::Calc_Accel(CVelocity vi, CDistance distance, CTime time)
{
	CAccel tempAccel;

	tempAccel.magnitude = ((2*distance.magnitude)/HVSTMTH::raiseTo(time.magnitude,2)) - (vi.magnitude*time.magnitude);
	return tempAccel;
}

HVSTPHYS::CAccel HVSTPHYS::Calc_Accel(CDistance distance, CTime time)
{
	CAccel tempAccel;

	tempAccel.magnitude = (2*distance.magnitude)/HVSTMTH::raiseTo(time.magnitude,2);
	return tempAccel;
}

HVSTPHYS::CAccel HVSTPHYS::Calc_Accel(CVelocity vi, CVelocity vf, CTime time)
{
	CAccel tempAccel;

	tempAccel.magnitude = (vf.magnitude - vi.magnitude)/time.magnitude;
	return tempAccel;
}

HVSTPHYS::CMomentum HVSTPHYS::Calc_Moment(CVelocity velocity, CMass mass)
{
	CMomentum tempMom;

	tempMom.magnitude = velocity.magnitude*mass.magnitude;
	return tempMom;
}

HVSTPHYS::CVelocity HVSTPHYS::Calc_Velocity(CDistance distance, CTime time)
{
	CVelocity tempVel;

	tempVel.magnitude = distance.magnitude/time.magnitude;
	return tempVel;
}
