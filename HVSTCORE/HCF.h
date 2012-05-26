#ifndef _HCF_H_
#define _HCF_H_
#include <iostream>
#include <vector>
#include "CFileData.h"
#include "Dictionary.h"

class CHCF
{
public:
	
	CHCF(std::string fileName);
	~CHCF();

	const std::string PAKID;
		
	int getGameID();
	int getSpriteCount();
	int getFileCount();
	CFileData * getNext(); //retrieves the next file
	CFileData * getFromPos(__int64 position); //get a resource at a specific position in the file

private:
	int _gameID;
	dictionary<std::string, CFileData*> _maps;
	dictionary<std::string, CFileData*> _sprites;
	dictionary<std::string, CFileData*> _tiles;
	dictionary<std::string, CFileData*> _sfx;
	dictionary<std::string, CFileData*> _music;
	FILE * _fileHandle;

	//this is the more recent stuff.  The above isn't going to properly make use of this system.
	std::vector<void*> _mapsVec;
	int _fileCount;

	
};


#endif