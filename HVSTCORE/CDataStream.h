#ifndef _CDATASTREAM_H_
#define _CDATASTREAM_H_

#include "CLayer3_0.h"
#include "CContentStream.h"

class CDataStream
{
public:
	CDataStream(FILE * mapFile);
	CDataStream(CFileData * data); //pass the address of the map.  DO NOT use a pointer in any other way!
	virtual ~CDataStream();

	List<CLayer3_0*> layers;

	double getHMDVersion();
	CContentStream peekContentStream();

private:
	const double _HMD_VERSION;
	unsigned short int _MAP_ID;
	CContentStream * _contentStream;


};


#endif