#ifndef _CHK_H_
#define _CHK_H_
#include "HMD.h"

class CBaseCHK
{
public:
	CBaseCHK(){}
	~CBaseCHK(){}

	CBaseHMD getHMD(int HMDID){return mapList[HMDID];}
	void insertHMD(CBaseHMD HMD);
private:
	std::vector<CBaseHMD> mapList;

};

namespace CHKFunc
{
	void readCHK(char * fileName, CBaseCHK &CHK);
	CBaseHMD swapChunk(int chunkID, CBaseCHK CHK);
};



#endif