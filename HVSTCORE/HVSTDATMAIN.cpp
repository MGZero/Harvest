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
  V1.0 - 10/1/08 First build released containing the standard functions to add and remove files, 
  sort them and truncate the database.

  v1.2 - 10/16/08 Blocked out the assignment operator and copy construcor to prevent shallow copying.
	   - Added error checking for the getData() and removeData() functions

  v2.0 - 11/8/08 Added the split function and an overloaded += operator.
	   - Added a function to write databases to a file			


  -----------------------------------------------------------------------------       

   August 08
	
	  File Created.

*********************************************************************************/
//#include "stdafx.h"
#include "HVSTDATMAIN.h"





//move these damn things




template <typename T> void HVSTDAT<T>::listData()
{
	//list the data
	for (int i = 0; i < dataCount; i++)
	{
		std::cout << i + 1 << ": " << mainData[i] <<"\n";
	}
}

template <typename T> void HVSTDAT<T>::sort()
{
	int outer, inner;
	T temp;

	for (outer = 0; outer < dataCount; outer++)
	{
		for (inner = 1; inner < (dataCount - outer); inner++)
		{
			if (mainData[inner] < mainData[inner - 1])
			{
				temp = mainData[inner - 1];
				mainData[inner - 1] = mainData[inner];
				mainData[inner] = temp;
			}
		}
	}
}

template <typename T> void HVSTDAT<T>::copy(HVSTDAT<T> &copyTo)
{
	delete copyTo.mainData; //remove current data in the new database
	copyTo.dataCount = dataCount;
	copyTo.mainData = new T[dataCount];

	for (int i = 0; i < dataCount; i++)
	{
		copyTo.mainData[i] = mainData[i];
	}
}

template <typename T> void HVSTDAT<T>::operator+= (HVSTDAT<T>& firstVal)
{
	
	int tempCount;
	int j = 0;
	tempCount = firstVal.dataCount + dataCount;

	tempData = new T[dataCount];

	for (int i = 0; i < dataCount; i++)
	{
		tempData[i] = mainData[i];
	}

	delete mainData;
	mainData = new T[tempCount];

	for (int i = 0; i < dataCount + 1; i++)
	{
		mainData[i] = tempData[i];
	}

	delete tempData;

	for (int i = dataCount; i < tempCount; i++, j++)
	{
		mainData[i] = firstVal.mainData[j];
	}

	dataCount = tempCount;
}

template <typename T> void HVSTDAT<T>::split(int start, HVSTDAT<T>& first, HVSTDAT<T>& second)
{
	delete first.mainData;
	delete second.mainData;
	int j = start + 1;
	first.dataCount = start + 1;
	second.dataCount = dataCount - (start +1);

	first.mainData = new T[first.dataCount];
	second.mainData = new T[second.dataCount];

	for (int i = 0; i < first.dataCount; i++)
	{
		first.mainData[i] = mainData[i];
	}

	for (int i = 0; i < second.dataCount; i++, j++)
	{
		second.mainData[i] = mainData[j];
	}
}


