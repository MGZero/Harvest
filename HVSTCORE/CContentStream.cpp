#include "CContentStream.h"

CContentStream::CContentStream(FILE * stream) :
_HMD_VERSION(3.0)
{
	int intGarbage = 0;
	std::string stringReader = "";

	fread(&intGarbage, sizeof(intGarbage),1,stream);
	fread(&stringReader, intGarbage, 1, stream);

	//parse the string
	stringReader = stringReader.substr(4, stringReader.length() - 4);
	_GAMEID = atof(stringReader.c_str());

	fread(&intGarbage, sizeof(intGarbage), 1, stream);
	fread(&stringReader, intGarbage, 1, stream);
	_tileRes = stringReader;

	fread(&intGarbage, sizeof(intGarbage), 1, stream);
	fread(&stringReader, intGarbage, 1, stream);
	_bgmRes = stringReader;
	
}

CContentStream::CContentStream(__int64 & position, CFileData * data) :
_HMD_VERSION(3.0)
{
	int intGarbage = 0;
	std::string stringReader = "";

	//GameID
	intGarbage = data->toInt(position);
	position += 4;
	stringReader = data->getDataRange(position, intGarbage);
	position += intGarbage;

	stringReader = stringReader.substr(4, stringReader.length() - 4);
	_GAMEID = atof(stringReader.c_str());

	//tileSet resource
	intGarbage = data->toInt(position);
	position += 4;
	stringReader = data->getDataRange(position, intGarbage);
	position += intGarbage;
	_tileRes = stringReader;

	//bgm resource
	intGarbage = data->toInt(position);
	position += 4;
	stringReader = data->getDataRange(position, intGarbage);
	position += intGarbage;
	_bgmRes = stringReader;
}

CContentStream::~CContentStream()
{

}


double CContentStream::getHMDVersion()
{
	return _HMD_VERSION;
}

double CContentStream::getGameID()
{
	return _GAMEID;
}

std::string CContentStream::getTileResource()
{
	return _tileRes;
}

std::string CContentStream::getBGMResource()
{
	return _bgmRes;
}