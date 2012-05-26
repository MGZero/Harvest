#include "CLinkCousin.h"

void CLinkCousin::initialize(bool opening)
{

	//events
#define ROOMSTART
#define COLLIDE
	

	isOpening = opening;
	
	openingText[0] = "There you are! Father has been looking for you all day!";
	openingText[1] = "He says he has a job for you before you leave tomorrow.";
	openingText[2] = "I think he said he's working in the house today.";
	openingText[3] = "You'd better hurry though, you know how impatient he can be!";

	msg1[0] = "You'd better hurry, you know how impatient he can be!";



}

void CLinkCousin::executeScene(float x, float y)
{

}

void CLinkCousin::speak(float x, float y)
{

}

void CLinkCousin::runRoomStart()
{
	

		
	
	
}

void CLinkCousin::runCollide()
{

}

