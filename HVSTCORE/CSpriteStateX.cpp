#include "CSpriteStateX.h"

CAnimationX CSpriteStateX::operator()(void)
{
	return *_currentState;
}

CSpriteStateX::~CSpriteStateX()
{
	//clean up the vector
	
	if (_sprites.size() > 0)
	{
		std::tr1::unordered_map<std::string, CAnimationX*>::iterator temp;
		for (temp = _sprites.begin(); temp != _sprites.end(); temp++)
		{
			delete temp->second;
			temp->second = 0;
		}
	}
}

CAnimationX CSpriteStateX::getSprite(std::string index)
{
	return *_sprites[index];
}

void CSpriteStateX::updateSprite(std::string index, CAnimationX *animation)
{
	if (animation == 0)
		throw "Bad animation insert";

	_sprites[index] = animation;
}

void CSpriteStateX::addSprite(std::string index, CAnimationX *animation)
{
	_sprites.insert(std::tr1::unordered_map<std::string, CAnimationX*>::value_type(index, animation));
}

void CSpriteStateX::swapState(std::string index)
{
	_previousState = _currentState;
	_currentState = _sprites[index];
}