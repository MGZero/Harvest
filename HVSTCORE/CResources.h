#ifndef _CRESOURCES_H_
#define _CRESOURCES_H_

#include "stdio.h"
#include "List.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "CAnimationX.h"
#include "CTileSheetX.h"
#include <unordered_map>
#include "CSFX.h"
#include "HCF.h"
#include "hmd3.0.h"

//using namespace std::tr1;

typedef std::tr1::unordered_map<std::string, CSpriteX*> spriteMap;
typedef std::tr1::unordered_map<std::string, CTileSheetX*> tileMap;
typedef std::tr1::unordered_map<std::string, CSFX*> sfxMap;
typedef std::tr1::unordered_map<std::string, __int64> musicMap;
typedef std::tr1::unordered_map<std::string, CHMD3_0*> hmdMap;

class CResources
{
public:
	~CResources();
	CResources * init();
	void release();

	void addResource(void * resource, std::string type, std::string name);

	//use these
	void addResource(CFileData * fileData);
	List<void *> getResourceList(std::string name);
	void addHCF(std::string fileName);

	sfxMap _sfxData; //NOT TO BE CONFUSED WITH MIDI/OGG - precache
	spriteMap _spriteData; //precache
	tileMap _tileData; //precache

private:
	CResources();
	static CResources * _singleton;

	FILE * _resourceData;
	List<void *> _sprites;
	List<void *> _tileSets;
	List<void *> _music;
	List<void *> _sfx;
	List<void *> _maps;

	musicMap _musicData; //MIDI OR OGG ONLY!!! - do not precache, save position in file
	hmdMap _mapData; //MAPS - PRECACHE DATA ONLY!! HANDLE ENTITY STORAGE AND SHIT ON RUNTIME
	std::stringstream _SStream;

	std::vector<CHCF *> _HCFFiles;
	
};

#endif