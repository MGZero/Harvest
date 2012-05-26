#ifndef _CBASEHITBOX_H_
#define _CBASEHITBOX_H_

#include "HVSTMTH.h"
#include "list.h"
#include "CCollisionTrigger.h"

class CBaseHitBox
{

public:
	
	CBaseHitBox(float x1, float y1, float width1, float height1);
	CBaseHitBox(float x, float y, float radius);
	~CBaseHitBox();
	
	float x, y, x2, y2;
	float width, height;
	float area;
	collisionState marked; //if true, there is at least one collision with another hitbox

	//rectangle
	float getX();
	float getY();
	float getX2();
	float getY2();
	float getWidth();
	float getHeight();
	float getAreaR();

	//circle
	float getRadius();
	float getX(float angle);
	float getY(float angle);
	float getAreaC();

	//triggers
	CCollisionTrigger * collisionTrigger;

	void setHotSpot(float * x, float * y);

	//various methods
	bool pointFree(float x, float y); //checks to see if the given point is within another hitbox
	void setMapReference(std::vector<CBaseHitBox*>&  mapHitBoxes); //sets a reference to every hitbox in the map
	void reset();
	bool contains(float x, float y); //checks if this hitbox contains another point
	bool contains(CBaseHitBox & hitbox); //checks if this contains another hitbox.  If so, it also grabs the associated entityID
	int getBoundEnt();
	void updateTrigger();
	void checkBoxes(std::vector<CBaseHitBox*> & mapHitBoxes);

private:
	CBaseHitBox(){};
	HVSTMTH::circle * _boundingCircle;
	HVSTMTH::rectangle * _boundingBox;
	std::vector<int> _entIDs;
	std::vector<CBaseHitBox*> _mapHitBoxes; //FOR THE LOVE OF GOD, BE CAREFUL WITH THIS

	int _boundEnt; //the entity that this hitbox belongs to
	int _currentIndex;
	
};

#endif