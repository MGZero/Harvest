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

  File:    HVSTPHYS.h
  Authors: Steve Calandra


  -----------------------------------------------------------------------------       

  December 15 2010
	- Added code audit warning notice. (Jon)

   October 25 08
	
	  File Created.

*********************************************************************************/

/* WARNING(Jon)
	INFO: USE OF DOUBLE ON SOME VARIABLES MAY BE RESPONSIBLE FOR MULTIPLE COMPILER WARNINGS WHICH CAUSE VARIABLES TO CONVERT FROM DOUBLE TO FLOAT.

	SOLUTION: SWITCH VARIABLES IN HVSPHYS TO USING FLOAT
*/

#ifndef _HVSTPHYS_H_
#define _HVSTPHYS_H_
#include "HVSTMTH.h"


#define G .0000000000667f

		//if the collision involves a squishy object, it's automatically moslty elastic.
		//if the collision involves a soft object, it's automatically mostly inelastic
		//if the collision involves a squishy and soft object, then it will be determined by subtracting the two numbers
		//if it involves two hard objects, then it will be determined by subtracting the two numbers

#define HEAVY_SQUISH 0
#define HIGH_SQUISH 1
#define SQUISH 2
#define LOW_SQUISH 3
#define LIGHT_SQUISH 4

#define HEAVY_SOFT  5
#define HIGH_SOFT 6
#define SOFT 7
#define LOW_SOFT 8
#define LIGHT_SOFT 9

#define LIGHT_HARD 10
#define LOW_HARD 11
#define HARD 12
#define HIGH_HARD 13
#define HEAVY_HARD 14

using namespace HVSTMTH;

namespace HVSTPHYS
{
	//base physics units classes
	

	//vector units
	class CForce       : public CBaseVector{};
	class CVelocity    : public CBaseVector{};
	class CAccel       : public CBaseVector{};
	class CMomentum    : public CBaseVector{};
	class CDistance    : public CBaseVector{};
	class CCharge      : public CBaseVector{};

	//scalar units
	class CEnergy      : public CBaseScalar{};
	class CTime        : public CBaseScalar{};
	class CMass        : public CBaseScalar{};
	class CSpringC     : public CBaseScalar{};
	class CPower       : public CBaseScalar{};

	//functions
	//done
	CForce Calc_Force(CMass mass, CAccel accel); //f = ma
	CForce Calc_Force(CMass mass, float accel);
	CForce Calc_Force(CEnergy work, CDistance distance); //w = fd

	CAccel Calc_Accel(CMass mass, CForce force); //a = f/m
	CAccel Calc_Accel(CVelocity vi, CVelocity vf, CTime time); //a = (vf-vi)/t
	CAccel Calc_Accel(CVelocity vi, CDistance distance, CTime time); //a = 2d/t² - vit
	CAccel Calc_Accel(CDistance distance, CTime time); //a = 2d/t²

	CEnergy Calc_Kinetic(CMass mass, CVelocity velocity); //ke = 1/2mv²

	CMomentum Calc_Moment(CVelocity velocity, CMass mass); //p = mv

	CVelocity Calc_Velocity(CDistance distance, CTime time); //v = d/t
	CVelocity Calc_Velocity(CMomentum momentum, CMass mass); //v = p/m
	CVelocity Calc_Velocity(CMass mass1, CMass mass2, CVelocity vel1, CVelocity vel2); // v = ((m1 - m2)/(m1 + m2))v1 + (2m2/(m1 + m2))v2
	CVelocity Calc_Velocity(CVelocity vel1, CVelocity vel2); // v = 2v1 - v2
	CVelocity Calc_Velocity(CVelocity vel1); //v = v1
	void Calc_VelocityS(CVelocity &vel1, CVelocity &vel2); //v1 = v2  v2 = v1
	CVelocity Calc_VelocityM(CMass mass1, CMass mass2, CVelocity vel1, CVelocity vel2); // v = (m1v1 + m2v2)/(m1 + m2) conservation of momentum

	CPower Calc_Power(CEnergy work, CTime time); //p = w/t

	CDistance Calc_Distance(CVelocity vi, CAccel accel, CTime time); //d = vit + 1/2at²
	CDistance Calc_Distance(CAccel accel, CTime time); //d = 1/2at²
	CDistance Calc_Distance(CEnergy springEn, CSpringC constant); //d = sqrt(2pe/k)

	int calc_CollisionScale(int hardness1, int hardness2);

	
	


};
#endif



	
