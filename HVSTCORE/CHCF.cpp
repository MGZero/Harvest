#include "HCF.h"


CHCF::CHCF(std::string fileName)
: PAKID("HVST84838672")
{
	_fileHandle = fopen(fileName.c_str(), "rb");
	std::string strGarbage = "";
	unsigned int intGarbage = 0;
	unsigned long longGarbage = 0;
	unsigned char * data = 0;
	char charGarbage = '0';

	if (!_fileHandle)
		return;

	for (int i = 0; i < 12; i++)
	{
		fread(&charGarbage, 1, 1, _fileHandle);
		strGarbage += charGarbage;
	}


	if (strGarbage != PAKID)
	{
		fclose(_fileHandle);
		throw "Incorrect archive format";
	}
	strGarbage = "";

	fread(&_gameID, sizeof(_gameID),1,_fileHandle);
	fread(&_fileCount, sizeof(_fileCount),1,_fileHandle);
	
}

CFileData * CHCF::getNext()
{
	if (!_fileHandle)
		throw "Invalid HCF Access";

	__int64 longGarbage = 0;
	__int32 intGarbage = 0;
	std::string strGarbage = "";
	char charGarbage = '0';
	unsigned char * data = 0;

	std::string fileName = "";
	__int64 fileOffset = 0;
	__int64 fileSize = 0;
	__int32 fileType = 0;

	fread(&fileOffset, 8,1,_fileHandle); //file offset

	fread(&intGarbage, 4, 1, _fileHandle);//fileName
		
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1, 1, _fileHandle);
		fileName += charGarbage;
	}

	fread(&fileSize, 8, 1, _fileHandle); //fileSize
		
	fread(&fileType, 4, 1, _fileHandle); //fileType
	std::string tempStr = "";
	char tempC = 0;
	data = new unsigned char[fileSize];
	for (__int64 i = 0; i < fileSize; i++)
	{
		
		fread(&tempC, 1, 1, _fileHandle);
		data[i] = tempC;
		tempStr += tempC;
		
	}
	//fread(data, fileSize, 1, _fileHandle);

	CFileData * temp = new CFileData(fileName, (FILETYPES)fileType, data, fileSize, fileOffset);

	return temp;
	
}


int CHCF::getFileCount()
{
	return _fileCount;
}

int CHCF::getSpriteCount()
{
	return _sprites.count();
}

CHCF::~CHCF()
{
	_maps.clear(true);
	_sprites.clear(true);
	_tiles.clear(true);
	_sfx.clear(true);
	_music.clear(true);

	if (_fileHandle)
		fclose(_fileHandle);
}