#include "entInfo.h"

CEntClassCreation::CEntClassCreation(int ID, std::string entName, std::string className)
{
	this->ID = ID;
	this->entName = entName;
	this->className = className;
}

int CEntClassCreation::getID()
{
	return ID;
}

std::string CEntClassCreation::getEntName()
{
	return entName;
}

std::string CEntClassCreation::getClassName()
{
	return className;
}

void CEntInfo::addToDictionary(int ID, std::string className)
{
	entDictionary.append(ID, className);
}

std::string CEntInfo::entLookUp(int ID)
{
	return entDictionary[ID];
}

int CEntInfo::entCount()
{
	return entDictionary.count();
}