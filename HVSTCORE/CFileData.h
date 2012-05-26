#ifndef _CFILEDATA_H_
#define _CFILEDATA_H_

#include <iostream>
#include <sstream>

enum FILETYPES
{
	MAP = 0,
	SPRITE,
	TILESET,
	MUSIC,
	SFX
};

class CFileData
{
public:
	CFileData(std::string fileName, FILETYPES type, unsigned char * data, __int64 fileSize, __int64 filePos );
	~CFileData();

	unsigned char * getData();
	std::string getDataRange(__int64 startPos, __int64 length);
	FILETYPES getType();
	std::string getName();
	__int64 getSize();
	__int64 getPos();
	
	__int32 toInt(__int64 start);
	__int64 toLong(__int64 start);
	double toDouble(__int64 start);
	unsigned short int toUShort(__int64 start);


private:
	unsigned char * _data;
	FILETYPES _type;
	std::string _fileName;
	__int64 _fileSize;
	__int64 _filePos;

};

#endif