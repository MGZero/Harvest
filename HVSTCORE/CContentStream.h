#ifndef _CCONTENTSTREAM_H_
#define _CCONTENTSTREAM_H_

#include <iostream>
#include "CFileData.h"

class CContentStream
{
public:
	CContentStream(FILE * stream);
	CContentStream(__int64 & position, CFileData * data); //same deal as with dataStream
	virtual ~CContentStream();


	double getHMDVersion();
	double getGameID();
	std::string getTileResource();
	std::string getBGMResource();


private:
	const double _HMD_VERSION;
	
	double _GAMEID;
	std::string _tileRes;
	std::string _bgmRes;



};

#endif