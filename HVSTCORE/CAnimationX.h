#ifndef _CANIMATION_X_
#define _CANIMATION_X_

#include "glew.h"
#include "wglew.h"
#include "FreeImage.h"
#include <vector>
#include "stdlib.h"
#include "List.h"
#include "CSpriteX.h"

class CAnimationX
	{
	public:
		CAnimationX(int count, float speed, int width, int height);
		~CAnimationX();

		//inline CSpriteX getFrame(int index){return *_sprites[index];}
		//CSpriteX getFrameX(int index); //getFrameX
		inline int getNumofFrames(){return _numOfFrames;}
		void addSprite(CSpriteX *sprite);
		inline float getSpeed(){return _speed;}
		inline float getWidth(){return _width;}
		inline float getHeight(){return _height;}
		void clearAnimation();
		bool animate(float x, float y);

	private:
		
		int _numOfFrames;
		float _speed;
		float _width, _height;
		int _frameTracker; //for the animationTrigger
		std::vector<CSpriteX*> _sprites;
		CSpriteX * _currentFrame;
		float _frameCount;
		
		
	};

#endif