#include "theoreticalEnt.h"

CEntityStateTrigger::CEntityStateTrigger()
{
	CBaseEvent * evCreate = new CBaseEvent("Create");
	CBaseEvent * evDestroy = new CBaseEvent("Destroy");
	CBaseEvent * evOutsideMap = new CBaseEvent("Outside Map");
	CBaseEvent * evSleep = new CBaseEvent("Sleep");

	_addEvent(evCreate);
	_addEvent(evDestroy);
	_addEvent(evOutsideMap);
	_addEvent(evSleep);
}

CEntityStateTrigger::~CEntityStateTrigger()
{

}

CBaseTheoryEnt::CBaseTheoryEnt()
{
		_currentAnimState = 0;

		animationTrigger = new HVSTGFX::CAnimationTrigger();
		entityStateTrigger = new CEntityStateTrigger();

		//fire the create event
		entityStateTrigger->getEvent(0)->triggered = true;
		inAction = false;
		//_spriteStates = new CSpriteStateX();
	}

CBaseTheoryEnt::CBaseTheoryEnt(int ID, std::string name, List<std::string> params)
{
	this->_ID = ID;
	this->mapName = name;
	_currentAnimState = 0;

	//make this bitch normal
	myState[0] = state::NORMAL;

	animationTrigger = new HVSTGFX::CAnimationTrigger();
	entityStateTrigger = new CEntityStateTrigger();

	//fire the create event
	entityStateTrigger->getEvent(0)->triggered = true;
}

void CBaseTheoryEnt::initialize(std::string name, float x, float y, std::vector<std::string> params)
{
	this->_name = name;
	this->x = x;
	this->y = y;

	_currentAnimState = 0;

	animationTrigger = new HVSTGFX::CAnimationTrigger();
	entityStateTrigger = new CEntityStateTrigger();

	//fire the create event
	entityStateTrigger->getEvent(0)->triggered = true;
}

CBaseTheoryEnt::~CBaseTheoryEnt()
{
	//runDestroy() is to be called on the derived classes, doing so here may cause problems
	//delete _spriteStates;
	for (int i = 0; i < hitboxes.size(); i++)
	{
		delete hitboxes[i];
		hitboxes[i] = 0;
	}
}

void CBaseTheoryEnt::runCreate()
{
	//this MUST be the last line of code in all of the local event handlers
	entityStateTrigger->getEvent(0)->triggered = false;	
}

void CBaseTheoryEnt::runKeyDown(List<char> keyStrokes){}
void CBaseTheoryEnt::runNewFrame(){}

void CBaseTheoryEnt::doCollisions()
{
	for (std::vector<CBaseHitBox*>::iterator i = hitboxes.begin();
		 i != hitboxes.end(); i++)
	{
		if ((*i)->collisionTrigger->getEvent(0)->triggered)
			runCollide();
	}
}

void CBaseTheoryEnt::checkEvents()
{
	//eventStateTrigger
	//if (entityStateTrigger->getEvent(0)->triggered)
	//	runCreate();
	
	//keyboard trigger
	if (glbl->GKeyboardTrigger->getEvent(0)->triggered)
		runKeyDown(glbl->GKeyboardTrigger->getEvent(0)->keyStrokesDown);

	if (glbl->GKeyboardTrigger->getEvent(4)->triggered)
		runNoKey();

	//frame trigger
	if (glbl->GFrameTrigger->getEvent(0)->triggered)
		runNewFrame();

}

void CBaseTheoryEnt::live()
{
	checkEvents();
	//still needs to be moved...
	Draw();
}

void CBaseTheoryEnt::Draw()
{
	HVSTGFX::CAnimation * temp = spriteStates[spriteStates.currentState];
	HVSTGFX::animateX(temp,x,y); 
}

void CBaseTheoryEnt::draw()
{
	CAnimationX temp = _spriteStates();
	temp.animate(x,y);
}

