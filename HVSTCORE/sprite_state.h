#ifndef _SPRITE_STATE_H
#define _SPRITE_STATE_H

#include "glmain.h"
#include "List.h"
#include <vector>


class CSprite_State
{
public:
	CSprite_State(){currentState = 0; previousState = 0;}
	~CSprite_State(){}
	HVSTGFX::CAnimation getSprite(int index);
	void updateSprite(int index, HVSTGFX::CAnimation animation);
	void addSprite(HVSTGFX::CAnimation animation);
	void addSprite(HVSTGFX::CAnimation * animation);
	int currentState;
	int previousState;

	HVSTGFX::CAnimation* operator[](int index);
	void swapState(HVSTGFX::CAnimation * animation);


private:
	
	std::vector<HVSTGFX::CAnimation> sprites;
	List<HVSTGFX::CAnimation*> _sprites;

};

#endif