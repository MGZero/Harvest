#include "CBaseHitBox.h"

CBaseHitBox::CBaseHitBox(float x1, float y1, float width1, float height1)
{
	x = x1;
	y = y1;
	width = width1;
	height = height1;
	x2 = x + width;
	y2 = y - height;
	area = (width * height);

	_boundingBox = new HVSTMTH::rectangle(x1, y1, width1, height1);
	marked = NOTCHECKED;
}

CBaseHitBox::CBaseHitBox(float x, float y, float radius)
{
	_boundingCircle = new HVSTMTH::circle(x,y,radius);
}

CBaseHitBox::~CBaseHitBox()
{
	if (_boundingBox)
	{
		delete _boundingBox;
		_boundingBox = 0;
	}

	if (_boundingCircle)
	{
		delete _boundingCircle;
		_boundingCircle = 0;
	}
}

float CBaseHitBox::getX()
{
	if (_boundingBox)
		return _boundingBox->x;

	return 0.0;
}

float CBaseHitBox::getY()
{
	if (_boundingBox)
		return _boundingBox->y;

	return 0.0;
}

float CBaseHitBox::getX2()
{
	if (_boundingBox)
		return _boundingBox->x2;

	return 0.0;
}

float CBaseHitBox::getY2()
{
	if (_boundingBox)
		return _boundingBox->y2;

	return 0.0;
}

float CBaseHitBox::getWidth()
{
	if (_boundingBox)
		return _boundingBox->width;

	return 0.0;
}

float CBaseHitBox::getHeight()
{
	if (_boundingBox)
		return _boundingBox->height;

	return 0.0;
}

float CBaseHitBox::getAreaR()
{
	if (_boundingBox)
		return _boundingBox->area();

	return 0.0;
}

float CBaseHitBox::getRadius()
{
	if (_boundingCircle)
		return _boundingCircle->area();

	return 0.0;
}

float CBaseHitBox::getX(float angle)
{
	if (_boundingCircle)
		return cos(angle)*_boundingCircle->radius;

	return 0.0;
}

float CBaseHitBox::getY(float angle)
{
	if (_boundingCircle)
		return sin(angle)*_boundingCircle->radius;

	return 0.0;
}

float CBaseHitBox::getAreaC()
{
	if (_boundingCircle)
		return _boundingCircle->area();

	return 0.0;
}

void CBaseHitBox::setHotSpot(float * x, float * y)
{
	if (_boundingBox)
		_boundingBox->setHotSpot(x,y);
}


//call this at the end of every collision check
void CBaseHitBox::reset()
{
	marked = NOTCHECKED;
	_entIDs.erase(_entIDs.begin(), _entIDs.end());
}

int CBaseHitBox::getBoundEnt()
{
	return _boundEnt;
}

bool CBaseHitBox::pointFree(float x, float y)
{
	return true;
}


void CBaseHitBox::setMapReference(std::vector<CBaseHitBox*> &mapHitBoxes)
{
	_mapHitBoxes = mapHitBoxes;
}

bool CBaseHitBox::contains(CBaseHitBox & hitbox)
{
	//make a temp rectangle
	if (_boundingBox)
	{
		bool result = false;
		HVSTMTH::rectangle temp(hitbox.x,hitbox.y,hitbox.width,hitbox.height);
		
		//check for a collision, grab ID, and change collision state
		if ((result = _boundingBox->contains(temp)))
		{
			_entIDs.insert(_entIDs.begin(),hitbox.getBoundEnt());
			marked = COLLISION;
		}
		else if(marked != COLLISION)
		{
			marked = NOCOLL;
		}
		return result;
	}

	return false;
	
}

void CBaseHitBox::checkBoxes(std::vector<CBaseHitBox*> & mapHitBoxes)
{
	for (std::vector<CBaseHitBox*>::iterator itr = mapHitBoxes.begin(); itr != mapHitBoxes.end(); itr++)
		contains(**itr);
	
	if(marked == COLLISION)
		updateTrigger();
}

bool CBaseHitBox::contains(float x, float y)
{
	if (_boundingBox)
		return _boundingBox->contains(x,y);
	else if (_boundingCircle)
		return _boundingCircle->contains(x,y);
	
	return false;
}

//call this AFTER this box has checked all other boxes
void CBaseHitBox::updateTrigger()
{
	collisionTrigger->collState = marked;
	collisionTrigger->IDs = _entIDs;
	collisionTrigger->update();
	reset();
}