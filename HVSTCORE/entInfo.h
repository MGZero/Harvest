#ifndef _ENTINFO_H_
#define _ENTINFO_H_

#include "linkedlist.h"
#include "CBaseSound.h"
#include "CBasePlayer.h"
#include "CBaseWater.h"
#include "CBaseBush.h"		
#include "dictionary.h"
	


//remove class
class CEntClassCreation
{
public:
	CEntClassCreation(int ID, std::string entName, std::string className);
	int getSize();
	int getID();
	std::string getEntName();
	std::string getClassName();
private:
	int ID;
	std::string entName;
	std::string className;

};

//references to the HMD
class CEntInfo
{
public:
	CEntInfo(){}
	~CEntInfo(){}
	void addToDictionary(int ID, std::string className);
	std::string entLookUp(int ID);
	int entCount();
private:
	dictionary<int, std::string> entDictionary;
};










#endif