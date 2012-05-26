#ifndef _CLINKCOUSIN_H_
#define _CLINKCOUSIN_H_

#include "CBaseNPC.h"

class CLinkCousin : public CBaseNPC
{
	
public:
	CLinkCousin(){}
	~CLinkCousin(){}
	
	bool getIsOpening(){return isOpening;} //call on roomStart Event
	void executeScene(float x, float y); //call if isOpening is true on roomStart
	void speak(float x, float y); //call when colliding with the player


private:
	std::string openingText[4];
	std::string msg1[1];

	bool isOpening;
	void initialize( bool opening );
	
	inline void runRoomStart();
	inline void runCollide();



};

#endif