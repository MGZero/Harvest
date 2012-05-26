#include "sprite_state.h"

void CSprite_State::addSprite(HVSTGFX::CAnimation animation)
{
	sprites.push_back(animation);
}

void CSprite_State::addSprite(HVSTGFX::CAnimation *animation)
{
	_sprites.add(animation);
}

void CSprite_State::swapState(HVSTGFX::CAnimation *animation)
{
	previousState = currentState;
	currentState = _sprites.indexOf(animation);
}

HVSTGFX::CAnimation CSprite_State::getSprite(int index)
{
	return sprites[index];
}

void CSprite_State::updateSprite(int index, HVSTGFX::CAnimation animation)
{
	sprites[index] = animation;
}

HVSTGFX::CAnimation* CSprite_State::operator [](int index)
{
	return _sprites[index];
}