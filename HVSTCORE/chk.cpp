#include "Chk.h"

void CBaseCHK::insertHMD(CBaseHMD HMD)
{
	mapList.insert(mapList.end(), HMD);
}

CBaseHMD CHKFunc::swapChunk(int chunkID, CBaseCHK CHK)
{
	return CHK.getHMD(chunkID);
}