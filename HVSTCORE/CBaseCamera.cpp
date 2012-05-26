#include "CBaseCamera.h"

CBaseCamera::CBaseCamera(float viewX, float viewY, float myX, float myY, float boundX, float boundY, CBaseVector mySpeed, CBasePhysEnt * following, bool engine)
{
#ifdef _DEBUG
	glbl->debugger->writeString("Creating camera...\n");
#endif
		float xVal = .97f;

		viewPortWidth = viewX;
		viewPortHeight = viewY;
		x = myX;
		y = myY;
		xBound = boundX;
		yBound = boundY;
		
		follow = following; //shallow copy, for the love of god, don't delete this when the camera is deleted..
#ifdef _DEBUG
		if (!follow)
			glbl->debugger->writeString("ERROR: CAMERA FOLLOWING ENTITY IS NULL!\n");
#endif
		speed = mySpeed;
		HUD = new HVSTLOG::CBaseHUD();
		HUD->x = (x - xBound) + (170 * SCALEX_1);
		HUD->y = (y + yBound) + (20 * SCALEY_1);

		for (int i = 0; i < 10; i++, xVal -= .05f)
			HVSTLOG::setUpHeart(x - xVal, y + .8f, HUD,i);
		xVal = .97f;

		for (int i = 10; i < 20; i++, xVal -= .05f)
			HVSTLOG::setUpHeart(x - xVal, y + .85f, HUD,i);

		transformation = new HVSTMTH::matrix(3,3);
	
}

CBaseCamera::~CBaseCamera()
{
	delete transformation;
}

void CBaseCamera::live()
{
	static float tempX = x, tempY = y;
	//check if the engine spawned this
	if (!fromEngine)
	{
		delete this;
		return;
	}

	//execute camera functionality

	if (follow)
//check the follow entities position in relation to the camera
	switch (follow->getDirection())
	{
		case HVSTGFX::LEFT:
		case HVSTGFX::RIGHT:
		case HVSTGFX::DOWN:
		case HVSTGFX::UP:

		if (follow->y <= (tempY - yBound) && follow->y >= -2.0)
			tempY -= speed.Y;
		if (follow->y >= (tempY + yBound) && follow->y <= 2.0)
			tempY += speed.Y;
		if (follow->x >= (tempX + xBound) && follow->x <= 1.95)
			tempX += speed.X;
		if (follow->x <= (tempX - xBound) && follow->x >= -1.95)
		tempX -= speed.X;
		break;

	} 

	update(tempX, tempY);

}

void CBaseCamera::update(float newX, float newY)
{

	//check how the camera should move and update
	if (newX > x)
	{
		glTranslatef(-speed.X, 0, 0);
		HUD->x += speed.X;

		for (int i = 0; i < 20; i++)
			HUD->heart[i]->x += speed.X;
	}
	else if (newX < x)
	{
		glTranslatef(speed.X,0,0);
		HUD->x -= speed.X;

		for (int i = 0; i < 20; i++)
			HUD->heart[i]->x -= speed.X;
	}
	else
		glTranslatef(0,0,0);

	if (newY > y )
	{
		glTranslatef(0,-speed.Y,0);
		HUD->y += speed.Y;

		for (int i = 0; i < 20; i++)
			HUD->heart[i]->y += speed.Y;
	}
	else if (newY < y)
	{
		glTranslatef(0,speed.Y,0);
		HUD->y -= speed.Y;

		for (int i = 0; i < 20; i++)
			HUD->heart[i]->y -= speed.Y;
	}
	else
		glTranslatef(0,0,0);
		

	x = newX;
	y = newY;

	
}

void CBaseCamera::snapTo(float newX, float newY)
{
	update(newX, newY);
}