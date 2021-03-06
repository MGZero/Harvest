/********************************************************************************

  Copyright © 2008 Crystal Rook Software

  -----------------------------------------------------------------------------

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  -----------------------------------------------------------------------------       

  File:    HVSTDATMAIN.cpp
  Authors: Steve Calandra
  Notes:   This is the function implementation for the class and examples of using it.

  Version History
  V1.0 - 10/25/08 - First Build released


  -----------------------------------------------------------------------------       

   October 23 08
	
	  File Created.

*********************************************************************************/

#include "HVSTMTH.h"

double HVSTMTH::radToDeg(double radians)
{
	double degrees;

	degrees = (radians*PIRAD)/PI;
	return degrees;
}

double HVSTMTH::degToRad(double degrees)
{
	double radians;

	radians = (degrees * PI)/180;
	return radians;
}

std::string HVSTMTH::stringify(double val)
{
	std::ostringstream o;
	if (!(o << val))
		throw "Cannot convert to string\n";
	return o.str();
}

std::string HVSTMTH::degToRadPi(double degrees)
{
	std::string radians, temp("p/180");
	
	radians = stringify(degrees);
	radians += temp;
	return radians;
}
	 

double HVSTMTH::raiseTo(double base, double power)
{
	double newBase = base;
	int count = 2;

	while (count <= power)
	{
		newBase *= base;
		count++;
	}

	return newBase;
}



double HVSTMTH::radToDeg(std::string radians)
{

	double temp;
	std::string tempString;
	int length;
	const char * thisString;

	length = radians.length() - 5; //get the length of the top term without pi
	thisString = new char[length];
	tempString = radians.substr(0, length);
	thisString = tempString.c_str();
	temp = atof(thisString);
	return temp;
}

std::string HVSTMTH::radToRadPi(double radians)
{
	std::string radPi, temp("p/180");
	
	radPi = stringify(radians);
	radPi += temp;
	return radPi;
}

double HVSTMTH::parseRad(std::string radians)
{
	return radToDeg(radians);
}

double HVSTMTH::distance(double x1, double y1, double x2, double y2)
{
	double dist;

	dist = raiseTo((x2 - x1),2) + raiseTo((y2 - y1),2);
	return sqrt(dist);
}

double HVSTMTH::distance(double* coord1, double* coord2)
{
	double dist;

	dist = raiseTo((coord2[0] - coord1[0]),2) + raiseTo((coord2[1] - coord1[1]),2);
	return sqrt(dist);
}

double HVSTMTH::slope(double x1, double y1, double x2, double y2)
{
	double m;

	m = (y2 - y1)/(x2 - x1);
	return m;
}

double HVSTMTH::slope(double* coord1, double* coord2)
{
	double m;

	m = (coord2[1] - coord1[1])/(coord2[0] - coord1[0]);
	return m;
}

double* HVSTMTH::midPnt(double* coord1, double* coord2)
{
	double midPoint[2];

	midPoint[0] = (coord1[0] + coord2[0])/2;
	midPoint[1] = (coord1[1] + coord2[1])/2;
	return midPoint;
}

int HVSTMTH::randomNum(int min, int max)
{
	int result = 0;
	int range = (max - min) + 1;

	for (int i = 0; i < range; i++)
	{
		result = min+int(range*rand()/(RAND_MAX)); 
	}
	return result;

}

HVSTMTH::circle::circle(float x, float y, float radius)
: HVSTMTH::shape(x,y)
{
	this->radius = radius;
}

float HVSTMTH::circle::area()
{
	return (PI*radius*radius);
}

bool HVSTMTH::circle::contains(float x, float y)
{
	float angle;
	float x1, y1;
	float x2, y2;
	//calculate the angle 
	angle =  (y - this->yCenter)/(x - this->xCenter);

	//calculate the points of intersection
	x1 = cos(angle)*radius;
	x2 = cos(-angle)*radius;

	y1 = sin(angle)*radius;
	y2 = sin(-angle)*radius;

	//if x and y are within the circle, then there is a collision
	if (x > x1 || x < x2)
		return false;

	if (y > y1 || y < y2)
		return false;

	return true;
}

HVSTMTH::rectangle::rectangle(float x, float y, float width, float height)
: HVSTMTH::shape((x + width)/2.0, (y - height)/2.0)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	x2 = x + width;
	y2 = y - width;
}

float HVSTMTH::rectangle::area()
{
	return (width*height);
}

bool HVSTMTH::rectangle::contains(HVSTMTH::rectangle rect)
{
	if (contains(rect.x,rect.y))
		return true;
	else if(contains(rect.x2,rect.y))
		return true;
	else if(contains(rect.x2, rect.y2))
		return true;
	else if(contains(rect.x, rect.y2));
		return true;

	return false;
}

bool HVSTMTH::rectangle::contains(float x, float y)
{
	//use the SAT to determine if the points are within the boundaries
	if (x < this->x || x > this->x2)
		return false;

	if (y > this->y || y < this->y2)
		return false;

	return true;
}


	