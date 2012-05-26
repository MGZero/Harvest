#include "CResources.h"

CResources * CResources::_singleton;

CResources::CResources()
{
	int fileCount = 0;

	addHCF("C:\\SoD.HCF");
	fileCount = _HCFFiles[0]->getFileCount();
	
	//start cachin' those resources!!!
	for (int i = 0; i < fileCount; i++)
		addResource(_HCFFiles[0]->getNext());
}

void CResources::addHCF(std::string fileName)
{
	CHCF * temp = new CHCF(fileName);

	_HCFFiles.push_back(temp);
}

CResources::~CResources()
{

	while (!_HCFFiles.empty())
	{
		delete _HCFFiles.back();
		_HCFFiles.pop_back();
	}

	for (int i = 0; i < _sprites.count(); i++)
	{
		delete _sprites[i];
		_sprites[i] = 0;
	}

	_sprites.clear();
}

void CResources::release()
{
	if (_singleton)
		delete _singleton;
	else
		throw "Attempted to delete singleton CResources when not initialized!";
}


CResources * CResources::init()
{
	if (!_singleton)
		_singleton = new CResources();

	return _singleton;
}

void CResources::addResource(CFileData * data)
{
	FILETYPES type = data->getType();
	switch (type)
	{
	case SPRITE:
		{

			CSpriteX * tempSprite = new CSpriteX(data);
			_spriteData.insert(spriteMap::value_type(data->getName(), tempSprite));
			tempSprite = 0;
			delete data;
			data = 0;
		}break;

	case TILESET:
		{
			CTileSheetX * tempSheet = new CTileSheetX(data, 16, 16);
			_tileData.insert(tileMap::value_type(data->getName(), tempSheet));
			delete data;
			tempSheet = 0;
			data = 0;
		}break;

	case SFX:
		{
			CSFX * tempSFX = new CSFX(data);
			_sfxData.insert(sfxMap::value_type(data->getName(), tempSFX));
			delete data;
			data = 0;
			tempSFX = 0;
		}break;

	case MUSIC:
		{
			_musicData.insert(musicMap::value_type(data->getName(), data->getPos()));
		}break;

	case MAP:
		{
			CHMD3_0 * tempHMD = new CHMD3_0(data);
			_mapData.insert(hmdMap::value_type(data->getName(), tempHMD));
			delete data;
			data = 0;
			tempHMD = 0;
		}break;

	default:
		break;
	}
}

void CResources::addResource(void *resource, std::string type, std::string name)
{
	std::string temp = "";
	
	if (type ==  "sprite")
	{
		_sprites.add(resource);
		_SStream << _sprites.count() - 1;
		_SStream >> temp;
		_SStream.clear();
		temp +=  ": " + name + "\n";
		//fwrite((void*)temp.c_str(), temp.length(), 1, _resourceData);
	}
	else if ( type == "music")
	{
		_music.add(resource);
		//_resourceData << _music.count() - 1 << ": " << name << "\n";
	}
	else if ( type == "sfx")
	{
		_sfx.add(resource);
		//_resourceData << _sfx.count() - 1 << ": " << name << "\n";
	}
	else
	{
		throw "Resource type not defined!";
	}
	
}

List<void *> CResources::getResourceList(std::string type)
{
	if (type ==  "sprite")
		return _sprites;
	else if ( type == "music")
		return _music;
	else if ( type == "sfx")
		return _sfx;
	else
		throw "Resource type not defined!";
}