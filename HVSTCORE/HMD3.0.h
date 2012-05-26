#ifndef _HMD3_0_H_
#define _HMD3_0_H_

#include <iostream>
#include "CDataStream.h"

//HMD 3.0 Class
//contains a copy of the header
class CHMD3_0
{
public:
	CHMD3_0(std::string fileName);
	CHMD3_0(CFileData * data);
	virtual ~CHMD3_0();
	int _MAP_ID;

	void createMap();
	CDataStream * _dataStream;

private:
	
	void _setUpTileCoords();
	CBaseVector _tileCoords[2500];

};


#endif