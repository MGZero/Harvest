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
#ifndef _HVSTMTH_H_
#define _HVSTMTH_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 
#include <ctime> 
#include "Math.h"
namespace HVSTMTH
{
	const double PI = 3.14159265358979323846;
	const double PIRAD = 180;
	
	
	double distance(double x1, double y1, double x2, double y2);
	double distance(double * coord1, double * coord2);
	double slope(double x1, double y1, double x2, double y2);
	double slope(double * coord1, double * coord2);
	double* midPnt(double * coord1, double * coord2);
	double raiseTo(double base, double power);
	std::string stringify(double val);
	int randomNum(int min, int max);
	

	//trig stuff

	//to pi radians
	std::string radToRadPi(double radians); //converts radians to radians in terms of pi
	std::string degToRadPi(double degrees); //returns the radians in terms of pi

	//to radians
	double parseRad(std::string radians); //converts radians in terms of pi to decimals
	double degToRad(double degrees);

	//to degrees
	double radToDeg(double radians); //converts radians to degrees
	double radToDeg(std::string radians); //converts radians in terms of pi to degrees
	
class CBaseVector
{
public:
	CBaseVector(float x, float y){X = x; Y = y;}
	CBaseVector(){}
	~CBaseVector(){}
	float magnitude;
	//for the purpose of Sword of Divination, only magnitude x and y will be used. 
	//Magnitude and direction have no purpose in a 2D game like this
	float X;
	float Y;
	float direction; //in degrees

	void calcDirection(); //only use this when x and y are known
	void breakUp(); //use for breaking the magnitude into components
	void normalize();
};

class CBaseScalar
{
public:
	float magnitude;
};

	//shapes
	class shape //abstract
	{
	public:
		virtual bool contains(float x, float y) = 0;
		virtual float area() = 0;

		float xCenter, yCenter; //center point
		float * xFixed, * yFixed; //the point this shape should autosnap to

		void setHotSpot(float * x, float * y){xFixed = x; yFixed = y;}

	protected:
		shape(float x, float y){xCenter = x; yCenter = y;}
		shape(){}
		~shape(){}
	};

	class circle : public shape
	{
	public:
		circle(float x, float y, float radius);
		~circle(){};

		float radius;

		bool contains(float x, float y);
		float area();
	};

	class rectangle : public shape
	{
	public:
		rectangle(float x, float y, float width, float height);
		~rectangle(){};

		float x, y;
		float x2, y2;
		float width, height;

		bool contains(float x, float y);
		bool contains(rectangle rect);
		
		float area();
	};

	//matrices

	class matrix
	{
	public:
		matrix(int height, int width)
		{
			Matrix = new double*[height];

			for (int i = 0; i < height; i++)
				Matrix[i] = new double[width];

			rows = height;
			columns = width;
		}

		matrix(matrix &copy)
		{
			Matrix = new double*[copy.getRows()];

			for (int i = 0; i < copy.getRows(); i++)
				Matrix[i] = new double[copy.getColumns()];

			//populate!!
			for (int i = 0; i < copy.getRows(); i++)
				for (int j = 0; j < copy.getColumns(); j++)
					Matrix[i][j] = copy.getEntry(i,j);
		}

		~matrix()
		{
			for (int i = 0; i < rows; i++)
				delete[] Matrix[i];

			delete[] Matrix;
		}

		void insertEntry(double entry, int I, int J)
		{
			Matrix[I][J] = entry;
		}

		double getEntry(int I, int J){return Matrix[I][J];}

		void resize(int width, int height)
		{
			for (int i = 0; i < rows; i++)
				delete[] Matrix[i];

			delete[] Matrix;

			Matrix = new double*[height];

			for (int i = 0; i < height; i++)
				Matrix[i] = new double[width];

			rows = height;
			columns = width;
		}



		inline int getRows(){return rows;}
		inline int getColumns(){return columns;}

		//operators
		matrix& operator+=(matrix& right)
		{
			if (rows == right.getRows() && columns == right.getColumns())
			{
				for (int i = 0; i < getRows(); i++)
					for (int j = 0; j < getColumns(); j++)
						Matrix[i][j] += right.getEntry(i,j);
			}
			return *this;
		}

		matrix& operator-=(matrix& right)
		{
			if (rows == right.getRows() && columns == right.getColumns())
			{
				for (int i = 0; i < getRows(); i++)
					for (int j = 0; j < getColumns(); j++)
						Matrix[i][j] -= right.getEntry(i,j);
			}
			return *this;
		}

		matrix& operator *= (int scale)
		{
			for (int i = 0; i < getRows(); i++)
					for (int j = 0; j < getColumns(); j++)
						Matrix[i][j] *= scale;
			return *this;
		}

		matrix& operator *= (matrix& right)
		{
			matrix *temp = this;
			if (columns == right.getRows())
			{
				resize(right.getColumns(), rows);

				for (int i = 0; i < rows; i++)
					for (int j = 0; j < columns; j++)
					{
						for (int k = 0; k < right.getRows(); k++)
						{
							for (int l = 0; l < columns; l++)
								Matrix[i][j] = temp->getEntry(i,l) * right.getEntry(l,k);
						}

					}
			}
			return *temp;
		}

	private:
		matrix(){};

		//dont allow direct access to the array
		double ** Matrix;
		int rows, columns;

	};

	//matrix math
	
	
	
};

#endif
	