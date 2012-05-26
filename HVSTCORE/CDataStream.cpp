#include "CDataStream.h"

CDataStream::CDataStream(CFileData *data) :
_HMD_VERSION(3.0)
{
	unsigned short int layerCount = 0;
	unsigned short int tileID = 0;
	unsigned short int entCount = 0;
	unsigned short int intGarbage = 0;
	unsigned short int hbCount = 0;
	std::string stringGarbage = "";
	__int64 position = 20;

	_contentStream = new CContentStream(position, data);

	layerCount = data->toUShort(position);
	position += 2;

	for (int i = 0; i < layerCount; i++)
	{
		layers.add(new CLayer3_0());

		//read in tiles
		for (int tiles = 0; tiles < 2500; tiles++)
		{
			tileID = data->toUShort(position);
			position += 2;
			layers[i]->tiles[tiles] = tileID;
		}

		//read in entities
		entCount = data->toUShort(position);
		position += 2;
		for (int entities = 0; entities < entCount; entities++)
		{
			unsigned short int entID = 0;
			std::string stringData = "", name = "";
			std::vector<std::string> paramList;
			unsigned short int x = 0, y = 0;
			unsigned short int paramCount = 0;

			entID = data->toUShort(position);
			position += 2;

			intGarbage = data->toUShort(position);
			position += 2;
			name = data->getDataRange(position, intGarbage);
			position += intGarbage;

			x = data->toUShort(position);
			position += 2;
			y = data->toUShort(position);
			position += 2;

			//parameter list
			paramCount = data->toUShort(position);
			position += 2;
			for (int i = 0; i < paramCount; i++)
			{
				intGarbage = data->toUShort(position);
				position += 2;
				stringData = data->getDataRange(position, intGarbage);
				position += intGarbage;
				paramList.push_back(stringData);
			}

			layers[i]->addEntity(entID, name, x, y, paramList);
		}

		//read in hitboxes
		hbCount = data->toUShort(position);
		position += 2;
		for (int i = 0; i < hbCount; i++)
		{
			unsigned short int x = 0, y = 0, width = 0, height = 0;

			x = data->toUShort(position);
			position += 2;
			y = data->toUShort(position);
			position += 2;
			width = data->toUShort(position);
			position += 2;
			height = data->toUShort(position);
			position += 2;

			layers[i]->hitboxes.push_back(new HVSTMTH::rectangle(x, y, width, height));
		}
	}
}

CDataStream::CDataStream(FILE * mapFile) :
_HMD_VERSION(3.0)
{
	unsigned short int layerCount = 0;
	unsigned short int tileID = 0;
	unsigned short int entCount = 0;
	unsigned short int intGarbage = 0;
	unsigned short int hbCount = 0;
	std::string stringGarbage = "";

	_contentStream = new CContentStream(mapFile);

	fread(&layerCount, 2, 1, mapFile);
	
	for (int i = 0; i < layerCount; i++)
	{
		layers.add(new CLayer3_0());

		//read in tiles
		for (int tiles = 0; tiles < 2500; tiles++)
		{
			fread(&tileID, 2, 1, mapFile);
			layers[i]->tiles[tiles] = tileID;
		}

		//read in entities
		fread(&entCount, 2, 1, mapFile);
		for (int entities = 0; entities < entCount; entities++)
		{
			unsigned short int entID = 0;
			std::string stringData = "", name = "";
			std::vector<std::string> paramList;
			unsigned short int x = 0, y = 0;
			unsigned short int paramCount = 0;

			fread(&entID, 2, 1, mapFile);

			fread(&intGarbage, 2, 1, mapFile);
			fread(&name, intGarbage, 1, mapFile);

			fread(&x, 2, 1, mapFile);
			fread(&y, 2, 1, mapFile);

			//parameter list
			fread(&paramCount, 2, 1, mapFile);
			for (int i = 0; i < paramCount; i++)
			{
				fread(&intGarbage, 2, 1, mapFile);
				fread(&stringData, intGarbage, 1, mapFile);
				paramList.push_back(stringData);
			}

			layers[i]->addEntity(entID, name, x, y, paramList);
		}

		//read in hitboxes
		fread(&hbCount, 2, 1, mapFile);
		for (int i = 0; i < hbCount; i++)
		{
			unsigned short int x = 0, y = 0, width = 0, height = 0;

			fread(&x, 2, 1, mapFile);
			fread(&y, 2, 1, mapFile);
			fread(&width, 2, 1, mapFile);
			fread(&height, 2, 1, mapFile);

			layers[0]->hitboxes.push_back(new HVSTMTH::rectangle(x, y, width, height));
		}
	}

	unsigned short int nodeCount = 0;
	unsigned short int xNode = 0, yNode = 0, layerNum = 0;

	
}

CDataStream::~CDataStream()
{

	for (int i = 0; i < layers.count(); i++)
	{
		layers.cleanNode(i);
	}
	layers.clear();
	delete _contentStream;
}

double CDataStream::getHMDVersion()
{
	return _HMD_VERSION;
}

CContentStream CDataStream::peekContentStream()
{
	return *_contentStream;
}