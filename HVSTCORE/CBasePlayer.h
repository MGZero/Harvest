#ifndef _CBASEPLAYER_H_
#define _CBASEPLAYER_H_

#include "PhysicalEnt.h"
#include "CBaseSound.h"
#include "CBaseArrow.h"
#include "CBaseBomb.h"
#include "CBaseIronBoot.h"
#include "CBaseBoomerang.h"

class CBasePlayer : public CBasePhysEnt
{
public:
	CBasePlayer();
	CBasePlayer(int ID, std::string name, List<std::string> params){} //this is a dummy, DO NOT USE
	CBasePlayer(std::string name, float x, float y, List<std::string> params){} //this is a dummy, DO NOT USE
	void live();

private:
	void runKeyDown(List<char> keyStrokes);
	void runNoKey();
	void runAnimEnd();

	//==================================================================//
	//===================sprite states==================================//
	//==================================================================//

	//idle states
	HVSTGFX::CAnimation * _sprIdleDown;
	HVSTGFX::CAnimation * _sprIdleUp;
	HVSTGFX::CAnimation * _sprIdleLeft;
	HVSTGFX::CAnimation * _sprIdleRight;

	//walking states
	HVSTGFX::CAnimation * _sprWalkDown;
	HVSTGFX::CAnimation * _sprWalkUp;
	HVSTGFX::CAnimation * _sprWalkLeft;
	HVSTGFX::CAnimation * _sprWalkRight;

	//arrow states
	HVSTGFX::CAnimation * _sprShootLeft;
	HVSTGFX::CAnimation * _sprShootRight;
	HVSTGFX::CAnimation * _sprShootUp;
	HVSTGFX::CAnimation * _sprShootDown;
	
	//standard attacks
	void _dropBomb();
	void _shootArrow();
	void _swingSword();
	void _throwBoomerang();
	void _fireHookshot();

	//specials


};

#endif