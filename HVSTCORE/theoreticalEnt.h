#ifndef _THEORETICALENT_H_
#define _THEORETICALENT_H_

#include "event.h"
#include "inputManager.h"
#include "glMain.h"
#include "HVSTPHYS.h"
#include <iostream>
#include "CEntRelation.h"
#include "CLayerX.h"
#include "CBaseTimer.h"
#include "sprite_state.h"
#include "CSpriteStateX.h"
#include "CBaseHitBox.h"
#include <vector>

enum state
{
	NORMAL = 1,
	DEAD,
	INVINCIBLE,
	INVISIBLE,
	NOCLIP,
	AIOFF,
	DISABLED
};

class CEntityStateTrigger : public CBaseEventTrigger
{
public:
	~CEntityStateTrigger();
	CEntityStateTrigger();
	void update();
};

class CBaseTheoryEnt
{
public:
	CBaseTheoryEnt();
	CBaseTheoryEnt(int ID, std::string name, List<std::string> params);

	virtual ~CBaseTheoryEnt();

	virtual void initialize(std::string name, float x, float y, std::vector<std::string> params);
	virtual void live(); //execute logic and update the sprite state
	void Draw();
	void draw();
	void doCollisions();
	void startTimer(int &timerRef, int ticks);
	void timerZero(bool &timerRef);
	inline int getDirection() { return direction;}
	inline int getID(){ return _ID; }

	std::vector<CBaseHitBox*> hitboxes;
	CBaseHitBox* boundary; //This is for checking if something is within range of potential collision or field of view and shit like that
	
	//sprite stuff
	CSprite_State spriteStates;

	//coordinates
	float x, y; 
	float x2, y2;

	HVSTMTH::CBaseVector position;
	HVSTMTH::CBaseVector position2;

	

protected:
	
	//these will each check if their respective event has been called, and then they'll execute
	virtual void runMapStart(){}
	virtual void runMapEnd(){}
	virtual void runCreate();
	virtual void runDestroy(){}
	virtual void runAnimEnd(){}
	virtual void runInteract(){}
	virtual void runNewFrame();
	virtual void runKeyDown(List<char> keyStrokes);
	virtual void runKeyRelease(List<char> keyStrokes){};
	virtual void runNoKey(){};
	virtual void runCollide(){};
	virtual void runMapChange(){}
	std::string entName; //the entity name, ex: ent_Sound
	std::string mapName; //the map name, ex: sound1
	int _ID;
	std::string _name;
	
	CSpriteStateX  _spriteStates;
	HVSTGFX::CAnimationTrigger * animationTrigger;
	CEntityStateTrigger * entityStateTrigger;
	CTimerTrigger * timerTrigger;
	virtual void checkEvents();
	HVSTGFX::CAnimation * _currentAnimState;
	bool inAction;
	int direction;
	bool moving;
	state myState[10];


	
};


#endif