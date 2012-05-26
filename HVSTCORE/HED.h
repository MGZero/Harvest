#ifndef _HED_H_
#define _HED_H_

#include "CBaseNPC.h"
#include "CBasePlayer.h"
#include "stdio.h"
#include "stdlib.h"
#include "entinfo.h"
#include "CLayer.h"
#include "list.h"
#include <iostream>
#include <fstream>
#include <hash_map>

typedef CBaseTheoryEnt * (*entityInst)();
typedef std::tr1::unordered_map<int, entityInst> entityMap;

struct CBaseHED
{
	std::string fileName;
	CEntInfo entData;
	
};

class CHED
{
public:
	CHED();
	~CHED();

	CBaseTheoryEnt * createEnt(int ID, std::string name, float x, float y, std::vector<std::string> params);

private:
	entityMap _DB;

};


namespace HEDFunc
{
	static CBaseHED list;
	const static CHED DB;
	void populateList(std::string fileName);
	template<class T> CBaseTheoryEnt * instantiator()
	{
		return new T;
	}
};


#endif