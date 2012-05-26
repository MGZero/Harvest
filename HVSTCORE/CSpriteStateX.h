#ifndef _CSPRITESTATEX_H
#define _CSPRITESTATEX_H

#include "glmain.h"
#include "CAnimationX.h"
#include "List.h"
#include <vector>

class CSpriteStateX
{
public:
	~CSpriteStateX();
	CAnimationX getSprite(std::string index);
	void updateSprite(std::string index, CAnimationX * animation);
	void addSprite(std::string index, CAnimationX * animation);

	CAnimationX operator()(void);
	void swapState(std::string index);
private:
	
	CAnimationX * _currentState;
	CAnimationX * _previousState;
	std::tr1::unordered_map<std::string, CAnimationX*> _sprites;

};

#endif