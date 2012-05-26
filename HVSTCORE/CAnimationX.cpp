#include "CAnimationX.h"

void CAnimationX::clearAnimation()
{
	_sprites.clear();
}

CAnimationX::~CAnimationX()
{
	clearAnimation();
}

void CAnimationX::addSprite(CSpriteX *sprite)
{
	_sprites.insert(_sprites.begin(),sprite);

	if (_sprites.size() == 1)
		_currentFrame = _sprites[0];
}

bool CAnimationX::animate(float x, float y)
{
	_sprites[(int)_frameCount]->createImage(x,y);
		
	_frameCount += _speed;
	if (_frameCount >= _numOfFrames)
	{
		_frameCount = 0;
		return true;
	}
	else
		return false;
}