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
     in a product, an acknowledgment in the product documentation is required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  -----------------------------------------------------------------------------       

  File:    HVSTDATMAIN.h
  Authors: Steve Calandra
  Notes:   This is the class definition for the database

  -----------------------------------------------------------------------------       

   August 08
	
	  File Created.

*********************************************************************************/

#ifndef _HVSTDATMAIN_H_
#define _HVSTDATMAIN_H_
#include <iostream>


template <typename T>
class HVSTDAT
{

private:
	
	//HVSTDAT(const HVSTDAT&) {}//cant use the copy constructor
	//HVSTDAT& operator=(const HVSTDAT&) {}//cant use assignment operator
	T *tempData; //temporary data
	T *mainData; //main data
	int dataCount; //how many files are in this database
	const char * testname;

public:
	HVSTDAT(){};
	HVSTDAT(T data, const char * name)
	{
		mainData = new T[1];
		dataCount = 1;
		mainData[0] = data;
		testname = name;
	}

	~HVSTDAT(){delete mainData;}
	
	//modify these to work with your program
	void truncate()
	{
	
		dataCount = 0;
		delete mainData; //get rid of the main data
		mainData = new T[0]; //recreate it
	}
	void copy(HVSTDAT<T> &copyTo);


	void addData(T data)
	{
		tempData = new T[dataCount]; //set up the temp holder

		//load into the temp holder
		for (int i = 0; i < dataCount; i++)
		{
			tempData[i] = mainData[i];
		}

		dataCount++; //increment data count

		delete mainData; //clear out the main data
		mainData = new T[dataCount]; //recreate it with an extra space

		//reload the main data
		for (int i = 0; i < dataCount - 1; i++)
		{
			mainData[i] = tempData[i];
		}

		mainData[dataCount - 1] = data; //put in the new data
		delete tempData; //get rid of the temp data
	}

	void removeData(int pos)
	{

		try
		{
			if (pos >= dataCount || pos < 0)
				throw "This data doesn't exist!";

	
			mainData[pos] = mainData[--dataCount]; //move the last piece of data to the place where the removed data is and update the count
	

			tempData = new T[dataCount]; //make a temp holder

			//load into the temp holder
			for (int i = 0; i < dataCount; i++)
			{
				tempData[i] = mainData[i];
			}

			delete mainData; //get rid of the main data
			mainData = new T[dataCount]; //redeclare it with the new size

			//load the main data back up
			for (int i = 0; i < dataCount; i++)
			{
				mainData[i] = tempData[i];
			}
	
			delete tempData; //get rid of the temp data
		}

		catch( const char * error )
		{
			std::cout << error << "\n"; //modify this catch statement for your program
		}
	}

	inline T getData(int pos)
    {
		try
		{
			if (pos >= dataCount || pos < 0)
				throw "This data doesn't exist!";

			return mainData[pos]; //return the data at position pos
		}
	
		catch(const char * error)
		{
			std::cout << error <<"\n"; //modify this for your program
		}
	}

	inline int getBounds()
	{
		return dataCount; //return the number of "holders" in the database
	}

	void listData();
	void sort();
	void split(int start, HVSTDAT<T>& first, HVSTDAT<T>& second);
	void save(const char * file);

	//operators
    void operator += (HVSTDAT<T>& firstVal); 


};

#endif
